#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loding_=new Loding(this);
    this->setCentralWidget(loding_);
    loding_->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);

    loding_->show();
    connect(loding_,&Loding::switchReg,this,&MainWindow::SlotSwitchReg);
    connect(loding_,&Loding::switchGet,this,&MainWindow::SlotSwitchGet);
    connect(loding_,&Loding::switchCtr,this,&MainWindow::SlotSwitchCtr);
   // SlotSwitchCtr();


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
    if(oldWidget)
    {
        oldWidget->deleteLater(); // Qt推荐，安全删除
    }

    ctrform_=new CtrForm(this);
    this->setCentralWidget(ctrform_);
    ctrform_->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    ctrform_->show();
    this->setMinimumSize(QSize(800,900));
    this->setMaximumSize(QWIDGETSIZE_MAX, QWIDGETSIZE_MAX);
    connect(ctrform_,&CtrForm::SwitchAcount,this,&MainWindow::SwitchAcount);

}

void MainWindow::SwitchAcount()
{

}
