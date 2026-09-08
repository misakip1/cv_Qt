#ifndef ALGORITHMDIALOG_H
#define ALGORITHMDIALOG_H

#include <QDialog>
#include"const.h"
namespace Ui {
class AlgorithmDialog;
}

class AlgorithmDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AlgorithmDialog(QWidget *parent = nullptr);
    ~AlgorithmDialog();

private slots:
    void on_buttonBox_accepted();
signals:
    void configMsg(std::shared_ptr<AlgorithmConfig>);
private:
    Ui::AlgorithmDialog *ui;
    std::shared_ptr<AlgorithmConfig > config_;
};

#endif // ALGORITHMDIALOG_H
