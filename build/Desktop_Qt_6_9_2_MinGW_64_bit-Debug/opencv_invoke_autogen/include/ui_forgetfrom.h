/********************************************************************************
** Form generated from reading UI file 'forgetfrom.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORGETFROM_H
#define UI_FORGETFROM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ForgetFrom
{
public:
    QGridLayout *gridLayout;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_2;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QLabel *label_3;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_2;
    QLabel *label;

    void setupUi(QWidget *ForgetFrom)
    {
        if (ForgetFrom->objectName().isEmpty())
            ForgetFrom->setObjectName("ForgetFrom");
        ForgetFrom->resize(416, 352);
        gridLayout = new QGridLayout(ForgetFrom);
        gridLayout->setObjectName("gridLayout");
        widget = new QWidget(ForgetFrom);
        widget->setObjectName("widget");
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName("gridLayout_2");
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName("pushButton_2");

        gridLayout_2->addWidget(pushButton_2, 4, 1, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");

        gridLayout_2->addWidget(label_4, 2, 0, 1, 1);

        lineEdit_4 = new QLineEdit(widget);
        lineEdit_4->setObjectName("lineEdit_4");

        gridLayout_2->addWidget(lineEdit_4, 3, 1, 1, 2);

        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");

        gridLayout_2->addWidget(label_3, 3, 0, 1, 1);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");

        gridLayout_2->addWidget(pushButton, 4, 0, 1, 1);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName("lineEdit");

        gridLayout_2->addWidget(lineEdit, 0, 1, 1, 2);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        lineEdit_3 = new QLineEdit(widget);
        lineEdit_3->setObjectName("lineEdit_3");

        gridLayout_2->addWidget(lineEdit_3, 2, 1, 1, 2);

        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName("lineEdit_2");

        gridLayout_2->addWidget(lineEdit_2, 1, 1, 1, 2);

        label = new QLabel(widget);
        label->setObjectName("label");

        gridLayout_2->addWidget(label, 0, 0, 1, 1);


        gridLayout->addWidget(widget, 0, 0, 1, 1);


        retranslateUi(ForgetFrom);

        QMetaObject::connectSlotsByName(ForgetFrom);
    } // setupUi

    void retranslateUi(QWidget *ForgetFrom)
    {
        ForgetFrom->setWindowTitle(QCoreApplication::translate("ForgetFrom", "Form", nullptr));
        pushButton_2->setText(QCoreApplication::translate("ForgetFrom", "\351\207\215\347\275\256\345\257\206\347\240\201", nullptr));
        label_4->setText(QCoreApplication::translate("ForgetFrom", "\351\252\214\350\257\201\345\257\206\347\240\201", nullptr));
        label_3->setText(QCoreApplication::translate("ForgetFrom", "\351\252\214\350\257\201\347\240\201", nullptr));
        pushButton->setText(QCoreApplication::translate("ForgetFrom", "\350\277\224\345\233\236", nullptr));
        label_2->setText(QCoreApplication::translate("ForgetFrom", "\345\257\206\347\240\201", nullptr));
        label->setText(QCoreApplication::translate("ForgetFrom", "\350\264\246\345\217\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ForgetFrom: public Ui_ForgetFrom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORGETFROM_H
