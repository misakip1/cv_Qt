#ifndef CTRFORM_H
#define CTRFORM_H

#include <QWidget>
#include<QMap>
#include"form.h"
#include<QMdiSubWindow>
#include"cameramanager.h"
namespace Ui {
class CtrForm;
}

class CtrForm : public QWidget
{
    Q_OBJECT

public:
    explicit CtrForm(QWidget *parent = nullptr);
    ~CtrForm();

private:
    Ui::CtrForm *ui;
    QMap<QString,QMdiSubWindow*> mapper_;
    CameraManager*mannger_;
signals:
    void SwitchAcount();
    void closeSub(QString);
public slots:
    void createMdi(QString,bool);
};

#endif // CTRFORM_H
