#include "regfrom.h"
#include "ui_regfrom.h"

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

