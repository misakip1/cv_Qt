#include "regfrom.h"
#include "ui_regfrom.h"
#include<QRegularExpression>
#include"httpserver.h"
RegFrom::RegFrom(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RegFrom)
{
    ui->setupUi(this);
}

RegFrom::~RegFrom()
{
    delete ui;
}

void RegFrom::on_pushButton_3_clicked()
{
    emit switchLog();
}


void RegFrom::on_pushButton_2_clicked()
{
    if(!reg())
    {
        return;
    }//http请求
    QJsonObject obj;
    obj["账号"] = ui->lineEdit->text();
    obj["用户名"] = ui->lineEdit_2->text();
    obj["密码"] = ui->lineEdit_3->text();
    obj["机器名"] = ui->lineEdit_5->text();
    obj["机器码"] = ui->lineEdit_6->text();
    //obj["验证码"] = ui->lineEdit_7->text();
    connect(&HttpServer::getInstance(),&HttpServer::reg_finsh_http,this,&RegFrom::http_finsh);
    QUrl url(path+"Reg");
    HttpServer::getInstance().post(url,obj,Moudel::RegModel);

}
void RegFrom::http_finsh(Moudel id,QString res,ErrorCodes error)
{
    qDebug()<<res;
    if(res!="Registration successful!\r\n"||error!=ErrorCodes::SUCCESS)
    {
        ui->label_8->setText("解析错误");
        return;
    }
    ui->label_8->setText("注册成功");
}
bool RegFrom::reg()
{
    QString account = ui->lineEdit->text().trimmed();
    QString username = ui->lineEdit_2->text().trimmed();
    QString pwd = ui->lineEdit_3->text().trimmed();
    QString pwdConfirm = ui->lineEdit_4->text().trimmed();
    QString machineId = ui->lineEdit_5->text().trimmed();
    QString machineName = ui->lineEdit_6->text().trimmed();
    QString code = ui->lineEdit_7->text().trimmed();

    ui->label_8->setStyleSheet("color:red;");
    ui->label_8->setText("");

    // ========== 1.非空校验 ==========
    if(account.isEmpty())
    {
        ui->label_8->setText("错误：账号不能为空");
        ui->lineEdit->setFocus();
        return false;
    }
    if(username.isEmpty())
    {
        ui->label_8->setText("错误：用户名不能为空");
        ui->lineEdit_2->setFocus();
        return false;
    }
    if(pwd.isEmpty())
    {
        ui->label_8->setText("错误：密码不能为空");
        ui->lineEdit_3->setFocus();
        return false;
    }
    if(pwdConfirm.isEmpty())
    {
        ui->label_8->setText("错误：请填写验证密码");
        ui->lineEdit_4->setFocus();
        return false;
    }
    if(machineId.isEmpty())
    {
        ui->label_8->setText("错误：机器编号不能为空");
        ui->lineEdit_5->setFocus();
        return false;
    }
    if(machineName.isEmpty())
    {
        ui->label_8->setText("错误：机器名不能为空");
        ui->lineEdit_6->setFocus();
        return false;
    }
    if(code.isEmpty())
    {
        ui->label_8->setText("错误：验证码不能为空");
        ui->lineEdit_7->setFocus();
        return false;
    }

    // ========== 2.密码一致性校验 ==========
    if(pwd != pwdConfirm)
    {
        ui->label_8->setText("错误：两次输入密码不一致");
        ui->lineEdit_4->setFocus();
        return false;
    }

    // ========== 3.密码复杂度（可按需修改） ==========
    // 示例：密码至少6位
    if(pwd.size() < 6)
    {
        ui->label_8->setText("错误：密码长度不能少于6位");
        ui->lineEdit_3->setFocus();
        return false;
    }

    // ========== 4.账号正则（仅字母数字下划线，8~20位）可按需关闭 ==========
    QRegularExpression regAccount("^[a-zA-Z0-9_]{8,20}$");
    if(!regAccount.match(account).hasMatch())
    {
        ui->label_8->setText("错误：账号只能字母数字下划线，长度8~20");
        ui->lineEdit->setFocus();
        return false;
    }

    // ========== 5.机器编号正则（举例：纯数字） ==========
    QRegularExpression regMachineId("^[0-9]+$");
    if(!regMachineId.match(machineId).hasMatch())
    {
        ui->label_8->setText("错误：机器编号只能为数字");
        ui->lineEdit_5->setFocus();
        return false;
    }

    // ========== 全部校验通过 ==========
    ui->label_8->setStyleSheet("color:green;");
    ui->label_8->setText("校验通过，可以提交注册");
    return true;
}

