#ifndef REGFROM_H
#define REGFROM_H

#include <QWidget>
#include"const.h"
#include<QJsonObject>
#include<QJsonDocument>
namespace Ui {
class RegFrom;
}

class RegFrom : public QWidget
{
    Q_OBJECT

public:
    explicit RegFrom(QWidget *parent = nullptr);
    ~RegFrom();


    void http_finsh(Moudel id, QString res, ErrorCodes error);
private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();
    bool reg();
private:
    Ui::RegFrom *ui;
signals:
    void switchLog();
};

#endif // REGFROM_H
