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

void Form::showPix(QImage image1,QImage image2)
{

    map1_=QPixmap::fromImage(image1).scaled(ui->label_3->size(),Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);
    map2_= QPixmap::fromImage(image2).scaled(ui->label_4->size(),Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);
    ui->label_3->setPixmap(map1_);
    ui->label_4->setPixmap(map2_);
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


void Form::on_pushButton_3_clicked()
{
    ui->label_3->setPixmap(QPixmap(""));
    ui->label_4->setPixmap(QPixmap(""));

    emit stop_();
}

