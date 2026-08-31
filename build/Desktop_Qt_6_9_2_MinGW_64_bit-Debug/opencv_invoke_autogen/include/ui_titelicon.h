/********************************************************************************
** Form generated from reading UI file 'titelicon.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TITELICON_H
#define UI_TITELICON_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TitelIcon
{
public:
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;

    void setupUi(QWidget *TitelIcon)
    {
        if (TitelIcon->objectName().isEmpty())
            TitelIcon->setObjectName("TitelIcon");
        TitelIcon->resize(213, 91);
        horizontalLayout_2 = new QHBoxLayout(TitelIcon);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(TitelIcon);
        widget->setObjectName("widget");
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);


        horizontalLayout_2->addWidget(widget);


        retranslateUi(TitelIcon);

        QMetaObject::connectSlotsByName(TitelIcon);
    } // setupUi

    void retranslateUi(QWidget *TitelIcon)
    {
        TitelIcon->setWindowTitle(QCoreApplication::translate("TitelIcon", "Form", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TitelIcon: public Ui_TitelIcon {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TITELICON_H
