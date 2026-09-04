#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"loding.h"
#include"regfrom.h"
#include"forgetfrom.h"
#include"ctrform.h"
#include"account.h"
#include<QPointer>
#include<QStackedWidget>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void SlotSwitchReg();
    void SlotSwitchLog();
    void SlotSwitchGet();
    void SlotSwitchCtr();
    void SwitchAcount();
private:
    Ui::MainWindow *ui;
    Loding*loding_;
    RegFrom*regfrom_;
    ForgetFrom*forgetfrom_;
    QPointer<account>account_pointer_;
    AccountMsg msg_;
    QPointer<CtrForm> ctr_pointer_;
    QStackedWidget*stack_;


};
#endif // MAINWINDOW_H
