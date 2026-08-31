#ifndef REGFROM_H
#define REGFROM_H

#include <QWidget>

namespace Ui {
class RegFrom;
}

class RegFrom : public QWidget
{
    Q_OBJECT

public:
    explicit RegFrom(QWidget *parent = nullptr);
    ~RegFrom();

private slots:
    void on_pushButton_3_clicked();

private:
    Ui::RegFrom *ui;
signals:
    void switchLog();
};

#endif // REGFROM_H
