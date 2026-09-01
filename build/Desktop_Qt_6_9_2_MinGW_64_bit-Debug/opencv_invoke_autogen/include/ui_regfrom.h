/********************************************************************************
** Form generated from reading UI file 'regfrom.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGFROM_H
#define UI_REGFROM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegFrom
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_5;
    QLabel *label_6;
    QLabel *label;
    QLineEdit *lineEdit_3;
    QLabel *label_3;
    QLabel *label_7;
    QPushButton *pushButton;
    QLabel *label_5;
    QLineEdit *lineEdit_6;
    QLabel *label_2;
    QLabel *label_4;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_4;
    QLabel *label_8;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit_7;

    void setupUi(QWidget *RegFrom)
    {
        if (RegFrom->objectName().isEmpty())
            RegFrom->setObjectName("RegFrom");
        RegFrom->resize(400, 300);
        horizontalLayout = new QHBoxLayout(RegFrom);
        horizontalLayout->setObjectName("horizontalLayout");
        widget = new QWidget(RegFrom);
        widget->setObjectName("widget");
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName("lineEdit");

        gridLayout->addWidget(lineEdit, 0, 2, 1, 1);

        lineEdit_5 = new QLineEdit(widget);
        lineEdit_5->setObjectName("lineEdit_5");

        gridLayout->addWidget(lineEdit_5, 4, 2, 1, 1);

        label_6 = new QLabel(widget);
        label_6->setObjectName("label_6");

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        label = new QLabel(widget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit_3 = new QLineEdit(widget);
        lineEdit_3->setObjectName("lineEdit_3");

        gridLayout->addWidget(lineEdit_3, 2, 2, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_7 = new QLabel(widget);
        label_7->setObjectName("label_7");

        gridLayout->addWidget(label_7, 6, 0, 1, 1);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");

        gridLayout->addWidget(pushButton, 5, 3, 1, 1);

        label_5 = new QLabel(widget);
        label_5->setObjectName("label_5");

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        lineEdit_6 = new QLineEdit(widget);
        lineEdit_6->setObjectName("lineEdit_6");

        gridLayout->addWidget(lineEdit_6, 5, 2, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName("lineEdit_2");

        gridLayout->addWidget(lineEdit_2, 1, 2, 1, 1);

        lineEdit_4 = new QLineEdit(widget);
        lineEdit_4->setObjectName("lineEdit_4");

        gridLayout->addWidget(lineEdit_4, 3, 2, 1, 1);

        label_8 = new QLabel(widget);
        label_8->setObjectName("label_8");

        gridLayout->addWidget(label_8, 11, 2, 1, 1);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName("pushButton_3");

        gridLayout->addWidget(pushButton_3, 11, 3, 1, 1);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName("pushButton_2");

        gridLayout->addWidget(pushButton_2, 9, 3, 1, 1);

        lineEdit_7 = new QLineEdit(widget);
        lineEdit_7->setObjectName("lineEdit_7");

        gridLayout->addWidget(lineEdit_7, 6, 2, 1, 1);


        horizontalLayout->addWidget(widget);


        retranslateUi(RegFrom);

        QMetaObject::connectSlotsByName(RegFrom);
    } // setupUi

    void retranslateUi(QWidget *RegFrom)
    {
        RegFrom->setWindowTitle(QCoreApplication::translate("RegFrom", "Form", nullptr));
        label_6->setText(QCoreApplication::translate("RegFrom", "\346\234\272\345\231\250\347\274\226\345\217\267", nullptr));
        label->setText(QCoreApplication::translate("RegFrom", "\350\264\246\345\217\267", nullptr));
        label_3->setText(QCoreApplication::translate("RegFrom", "\345\257\206\347\240\201", nullptr));
        label_7->setText(QCoreApplication::translate("RegFrom", "\351\252\214\350\257\201\347\240\201", nullptr));
        pushButton->setText(QCoreApplication::translate("RegFrom", "\350\216\267\345\217\226\351\252\214\350\257\201\347\240\201", nullptr));
        label_5->setText(QCoreApplication::translate("RegFrom", "\346\234\272\345\231\250\345\220\215", nullptr));
        label_2->setText(QCoreApplication::translate("RegFrom", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_4->setText(QCoreApplication::translate("RegFrom", "\351\252\214\350\257\201\345\257\206\347\240\201", nullptr));
        label_8->setText(QCoreApplication::translate("RegFrom", "\346\263\250\345\206\214\346\210\220\345\212\237", nullptr));
        pushButton_3->setText(QCoreApplication::translate("RegFrom", "\350\277\224\345\233\236", nullptr));
        pushButton_2->setText(QCoreApplication::translate("RegFrom", "\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegFrom: public Ui_RegFrom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGFROM_H
