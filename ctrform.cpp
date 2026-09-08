#include "ctrform.h"
#include"titelicon.h"
#include "ui_ctrform.h"
#include<QPixmap>
#include <QCameraDevice>
#include <QMediaDevices>
#include"sqlmanager.h"
CtrForm::CtrForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CtrForm)
{
    ui->setupUi(this);
    mannger_=new CameraManager();
    connect(ui->titwid,&TitelIcon::SwitchAcount,this,&CtrForm::SwitchAcount);
    QList<QCameraDevice> cameraList = QMediaDevices::videoInputs();
    QStringList s;
    for(auto&i:cameraList)
    {
        s<<i.description();
    }
    ui->comboBox->addItems(s);
    // 粉紫色 #E2C5E2
    ui->mdiArea->setBackground(QBrush(QColor("#E2C5E2")));

    connect(ui->comboBox,&MultiSelectComboBox::invokeMdi,this,&CtrForm::createMdi);
    connect(this,&CtrForm::closeSub,ui->comboBox,&MultiSelectComboBox::NoselectItem);
    connect(ui->titwid,&TitelIcon::SwitchAcount,this,&CtrForm::SwitchAcount);

    db.setDatabaseName("E:\\sqlitDb\\my.db");
    db.open();
    model=new QSqlQueryModel(this);
    QTimer *time_=new QTimer(this);
    time_->setInterval(1000);
    time_->setTimerType(Qt::PreciseTimer);
    // 隐藏左侧行号表头
    ui->tableView->verticalHeader()->setVisible(false);
    flashTabelView();
    time_->start();
    connect(time_,&QTimer::timeout,this,&CtrForm::flashTabelView);

}

CtrForm::~CtrForm()
{
    for (auto it = mapper_.begin(); it != mapper_.end(); ++it) {
        QMdiSubWindow* sub = it.value();
        if (sub) {
            sub->disconnect(this); // 切断该子窗口和当前对象的所有信号槽
        }
    }
    mapper_.clear(); // 清空映射，避免后续野访问
    delete mannger_;
    delete ui;
}

void CtrForm::createMdi(QString s, bool ok)
{

    if(ok)
    {
        Singleton<SQLManager>::getInstance();
        mannger_->addWorker(s);
        Form*form=new Form(this);
        form->setAttribute(Qt::WA_StyledBackground, true);
        QMdiSubWindow*sub_form_=ui->mdiArea->addSubWindow(form);
        connect(form,&Form::cvMgr_config,mannger_->camaer_thread_[s].cvMgr_,&cvMgr::setConfig);
        connect(mannger_->camaer_thread_[s].processor_,&CameraProcessor::cv_finsh,form,&Form::showPix);
        connect(form,&Form::stop_,mannger_->camaer_thread_[s].worker,&CameraWorker::stop,Qt::QueuedConnection);
        connect(mannger_->camaer_thread_[s].processor_,&CameraProcessor::sendFps,form,&Form::setFps);
        auto conn=connect(form,&Form::start_,mannger_->camaer_thread_[s].worker,&CameraWorker::start,Qt::QueuedConnection);
        connect(sub_form_, &QMdiSubWindow::destroyed, this, [=](){
        // mannger_->removeWorker(s);
            mapper_.remove(s);
         qDebug()<<"结束ctr"<<mapper_.size();
            emit closeSub(s);
            qDebug() << "子窗口关闭，key=" << s;
        });
        mapper_[s]=sub_form_;
          qDebug()<<"开启ctr"<<mapper_.size();
        form->show();
        ui->mdiArea->tileSubWindows();



    }
    else
    {
        if(!mapper_[s])
        {
            return;
        }
       // mannger_->removeWorker(s);
        QMdiSubWindow*sub_mdi=mapper_[s];
        mapper_.remove(s);
        sub_mdi->close();
        qDebug()<<"1234565";
        ui->mdiArea->tileSubWindows();
    }
}

void CtrForm::flashTabelView()
{
    model->setQuery("SELECT rec.id,rec.username,rec.machine_no,rec.original_image_path,rec.processed_image_path,rec.detect_time,res.is_ng,res.defect_type,res.detect_message from inspection_result as res JOIN inspection_record as rec where res.inspection_id=rec.id;");

    if (model->lastError().isValid())
    {
        qDebug() << "SQL错误：" << model->lastError().text();
        return;
    }

    model->setHeaderData(0, Qt::Horizontal, tr("编号"));
    model->setHeaderData(1, Qt::Horizontal, tr("用户"));
    model->setHeaderData(2, Qt::Horizontal, tr("机器号"));
    model->setHeaderData(3, Qt::Horizontal, tr("原图"));
    model->setHeaderData(4, Qt::Horizontal, tr("检测图"));
    model->setHeaderData(5, Qt::Horizontal, tr("检测时间"));
    model->setHeaderData(6, Qt::Horizontal, tr("Ng"));
    model->setHeaderData(7, Qt::Horizontal, tr("缺陷类型"));
    model->setHeaderData(8, Qt::Horizontal, tr("检测描述"));
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setStretchLastSection(true); // 最后一列自动拉伸
    ui->tableView->resizeColumnsToContents(); // 列宽自适应内容
}





void CtrForm::on_tableView_doubleClicked(const QModelIndex &index)
{
    if(index.column()==3||index.column()!=4)
    {
    // 获取地址文本
     address_ =model->record(index.row()).value("address").toString();
    QPixmap map1=QPixmap(address_).scaled(ui->label_3->size());
    ui->label_3->setPixmap(map1);
    }

}


void CtrForm::on_pushButton_clicked()
{
    QPixmap map=ui->label_3->pixmap();
    QImage image=map.toImage();
    bool ok=image.save(address_,"jpg",80);
    if(!ok)
    {
        qDebug()<<"复检图片保存失败";
        return;
    }
    ui->label_3->setPixmap(QPixmap(""));

}


void CtrForm::on_pushButton_2_clicked()
{
    qDebug()<<"取消保存还原图片";
     ui->label_3->setPixmap(QPixmap(address_));
}

