#ifndef TITELICON_H
#define TITELICON_H

#include <QWidget>

namespace Ui {
class TitelIcon;
}

class TitelIcon : public QWidget
{
    Q_OBJECT

public:
    explicit TitelIcon(QWidget *parent = nullptr);
    ~TitelIcon();
    void mouseDoubleClickEvent(QMouseEvent*event) override;

private:
    Ui::TitelIcon *ui;
signals:
    void SwitchAcount();
};

#endif // TITELICON_H
