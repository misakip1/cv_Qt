#ifndef CHECKABLECOMBOX_H
#define CHECKABLECOMBOX_H

#include <QComboBox>
#include <QObject>

class CheckableCombox : public QComboBox
{
    Q_OBJECT
public:
    CheckableCombox(QWidget*par=nullptr);
};

#endif // CHECKABLECOMBOX_H
