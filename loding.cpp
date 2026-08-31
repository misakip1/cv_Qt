#include "loding.h"
#include "ui_loding.h"
#include<QPixmap>
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
    emit switchCtr();
}


void Loding::on_pushButton_2_clicked()
{
    emit switchGet();
}


void Loding::on_pushButton_3_clicked()
{
    emit switchReg();
}

