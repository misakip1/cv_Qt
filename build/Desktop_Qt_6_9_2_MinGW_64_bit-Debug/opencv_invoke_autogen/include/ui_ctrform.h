/********************************************************************************
** Form generated from reading UI file 'ctrform.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CTRFORM_H
#define UI_CTRFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <multiselectcombobox.h>
#include <titelicon.h>

QT_BEGIN_NAMESPACE

class Ui_CtrForm
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_4;
    TitelIcon *titwid;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer_3;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    MultiSelectComboBox *comboBox;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_3;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_2;
    QWidget *tab_2;
    QWidget *tab_3;

    void setupUi(QWidget *CtrForm)
    {
        if (CtrForm->objectName().isEmpty())
            CtrForm->setObjectName("CtrForm");
        CtrForm->resize(650, 501);
        QFont font;
        font.setPointSize(11);
        CtrForm->setFont(font);
        CtrForm->setStyleSheet(QString::fromUtf8("/* CtrForm \344\270\273\347\252\227\344\275\223\350\203\214\346\231\257 */\n"
"#CtrForm {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #f8ecf7,\n"
"        stop:1 #eadef7\n"
"    );\n"
"}\n"
"MultiSelectComboBox\n"
"{\n"
"background: qlineargradient(\n"
"        x1:0,y1:0,x2:0,y2:1,\n"
"        stop:0 #dba8e8,\n"
"        stop:1 #b988da\n"
"    );\n"
"    color:white;\n"
"    border:none;\n"
"    border-radius:8px;\n"
"    padding:7px 16px;\n"
"    font-size:12px;\n"
"}\n"
"/* TabWidget \346\225\264\344\275\223 */\n"
"QTabWidget::pane {\n"
"    border:1px solid #d4bce6;\n"
"    border-radius:8px;\n"
"    background-color:rgba(255,255,255,0.62);\n"
"}\n"
"QTabBar::tab {\n"
"    background:rgba(255,255,255,0.5);\n"
"    color:#6b4a87;\n"
"    padding:6px 14px;\n"
"    border:1px solid #d4bce6;\n"
"    border-bottom:none;\n"
"    border-top-left-radius:6px;\n"
"    border-top-right-radius:6px;\n"
"}\n"
"QTabBar::tab:selected {\n"
"    background:#dba8e8;\n"
"    colo"
                        "r:white;\n"
"}\n"
"QTabBar::tab:hover {\n"
"    background:#e8cff2;\n"
"}\n"
"\n"
"/* PushButton \346\214\211\351\222\256\357\274\214\346\226\260\345\242\236\346\214\211\351\222\256\350\207\252\345\212\250\347\224\237\346\225\210 */\n"
"QPushButton {\n"
"    background: qlineargradient(\n"
"        x1:0,y1:0,x2:0,y2:1,\n"
"        stop:0 #dba8e8,\n"
"        stop:1 #b988da\n"
"    );\n"
"    color:white;\n"
"    border:none;\n"
"    border-radius:8px;\n"
"    padding:7px 16px;\n"
"    font-size:12px;\n"
"}\n"
"QPushButton:hover {\n"
"    background: qlineargradient(\n"
"        x1:0,y1:0,x2:0,y2:1,\n"
"        stop:0 #e2b3ed,\n"
"        stop:1 #c395e0\n"
"    );\n"
"}\n"
"QPushButton:pressed {\n"
"    background: qlineargradient(\n"
"        x1:0,y1:0,x2:0,y2:1,\n"
"        stop:0 #c985d9,\n"
"        stop:1 #ab79cc\n"
"    );\n"
"}\n"
"\n"
"/* Label \346\226\207\345\255\227\357\274\214\345\220\216\347\273\255\346\226\260\345\242\236label\350\207\252\345\212\250\351\200\202\351\205\215\346\226\207\345\255\227"
                        "\351\242\234\350\211\262 */\n"
"QLabel {\n"
"    color:#6b4a87;\n"
"    font-size:12px;\n"
"}"));
        verticalLayout = new QVBoxLayout(CtrForm);
        verticalLayout->setObjectName("verticalLayout");
        widget_4 = new QWidget(CtrForm);
        widget_4->setObjectName("widget_4");
        horizontalLayout_4 = new QHBoxLayout(widget_4);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        titwid = new TitelIcon(widget_4);
        titwid->setObjectName("titwid");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(titwid->sizePolicy().hasHeightForWidth());
        titwid->setSizePolicy(sizePolicy);
        titwid->setMinimumSize(QSize(50, 50));
        titwid->setMaximumSize(QSize(50, 50));

        horizontalLayout_4->addWidget(titwid);

        pushButton_3 = new QPushButton(widget_4);
        pushButton_3->setObjectName("pushButton_3");

        horizontalLayout_4->addWidget(pushButton_3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);


        verticalLayout->addWidget(widget_4);

        tabWidget = new QTabWidget(CtrForm);
        tabWidget->setObjectName("tabWidget");
        tab = new QWidget();
        tab->setObjectName("tab");
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setObjectName("verticalLayout_2");
        widget = new QWidget(tab);
        widget->setObjectName("widget");
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(widget);
        label->setObjectName("label");

        horizontalLayout_2->addWidget(label);

        comboBox = new MultiSelectComboBox(widget);
        comboBox->setObjectName("comboBox");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(comboBox);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout_2->addWidget(pushButton_2);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");

        horizontalLayout_2->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 5);
        horizontalLayout_2->setStretch(2, 3);
        horizontalLayout_2->setStretch(3, 3);
        horizontalLayout_2->setStretch(4, 3);

        verticalLayout_2->addWidget(widget);

        widget_2 = new QWidget(tab);
        widget_2->setObjectName("widget_2");
        horizontalLayout_3 = new QHBoxLayout(widget_2);
        horizontalLayout_3->setObjectName("horizontalLayout_3");

        verticalLayout_2->addWidget(widget_2);

        widget_3 = new QWidget(tab);
        widget_3->setObjectName("widget_3");
        horizontalLayout = new QHBoxLayout(widget_3);
        horizontalLayout->setObjectName("horizontalLayout");
        label_3 = new QLabel(widget_3);
        label_3->setObjectName("label_3");

        horizontalLayout->addWidget(label_3);

        label_4 = new QLabel(widget_3);
        label_4->setObjectName("label_4");

        horizontalLayout->addWidget(label_4);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addWidget(widget_3);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 10);
        verticalLayout_2->setStretch(2, 1);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        tabWidget->addTab(tab_3, QString());

        verticalLayout->addWidget(tabWidget);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 10);

        retranslateUi(CtrForm);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(CtrForm);
    } // setupUi

    void retranslateUi(QWidget *CtrForm)
    {
        CtrForm->setWindowTitle(QCoreApplication::translate("CtrForm", "Form", nullptr));
        pushButton_3->setText(QCoreApplication::translate("CtrForm", "PushButton", nullptr));
        label->setText(QCoreApplication::translate("CtrForm", "\351\200\211\346\213\251\347\233\270\346\234\272", nullptr));
        pushButton_2->setText(QCoreApplication::translate("CtrForm", "\345\274\200\345\247\213\346\243\200\346\265\213", nullptr));
        pushButton->setText(QCoreApplication::translate("CtrForm", "\347\273\223\346\235\237\346\243\200\346\265\213", nullptr));
        label_3->setText(QCoreApplication::translate("CtrForm", "\346\210\220\345\212\237\350\277\230\346\230\257ng", nullptr));
        label_4->setText(QCoreApplication::translate("CtrForm", "\347\274\272\351\231\267\344\270\252\346\225\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("CtrForm", "\346\243\200\346\265\213\345\214\272\345\237\237", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("CtrForm", "\346\225\260\346\215\256\345\272\223\345\244\215\346\243\200", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("CtrForm", "\347\275\221\347\273\234\350\277\236\346\216\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CtrForm: public Ui_CtrForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CTRFORM_H
