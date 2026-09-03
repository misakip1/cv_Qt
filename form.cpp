#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowFlag(Qt::WindowTitleHint);
}

Form::~Form()
{

    qDebug()<<"被删除";
    delete ui;
}

void Form::showPix(CameraTask task)
{
    map1_=QPixmap::fromImage(task.frame.image);
   // map2_=QPixmap::fromImage(task.result.image);
   QPixmap map11_= map1_.scaled(ui->label_3->size(),Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);
  // map2_= map2_.scaled(ui->label_4->size(),Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);
    ui->label_3->setPixmap(map11_);
    ui->label_4->setPixmap(map11_);
}

void Form::on_pushButton_2_clicked()
{
    emit stop_();
}


void Form::on_pushButton_clicked()
{
    qDebug()<<"点击检测";
    qDebug() << "[emit start]"<< "form =" << this;
    emit start_();
}

