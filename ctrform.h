#ifndef CTRFORM_H
#define CTRFORM_H

#include <QWidget>

namespace Ui {
class CtrForm;
}

class CtrForm : public QWidget
{
    Q_OBJECT

public:
    explicit CtrForm(QWidget *parent = nullptr);
    ~CtrForm();

private:
    Ui::CtrForm *ui;
signals:
    void SwitchAcount();
};

#endif // CTRFORM_H
