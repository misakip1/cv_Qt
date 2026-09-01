#include "loding.h"
#include "ui_loding.h"
#include<QPixmap>
#include<QRegularExpression>
#include<QJsonObject>
#include"httpserver.h"
#include"const.h"
Loding::Loding(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Loding)
{
    ui->setupUi(this);
    QPixmap map("E:\\icon\\主题素材\\壁纸.jpg");
    ui->icon->setScaledContents(true);
    ui->icon->setPixmap(map);
    ui->line_acount->setClearButtonEnabled(true);
    ui->line_mach->setClearButtonEnabled(true);
    ui->line_pwd->setClearButtonEnabled(true);
    ui->line_acount->setPlaceholderText("请输入账号");
    ui->line_pwd->setPlaceholderText("请输入密码");
    ui->line_mach->setPlaceholderText("请输入机器号");
}

Loding::~Loding()
{
    delete ui;
}

void Loding::on_pushButton_clicked()
{
    if(!log())
        return;
    //http请求
    QJsonObject obj;
    obj["账号"]=ui->line_acount->text();
    obj["密码"]=ui->line_pwd->text();
    obj["机器号"]=ui->line_mach->text();
    QUrl url(path+"loding");
    connect(&HttpServer::getInstance(),&HttpServer::lod_finsh_http,this,&Loding::http_finsh);
    HttpServer::getInstance().post(url,obj,Moudel::LodingModel);


}


void Loding::on_pushButton_2_clicked()
{
    emit switchGet();
}


void Loding::on_pushButton_3_clicked()
{
    emit switchReg();
}

bool Loding::log()
{
    QString account = ui->line_acount->text().trimmed();
    QString pwd = ui->line_pwd->text().trimmed();
    QString machineId = ui->line_mach->text().trimmed();
     ui->tip->setStyleSheet("color:red;");

    // ===== 1.非空校验 =====
    if(account.isEmpty())
    {
        ui->tip->setText( tr("账号不能为空！"));

        ui->line_acount->setFocus();
        return false;
    }
    if(pwd.isEmpty())
    {
         ui->tip->setText( tr("密码不能为空！"));
        ui->line_pwd->setFocus();
        return false;
    }
    if(machineId.isEmpty())
    {
        ui->tip->setText( tr("机器号不能为空！"));
        ui->line_mach->setFocus();
        return false;
    }

    // ===== 2.账号格式校验（和注册页面保持一致：字母数字下划线8~20位）=====
    QRegularExpression regAccount("^[a-zA-Z0-9_]{8,20}$");
    if(!regAccount.match(account).hasMatch())
    {
        ui->tip->setText( tr("账号只能是字母、数字、下划线，长度8~20位"));
        ui->line_acount->setFocus();
        return false;
    }

    // ===== 3.机器编号校验（和注册页保持一致，纯数字）=====
    QRegularExpression regMachineId("^[0-9]+$");
    if(!regMachineId.match(machineId).hasMatch())
    {
         ui->tip->setText( tr("机器编号只能填写数字"));
        ui->line_mach->setFocus();
        return false;
    }
     ui->tip->setStyleSheet("color:green;");
    // ===== 全部本地校验通过，接下来调用HttpServer发起登录请求 =====
  ui->tip->setText(tr("本地校验通过，准备提交登录"));

    return true;
}

void Loding::http_finsh(Moudel id, QString res, ErrorCodes errorres)
{
    if(res.isEmpty()||errorres!=ErrorCodes::SUCCESS)
    {
        ui->tip->setText("网络错误没有回包");
        return;
    }
    QJsonDocument jsonDoc = QJsonDocument::fromJson(res.toUtf8());
    //json解析错误
    if(jsonDoc.isNull()){
        ui->tip->setText(tr("json解析错误"));
        return;
    }

    //json解析错误
    if(!jsonDoc.isObject()){
        ui->tip->setText(tr("json解析错误"));
        return;
    }
    account_msg msg;
    msg.user_name=ui->line_acount->text();
    msg.user_pwd=ui->line_pwd->text();
    msg.machine_code=ui->line_mach->text();
    emit accountMsg(msg);
    emit switchCtr();

}

