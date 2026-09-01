#include "forgetfrom.h"
#include "ui_forgetfrom.h"
#include"httpserver.h"
#include<QMessageBox>
ForgetFrom::ForgetFrom(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ForgetFrom)
{
    ui->setupUi(this);
}

ForgetFrom::~ForgetFrom()
{
    delete ui;
}

void ForgetFrom::http_finsh(Moudel id, QString res, ErrorCodes error)
{
    if(res.isEmpty()||error!=ErrorCodes::SUCCESS)
    {QMessageBox::warning(this,"错误","网络错误");
        return;
    }
    QMessageBox::warning(this,"成功","注册成功");
}

void ForgetFrom::on_pushButton_clicked()
{
    emit switchLog();
}


void ForgetFrom::on_pushButton_2_clicked()
{
    QJsonObject obj;
    obj["账号"]=ui->lineEdit->text();
    obj["密码"]=ui->lineEdit_2->text();
    obj["验证码"]=ui->lineEdit_4->text();
    connect(&HttpServer::getInstance(),&HttpServer::forget_finsh_http,this,&ForgetFrom::http_finsh);
    QUrl url(path+"Forget");
    HttpServer::getInstance().post(url,obj,Moudel::ForgetModel);
}

