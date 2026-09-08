#ifndef FORM_H
#define FORM_H

#include <QWidget>

#include"const.h"
#include"algorithmdialog.h"
namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();
    void showPix(std::shared_ptr<CameraTask>);
    bool checkConfig();
public slots:
    void setConfig(std::shared_ptr<AlgorithmConfig> msg);
    void setFps(double fps);
private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

signals:
    void stop_();
    void start_();
    void cvMgr_config(std::shared_ptr<AlgorithmConfig> msg);
private:
    Ui::Form *ui;
    QPixmap map1_;
    QPixmap map2_;
    std::shared_ptr<AlgorithmConfig >config_;
    AlgorithmDialog*config_form_;
};

#endif // FORM_H
