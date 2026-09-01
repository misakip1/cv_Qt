#ifndef LODING_H
#define LODING_H

#include <QWidget>
#include"const.h"
namespace Ui {
class Loding;
}

class Loding : public QWidget
{
    Q_OBJECT

public:
    explicit Loding(QWidget *parent = nullptr);
    ~Loding();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();
    bool log();
    void http_finsh(Moudel id,QString ,ErrorCodes errorres);
private:
    Ui::Loding *ui;
    QString accout;
    QString pwd;
    QString machin_num;
signals:
    void switchReg();
    void switchCtr();
    void switchGet();
    void accountMsg(account_msg);
};

#endif // LODING_H
