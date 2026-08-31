#ifndef FORGETFROM_H
#define FORGETFROM_H

#include <QWidget>

namespace Ui {
class ForgetFrom;
}

class ForgetFrom : public QWidget
{
    Q_OBJECT

public:
    explicit ForgetFrom(QWidget *parent = nullptr);
    ~ForgetFrom();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ForgetFrom *ui;
signals:
    void switchLog();
};

#endif // FORGETFROM_H
