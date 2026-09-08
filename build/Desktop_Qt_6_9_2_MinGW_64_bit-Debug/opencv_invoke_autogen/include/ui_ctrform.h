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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
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
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_3;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    MultiSelectComboBox *comboBox;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_3;
    QMdiArea *mdiArea;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_5;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_6;
    QWidget *widget_6;
    QVBoxLayout *verticalLayout_4;
    QTableView *tableView;
    QWidget *widget_7;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_7;
    QWidget *widget_9;
    QWidget *widget_10;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
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
"}\n"
"QMdiArea#mdiArea\n"
"{\n"
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

        label_2 = new QLabel(widget_4);
        label_2->setObjectName("label_2");

        horizontalLayout_4->addWidget(label_2);

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

        horizontalSpacer = new QSpacerItem(0, 0, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 5);
        horizontalLayout_2->setStretch(2, 3);

        verticalLayout_2->addWidget(widget);

        widget_2 = new QWidget(tab);
        widget_2->setObjectName("widget_2");
        horizontalLayout_3 = new QHBoxLayout(widget_2);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        mdiArea = new QMdiArea(widget_2);
        mdiArea->setObjectName("mdiArea");
        mdiArea->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_3->addWidget(mdiArea);


        verticalLayout_2->addWidget(widget_2);

        widget_3 = new QWidget(tab);
        widget_3->setObjectName("widget_3");
        horizontalLayout = new QHBoxLayout(widget_3);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addWidget(widget_3);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 10);
        verticalLayout_2->setStretch(2, 1);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        horizontalLayout_5 = new QHBoxLayout(tab_2);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        widget_5 = new QWidget(tab_2);
        widget_5->setObjectName("widget_5");
        horizontalLayout_6 = new QHBoxLayout(widget_5);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        widget_6 = new QWidget(widget_5);
        widget_6->setObjectName("widget_6");
        verticalLayout_4 = new QVBoxLayout(widget_6);
        verticalLayout_4->setObjectName("verticalLayout_4");
        tableView = new QTableView(widget_6);
        tableView->setObjectName("tableView");
        tableView->setStyleSheet(QString::fromUtf8("QTableView\n"
"{\n"
"    background-color: #f3e5f5;\n"
"    gridline-color: #ce93d8;\n"
"    color: #4a148c;\n"
"    selection-background-color: #e1bee7;\n"
"    selection-color: #212121;\n"
"    border:1px solid #ba68c8;\n"
"}\n"
"QHeaderView::section\n"
"{\n"
"    background-color: #e1bee7;\n"
"    color:#4a148c;\n"
"    border: none;\n"
"    border-right:1px solid #ce93d8;\n"
"    border-bottom:1px solid #ce93d8;\n"
"    padding:4px;\n"
"}\n"
"QTableView::item\n"
"{\n"
"    padding:2px;\n"
"}\n"
"QTableView::item:hover\n"
"{\n"
"    background-color:#f0e0f7;\n"
"}"));

        verticalLayout_4->addWidget(tableView);


        horizontalLayout_6->addWidget(widget_6);

        widget_7 = new QWidget(widget_5);
        widget_7->setObjectName("widget_7");
        verticalLayout_3 = new QVBoxLayout(widget_7);
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_3 = new QLabel(widget_7);
        label_3->setObjectName("label_3");

        verticalLayout_3->addWidget(label_3);

        widget_8 = new QWidget(widget_7);
        widget_8->setObjectName("widget_8");
        horizontalLayout_7 = new QHBoxLayout(widget_8);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        widget_9 = new QWidget(widget_8);
        widget_9->setObjectName("widget_9");

        horizontalLayout_7->addWidget(widget_9);

        widget_10 = new QWidget(widget_8);
        widget_10->setObjectName("widget_10");
        verticalLayout_5 = new QVBoxLayout(widget_10);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);

        pushButton = new QPushButton(widget_10);
        pushButton->setObjectName("pushButton");

        verticalLayout_5->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget_10);
        pushButton_2->setObjectName("pushButton_2");

        verticalLayout_5->addWidget(pushButton_2);


        horizontalLayout_7->addWidget(widget_10);


        verticalLayout_3->addWidget(widget_8);

        verticalLayout_3->setStretch(0, 4);
        verticalLayout_3->setStretch(1, 1);

        horizontalLayout_6->addWidget(widget_7);

        horizontalLayout_6->setStretch(0, 2);
        horizontalLayout_6->setStretch(1, 1);

        horizontalLayout_5->addWidget(widget_5);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        tabWidget->addTab(tab_3, QString());

        verticalLayout->addWidget(tabWidget);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 10);

        retranslateUi(CtrForm);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(CtrForm);
    } // setupUi

    void retranslateUi(QWidget *CtrForm)
    {
        CtrForm->setWindowTitle(QCoreApplication::translate("CtrForm", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("CtrForm", "Misaki", nullptr));
        label->setText(QCoreApplication::translate("CtrForm", "\351\200\211\346\213\251\347\233\270\346\234\272", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("CtrForm", "\346\243\200\346\265\213\345\214\272\345\237\237", nullptr));
        label_3->setText(QString());
        pushButton->setText(QCoreApplication::translate("CtrForm", "\344\277\235\345\255\230", nullptr));
        pushButton_2->setText(QCoreApplication::translate("CtrForm", "\345\217\226\346\266\210", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("CtrForm", "\346\225\260\346\215\256\345\272\223\345\244\215\346\243\200", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("CtrForm", "\347\275\221\347\273\234\350\277\236\346\216\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CtrForm: public Ui_CtrForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CTRFORM_H
