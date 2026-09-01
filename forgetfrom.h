#ifndef FORGETFROM_H
#define FORGETFROM_H

#include <QWidget>
#include<QJsonObject>
#include<QJsonDocument>
#include"const.h"
namespace Ui {
class ForgetFrom;
}

class ForgetFrom : public QWidget
{
    Q_OBJECT

public:
    explicit ForgetFrom(QWidget *parent = nullptr);
    ~ForgetFrom();
    void http_finsh(Moudel id,QString res,ErrorCodes error);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ForgetFrom *ui;
signals:
    void switchLog();
};

#endif // FORGETFROM_H
