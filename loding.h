#ifndef LODING_H
#define LODING_H

#include <QWidget>

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

private:
    Ui::Loding *ui;
    QString accout;
    QString pwd;
    QString machin_num;
signals:
    void switchReg();
    void switchCtr();
    void switchGet();
};

#endif // LODING_H
