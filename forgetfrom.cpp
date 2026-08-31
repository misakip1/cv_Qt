#include "forgetfrom.h"
#include "ui_forgetfrom.h"

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

void ForgetFrom::on_pushButton_clicked()
{
    emit switchLog();
}

