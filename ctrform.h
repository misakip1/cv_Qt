#ifndef CTRFORM_H
#define CTRFORM_H

#include <QWidget>
#include<QMap>
#include<QTimer>
#include"form.h"
#include<QMdiSubWindow>
#include"cameramanager.h"
#include <QSqlQueryModel>
#include <QTableView>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include<QDir>
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
     QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    QSqlQueryModel *model;
     QString address_;
signals:
    void SwitchAcount();
    void closeSub(QString);
public slots:
    void createMdi(QString,bool);
    void flashTabelView();

private slots:
    void on_tableView_doubleClicked(const QModelIndex &index);
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // CTRFORM_H
