/********************************************************************************
** Form generated from reading UI file 'loding.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LODING_H
#define UI_LODING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Loding
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *icon;
    QWidget *widget_3;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *line_acount;
    QPushButton *pushButton_2;
    QLabel *password;
    QLabel *acount;
    QLabel *tip;
    QPushButton *pushButton;
    QLineEdit *line_mach;
    QLineEdit *line_pwd;
    QLabel *machine;
    QPushButton *pushButton_3;

    void setupUi(QWidget *Loding)
    {
        if (Loding->objectName().isEmpty())
            Loding->setObjectName("Loding");
        Loding->resize(300, 600);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Loding->sizePolicy().hasHeightForWidth());
        Loding->setSizePolicy(sizePolicy);
        Loding->setMinimumSize(QSize(250, 500));
        Loding->setMaximumSize(QSize(300, 600));
        QFont font;
        font.setPointSize(11);
        Loding->setFont(font);
        Loding->setStyleSheet(QString::fromUtf8("/* ===== \344\270\273\347\252\227\345\217\243\350\203\214\346\231\257 ===== */\n"
"#Loding {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #f8ecf7,\n"
"        stop:1 #eadef7\n"
"    );\n"
"    border-radius: 14px;\n"
"}\n"
"\n"
"/* ===== \351\200\232\347\224\250\346\240\207\347\255\276\346\226\207\345\255\227 ===== */\n"
"QLabel {\n"
"    color: #6b4a87;\n"
"    font-size: 13px;\n"
"}\n"
"\n"
"/* ===== \345\244\264\345\203\217/\345\233\276\347\211\207\345\214\272\345\237\237 ===== */\n"
"#icon {\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"/* ===== \350\241\250\345\215\225\345\215\241\347\211\207\345\256\271\345\231\250 ===== */\n"
"#widget_3 {\n"
"    background-color: rgba(255, 255, 255, 0.55);\n"
"    border-radius: 10px;\n"
"    padding: 18px 22px;\n"
"}\n"
"\n"
"/* ===== \350\276\223\345\205\245\346\241\206 ===== */\n"
"QLineEdit {\n"
"    background-color: rgba(255, 255, 255, 0.9);\n"
"    border: 1px solid #d4bce6;\n"
"    border-radius: 7px;\n"
"    padding"
                        ": 6px 11px;\n"
"    color: #5a3d75;\n"
"    font-size: 13px;\n"
"    min-height: 20px;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border-color: #c48fdd;\n"
"    background-color: #ffffff;\n"
"}\n"
"\n"
"QLineEdit::placeholder {\n"
"    color: #b39dc9;\n"
"}\n"
"\n"
"/* ===== \347\231\273\345\275\225\346\214\211\351\222\256 ===== */\n"
"QPushButton {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #dba8e8,\n"
"        stop:1 #b988da\n"
"    );\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 7px;\n"
"    padding: 7px 18px;\n"
"    font-size: 13px;\n"
"    font-weight: 500;\n"
"    min-height: 22px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #e2b3ed,\n"
"        stop:1 #c395e0\n"
"    );\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #c995d9,\n"
"        stop:1 #ab79cc\n"
"    );\n"
"}\n"
""));
        horizontalLayout = new QHBoxLayout(Loding);
        horizontalLayout->setObjectName("horizontalLayout");
        widget = new QWidget(Loding);
        widget->setObjectName("widget");
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        widget_2 = new QWidget(widget);
        widget_2->setObjectName("widget_2");
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        icon = new QLabel(widget_2);
        icon->setObjectName("icon");

        horizontalLayout_2->addWidget(icon);


        verticalLayout->addWidget(widget_2);

        widget_3 = new QWidget(widget);
        widget_3->setObjectName("widget_3");
        gridLayout = new QGridLayout(widget_3);
        gridLayout->setObjectName("gridLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 5, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 5, 2, 1, 1);

        line_acount = new QLineEdit(widget_3);
        line_acount->setObjectName("line_acount");

        gridLayout->addWidget(line_acount, 1, 1, 1, 1);

        pushButton_2 = new QPushButton(widget_3);
        pushButton_2->setObjectName("pushButton_2");

        gridLayout->addWidget(pushButton_2, 2, 2, 1, 1, Qt::AlignmentFlag::AlignVCenter);

        password = new QLabel(widget_3);
        password->setObjectName("password");

        gridLayout->addWidget(password, 2, 0, 1, 1);

        acount = new QLabel(widget_3);
        acount->setObjectName("acount");

        gridLayout->addWidget(acount, 1, 0, 1, 1);

        tip = new QLabel(widget_3);
        tip->setObjectName("tip");

        gridLayout->addWidget(tip, 0, 1, 1, 1);

        pushButton = new QPushButton(widget_3);
        pushButton->setObjectName("pushButton");

        gridLayout->addWidget(pushButton, 5, 1, 1, 1);

        line_mach = new QLineEdit(widget_3);
        line_mach->setObjectName("line_mach");

        gridLayout->addWidget(line_mach, 3, 1, 1, 1);

        line_pwd = new QLineEdit(widget_3);
        line_pwd->setObjectName("line_pwd");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(line_pwd->sizePolicy().hasHeightForWidth());
        line_pwd->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(line_pwd, 2, 1, 1, 1);

        machine = new QLabel(widget_3);
        machine->setObjectName("machine");

        gridLayout->addWidget(machine, 3, 0, 1, 1);

        pushButton_3 = new QPushButton(widget_3);
        pushButton_3->setObjectName("pushButton_3");

        gridLayout->addWidget(pushButton_3, 4, 1, 1, 1);


        verticalLayout->addWidget(widget_3);


        horizontalLayout->addWidget(widget);


        retranslateUi(Loding);

        QMetaObject::connectSlotsByName(Loding);
    } // setupUi

    void retranslateUi(QWidget *Loding)
    {
        Loding->setWindowTitle(QCoreApplication::translate("Loding", "Form", nullptr));
        icon->setText(QString());
        pushButton_2->setText(QCoreApplication::translate("Loding", "\345\277\230\350\256\260\345\257\206\347\240\201", nullptr));
        password->setText(QCoreApplication::translate("Loding", "\345\257\206\347\240\201", nullptr));
        acount->setText(QCoreApplication::translate("Loding", "\350\264\246\345\217\267", nullptr));
        tip->setText(QString());
        pushButton->setText(QCoreApplication::translate("Loding", "\347\231\273\345\275\225", nullptr));
        machine->setText(QCoreApplication::translate("Loding", "\346\234\272\345\231\250\345\217\267", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Loding", "\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Loding: public Ui_Loding {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LODING_H
