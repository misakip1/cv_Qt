/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QCheckBox *checkBox_6;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName("Form");
        Form->resize(439, 340);
        Form->setStyleSheet(QString::fromUtf8("QWidget#Form{\n"
"    background-color: #E2C5E2;\n"
"}"));
        verticalLayout = new QVBoxLayout(Form);
        verticalLayout->setObjectName("verticalLayout");
        widget_5 = new QWidget(Form);
        widget_5->setObjectName("widget_5");
        horizontalLayout_5 = new QHBoxLayout(widget_5);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_5 = new QLabel(widget_5);
        label_5->setObjectName("label_5");

        horizontalLayout_5->addWidget(label_5);

        checkBox_6 = new QCheckBox(widget_5);
        checkBox_6->setObjectName("checkBox_6");

        horizontalLayout_5->addWidget(checkBox_6);

        checkBox_5 = new QCheckBox(widget_5);
        checkBox_5->setObjectName("checkBox_5");

        horizontalLayout_5->addWidget(checkBox_5);

        checkBox_4 = new QCheckBox(widget_5);
        checkBox_4->setObjectName("checkBox_4");

        horizontalLayout_5->addWidget(checkBox_4);

        checkBox_3 = new QCheckBox(widget_5);
        checkBox_3->setObjectName("checkBox_3");

        horizontalLayout_5->addWidget(checkBox_3);

        checkBox = new QCheckBox(widget_5);
        checkBox->setObjectName("checkBox");

        horizontalLayout_5->addWidget(checkBox);

        checkBox_2 = new QCheckBox(widget_5);
        checkBox_2->setObjectName("checkBox_2");

        horizontalLayout_5->addWidget(checkBox_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget_5);

        widget = new QWidget(Form);
        widget->setObjectName("widget");
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        widget_2 = new QWidget(widget);
        widget_2->setObjectName("widget_2");
        horizontalLayout_3 = new QHBoxLayout(widget_2);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(widget_2);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);


        horizontalLayout_2->addWidget(widget_2);

        widget_3 = new QWidget(widget);
        widget_3->setObjectName("widget_3");
        horizontalLayout_4 = new QHBoxLayout(widget_3);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_4 = new QLabel(widget_3);
        label_4->setObjectName("label_4");

        horizontalLayout_4->addWidget(label_4);


        horizontalLayout_2->addWidget(widget_3);


        verticalLayout->addWidget(widget);

        widget_4 = new QWidget(Form);
        widget_4->setObjectName("widget_4");
        horizontalLayout = new QHBoxLayout(widget_4);
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(widget_4);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        label_2 = new QLabel(widget_4);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 5);

        verticalLayout->addWidget(widget_4);

        verticalLayout->setStretch(1, 10);
        verticalLayout->setStretch(2, 1);

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        label_5->setText(QCoreApplication::translate("Form", "\346\243\200\346\265\213\346\226\271\346\241\210", nullptr));
        checkBox_6->setText(QCoreApplication::translate("Form", "\345\210\222\347\227\225", nullptr));
        checkBox_5->setText(QCoreApplication::translate("Form", "\350\243\202\347\272\271", nullptr));
        checkBox_4->setText(QCoreApplication::translate("Form", "\345\207\271\345\235\221", nullptr));
        checkBox_3->setText(QCoreApplication::translate("Form", "\346\257\233\345\210\272", nullptr));
        checkBox->setText(QCoreApplication::translate("Form", "\346\261\241\346\270\215", nullptr));
        checkBox_2->setText(QCoreApplication::translate("Form", "\347\274\272\346\226\231", nullptr));
        label_3->setText(QString());
        label_4->setText(QString());
        label->setText(QCoreApplication::translate("Form", "\347\212\266\346\200\201", nullptr));
        label_2->setText(QCoreApplication::translate("Form", "\347\274\272\351\231\267\346\225\260\351\207\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
