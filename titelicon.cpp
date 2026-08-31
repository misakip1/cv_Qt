#include "titelicon.h"
#include "ui_titelicon.h"
#include<QPixmap>
TitelIcon::TitelIcon(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TitelIcon)
{
    ui->setupUi(this);
    QPixmap map("E:\\Qt_projet\\opencv_invoke\\title.png");
    ui->label->setPixmap(map);
    ui->label->setScaledContents(true);
}

TitelIcon::~TitelIcon()
{
    delete ui;
}

void TitelIcon::mouseDoubleClickEvent(QMouseEvent *event)
{
    qDebug()<<"触发双击";
    emit SwitchAcount();
}
