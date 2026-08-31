#include "ctrform.h"
#include"titelicon.h"
#include "ui_ctrform.h"
#include<QPixmap>
#include <QCameraDevice>
#include <QMediaDevices>
CtrForm::CtrForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CtrForm)
{
    ui->setupUi(this);
    connect(ui->titwid,&TitelIcon::SwitchAcount,this,&CtrForm::SwitchAcount);
    QList<QCameraDevice> cameraList = QMediaDevices::videoInputs();
    QStringList s;
    for(auto&i:cameraList)
    {
        s<<i.description();
    }
    ui->comboBox->addItems(s);

}

CtrForm::~CtrForm()
{
    delete ui;
}
