#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    stack_=new QStackedWidget(this);
    // loding_=new Loding(this);
    // this->setCentralWidget(loding_);
    // loding_->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);

    // loding_->show();
    // connect(loding_,&Loding::switchReg,this,&MainWindow::SlotSwitchReg);
    // connect(loding_,&Loding::switchGet,this,&MainWindow::SlotSwitchGet);
    // connect(loding_,&Loding::switchCtr,this,&MainWindow::SlotSwitchCtr);
    ctr_pointer_=new CtrForm(this);
    ctr_pointer_->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    connect(ctr_pointer_,&CtrForm::SwitchAcount,this,&MainWindow::SwitchAcount);
    stack_->addWidget(ctr_pointer_);

    account_pointer_=new account(msg_,this);
    connect(account_pointer_,&account::switchCtr,this,&MainWindow::SlotSwitchCtr);
    stack_->addWidget(account_pointer_);
   SlotSwitchCtr();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SlotSwitchReg()
{
    QWidget* oldWidget = this->centralWidget();
    if(oldWidget)
    {
        oldWidget->deleteLater(); // Qt推荐，安全删除
    }
    regfrom_=new RegFrom(this);
    connect(regfrom_,&RegFrom::switchLog,this,&MainWindow::SlotSwitchLog);
    this->setCentralWidget(regfrom_);
    regfrom_->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    regfrom_->show();
}

void MainWindow::SlotSwitchLog()
{
    QWidget* oldWidget = this->centralWidget();
    if(oldWidget)
    {
        oldWidget->deleteLater(); // Qt推荐，安全删除
    }
    loding_=new Loding(this);
    this->setCentralWidget(loding_);
    loding_->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);

    loding_->show();
    connect(loding_,&Loding::switchReg,this,&MainWindow::SlotSwitchReg);
    connect(loding_,&Loding::switchGet,this,&MainWindow::SlotSwitchGet);
    connect(loding_,&Loding::switchCtr,this,&MainWindow::SlotSwitchCtr);
    connect(loding_,&Loding::accountMsg,this,[this](AccountMsg msg){
        this->msg_=msg;
    });
}

void MainWindow::SlotSwitchGet()
{
    QWidget* oldWidget = this->centralWidget();
    if(oldWidget)
    {
        oldWidget->deleteLater(); // Qt推荐，安全删除
    }
    forgetfrom_=new ForgetFrom(this);
    this->setCentralWidget(forgetfrom_);
    forgetfrom_->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    forgetfrom_->show();
    connect(forgetfrom_,&ForgetFrom::switchLog,this,&MainWindow::SlotSwitchLog);


}

void MainWindow::SlotSwitchCtr()
{
    QWidget* oldWidget = this->centralWidget();
    // 判断：如果旧页面不是account_pointer_，才delete
    if(oldWidget && oldWidget != stack_)
    {
        oldWidget->deleteLater();
    }

    stack_->setCurrentWidget(ctr_pointer_);
    this->setCentralWidget(stack_);
    this->setMinimumSize(QSize(800,900));
    this->setMaximumSize(QWIDGETSIZE_MAX, QWIDGETSIZE_MAX);
}
void MainWindow::SwitchAcount()
{
     stack_->setCurrentWidget(account_pointer_);


}
