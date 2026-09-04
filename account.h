#pragma once
#include <QWidget>
#include"const.h"
// 前置声明UI类，cpp里再引入头文件
namespace Ui {
class account;
}

class account : public QWidget
{
    Q_OBJECT  // Qt类必须加，信号槽/元对象需要
public:
    explicit account(AccountMsg msg,QWidget *parent = nullptr);
    ~account();


private slots:
    void on_pushButton_clicked();

signals:
    void switchCtr();
private:
    Ui::account *ui;  // 类名和ui的objectName对应
    AccountMsg msg_;
};
