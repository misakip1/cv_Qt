#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include"const.h"
namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();
    void showPix(CameraTask);
private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();

signals:
    void stop_();
    void start_();
private:
    Ui::Form *ui;
    QPixmap map1_;
    QPixmap map2_;
};

#endif // FORM_H
