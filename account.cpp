#include "account.h"
#include "ui_account.h"  // uic自动生成的头文件
#include<QPixmap>
account::account(account_msg msg,QWidget* par)
    : QWidget(par)
    , ui(new Ui::account),msg_(msg)  // 这里是Ui::account，不是Ui::Form
{
    ui->setupUi(this);
    QPixmap map("E:\\Qt_projet\\opencv_invoke\\title.png");
    map.scaled(ui->label->size());
     ui->label_2->setPixmap(map);
    if(msg.user_name.isEmpty()||msg.user_pwd.isEmpty()||msg.machine_code.isEmpty())
        return;

    ui->label->setText(msg_.user_name);
    ui->label_3->setText("机器编号"+msg.machine_code);


}

// 析构函数记得释放ui
account::~account()
{
    qDebug()<<"释放account";
    delete ui;
}

void account::on_pushButton_clicked()
{
    emit switchCtr();
}
