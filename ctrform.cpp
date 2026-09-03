#include "ctrform.h"
#include"titelicon.h"
#include "ui_ctrform.h"
#include<QPixmap>
#include <QCameraDevice>
#include <QMediaDevices>

CtrForm::CtrForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CtrForm)
{
    ui->setupUi(this);
    mannger_=new CameraManager;
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
        mannger_->addWorker(s);
        Form*form=new Form(this);
        form->setAttribute(Qt::WA_StyledBackground, true);
        QMdiSubWindow*sub_form_=ui->mdiArea->addSubWindow(form);
        connect(mannger_->camaer_thread_[s].processor_,&CameraProcessor::cv_finsh,form,&Form::showPix);
        connect(sub_form_, &QMdiSubWindow::destroyed, this, [=](){
         mannger_->removeWorker(s);
            mapper_.remove(s);
            emit closeSub(s);
            qDebug() << "子窗口关闭，key=" << s;
        });
        mapper_[s]=sub_form_;

        form->show();

        ui->mdiArea->tileSubWindows();

    }
    else
    {
        if(!mapper_[s])
        {
            return;
        }
        mannger_->removeWorker(s);
        QMdiSubWindow*sub_mdi=mapper_[s];
        mapper_.remove(s);
        sub_mdi->close();
        qDebug()<<"1234565";
        ui->mdiArea->tileSubWindows();
    }
}
