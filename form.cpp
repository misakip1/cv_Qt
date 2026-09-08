#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowFlag(Qt::WindowTitleHint);
    config_form_=new AlgorithmDialog(this);
    connect(config_form_,&AlgorithmDialog::configMsg,this,&Form::setConfig);
    config_=std::make_shared<AlgorithmConfig>();

}

Form::~Form()
{

    qDebug()<<"被删除";
    delete ui;
}
void Form::setConfig(std::shared_ptr<AlgorithmConfig> msg)
{
    config_=msg;
    emit cvMgr_config(msg);
}

void Form::setFps(double fps)
{
    ui->label_6->setText(QString("帧率%1").arg(fps));
}
void Form::showPix(std::shared_ptr<CameraTask> task)
{
    {
        std::lock_guard<std::mutex> lk_(mtx_);
        qint64 imageCode=task->imageCode.toLongLong();
        if(imageCode>imagecode_)
        {
            imagecode_=imageCode;
        }
        else
        {
            return;
        }
        map1_=QPixmap::fromImage(task->image1_).scaled(ui->label_3->size(),Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);
        map2_= QPixmap::fromImage(task->image2_).scaled(ui->label_4->size(),Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);
        ui->label_3->setPixmap(map1_);
        ui->label_4->setPixmap(map2_);
    }
}

bool Form::checkConfig()
{
    if (config_->deformation        ||
        config_->broken             ||
        config_->scuff              ||
        config_->whitePoint         ||
        config_->colorDifference    ||
        config_->grindingMark       ||
        config_->primerReturn       ||
        config_->exposedBase        ||
        config_->hangerMark         ||
        config_->dent               ||
        config_->scratch            ||
        config_->crater             ||
        config_->orangePeel         ||
        config_->aluminumChip       ||
        config_->sprayFlow          ||
        config_->bubble             ||
        config_->pit                ||
        config_->coarseTexture      ||
        config_->coatingCrack       ||
        config_->dirt               ||
        config_->adhesion           ||
        config_->powderBump         ||
        config_->coatingScratch     ||
        config_->pushDamage         ||
        config_->oil)
    {
        qDebug()<<"记录的有信息";
        return true;
    }
    // 全部false
    return false;
}

void Form::on_pushButton_2_clicked()
{
    emit stop_();
}


void Form::on_pushButton_clicked()
{
    qDebug()<<"点击检测";
    qDebug() << "[emit start]"<< "form =" << this;
    bool ok=checkConfig();
    if(!ok)
    {
        QMessageBox::warning(this,"错误","请至少选择一种检测方案");
        return;
    }
    emit start_();
}


void Form::on_pushButton_3_clicked()
{
    ui->label_3->setPixmap(QPixmap(""));
    ui->label_4->setPixmap(QPixmap(""));

    emit stop_();
}


void Form::on_pushButton_4_clicked()
{

    config_form_->exec();

}

