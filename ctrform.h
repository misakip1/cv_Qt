#ifndef CTRFORM_H
#define CTRFORM_H

#include <QWidget>
#include<QMap>
#include"form.h"
#include<QMdiSubWindow>

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

signals:
    void SwitchAcount();
    void closeSub(QString);
public slots:
    void createMdi(QString,bool);
};

#endif // CTRFORM_H
