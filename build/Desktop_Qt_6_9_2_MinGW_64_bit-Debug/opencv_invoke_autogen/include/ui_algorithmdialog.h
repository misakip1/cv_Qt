/********************************************************************************
** Form generated from reading UI file 'algorithmdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALGORITHMDIALOG_H
#define UI_ALGORITHMDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AlgorithmDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *scuff;
    QCheckBox *scratch;
    QCheckBox *coatingScratch;
    QCheckBox *grindingMark;
    QCheckBox *coatingCrack;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *dirt;
    QCheckBox *whitePoint;
    QCheckBox *aluminumChip;
    QCheckBox *crater;
    QCheckBox *pushDamage;
    QCheckBox *bubble;
    QCheckBox *pit;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *colorDifference;
    QCheckBox *primerReturn;
    QCheckBox *exposedBase;
    QCheckBox *oil;
    QCheckBox *adhesion;
    QCheckBox *powderBump;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *orangePeel;
    QCheckBox *coarseTexture;
    QCheckBox *sprayFlow;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *groupBox_5;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *deformation;
    QCheckBox *dent;
    QCheckBox *hangerMark;
    QCheckBox *broken;
    QSpacerItem *horizontalSpacer_4;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AlgorithmDialog)
    {
        if (AlgorithmDialog->objectName().isEmpty())
            AlgorithmDialog->setObjectName("AlgorithmDialog");
        AlgorithmDialog->resize(650, 508);
        QFont font;
        font.setPointSize(11);
        AlgorithmDialog->setFont(font);
        AlgorithmDialog->setStyleSheet(QString::fromUtf8("\n"
"    QDialog {\n"
"        background-color: #F3E5F5;\n"
"        color: #4A148C;\n"
"    }\n"
"\n"
"    QWidget#centralWidget {\n"
"        background-color: #F3E5F5;\n"
"    }\n"
"\n"
"    QLabel {\n"
"        color: #4A148C;\n"
"    }\n"
"\n"
"    QCheckBox {\n"
"        color: #4A148C;\n"
"        spacing: 6px;\n"
"    }\n"
"\n"
"    QCheckBox::indicator {\n"
"        width: 16px;\n"
"        height: 16px;\n"
"        border: 1px solid #BA68C8;\n"
"        border-radius: 3px;\n"
"        background-color: #FFFFFF;\n"
"    }\n"
"\n"
"    QCheckBox::indicator:checked {\n"
"        background-color: #CE93D8;\n"
"        border: 1px solid #AB47BC;\n"
"    }\n"
"\n"
"    QPushButton {\n"
"        background-color: #CE93D8;\n"
"        color: #FFFFFF;\n"
"        border: none;\n"
"        border-radius: 4px;\n"
"        padding: 6px 16px;\n"
"    }\n"
"\n"
"    QPushButton:hover {\n"
"        background-color: #BA68C8;\n"
"    }\n"
"\n"
"    QPushButton:pressed {\n"
"        background-color: #9C27B0;\n"
"  "
                        "  }\n"
"\n"
"    QDialogButtonBox {\n"
"        background-color: #F3E5F5;\n"
"    }\n"
"\n"
"    QDialogButtonBox QPushButton {\n"
"        background-color: #CE93D8;\n"
"        color: #FFFFFF;\n"
"        border: none;\n"
"        border-radius: 4px;\n"
"        padding: 6px 16px;\n"
"    }\n"
"\n"
"    QDialogButtonBox QPushButton:hover {\n"
"        background-color: #BA68C8;\n"
"    }\n"
""));
        verticalLayout = new QVBoxLayout(AlgorithmDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(AlgorithmDialog);
        widget->setObjectName("widget");
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(widget);
        widget_2->setObjectName("widget_2");
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(294, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(widget_2);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(294, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addWidget(widget_2);

        groupBox = new QGroupBox(widget);
        groupBox->setObjectName("groupBox");
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        scuff = new QCheckBox(groupBox);
        scuff->setObjectName("scuff");

        horizontalLayout_2->addWidget(scuff);

        scratch = new QCheckBox(groupBox);
        scratch->setObjectName("scratch");

        horizontalLayout_2->addWidget(scratch);

        coatingScratch = new QCheckBox(groupBox);
        coatingScratch->setObjectName("coatingScratch");

        horizontalLayout_2->addWidget(coatingScratch);

        grindingMark = new QCheckBox(groupBox);
        grindingMark->setObjectName("grindingMark");

        horizontalLayout_2->addWidget(grindingMark);

        coatingCrack = new QCheckBox(groupBox);
        coatingCrack->setObjectName("coatingCrack");

        horizontalLayout_2->addWidget(coatingCrack);


        verticalLayout_2->addWidget(groupBox);

        groupBox_2 = new QGroupBox(widget);
        groupBox_2->setObjectName("groupBox_2");
        horizontalLayout_3 = new QHBoxLayout(groupBox_2);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        dirt = new QCheckBox(groupBox_2);
        dirt->setObjectName("dirt");

        horizontalLayout_3->addWidget(dirt);

        whitePoint = new QCheckBox(groupBox_2);
        whitePoint->setObjectName("whitePoint");

        horizontalLayout_3->addWidget(whitePoint);

        aluminumChip = new QCheckBox(groupBox_2);
        aluminumChip->setObjectName("aluminumChip");

        horizontalLayout_3->addWidget(aluminumChip);

        crater = new QCheckBox(groupBox_2);
        crater->setObjectName("crater");

        horizontalLayout_3->addWidget(crater);

        pushDamage = new QCheckBox(groupBox_2);
        pushDamage->setObjectName("pushDamage");

        horizontalLayout_3->addWidget(pushDamage);

        bubble = new QCheckBox(groupBox_2);
        bubble->setObjectName("bubble");

        horizontalLayout_3->addWidget(bubble);

        pit = new QCheckBox(groupBox_2);
        pit->setObjectName("pit");

        horizontalLayout_3->addWidget(pit);


        verticalLayout_2->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(widget);
        groupBox_3->setObjectName("groupBox_3");
        horizontalLayout_4 = new QHBoxLayout(groupBox_3);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        colorDifference = new QCheckBox(groupBox_3);
        colorDifference->setObjectName("colorDifference");

        horizontalLayout_4->addWidget(colorDifference);

        primerReturn = new QCheckBox(groupBox_3);
        primerReturn->setObjectName("primerReturn");

        horizontalLayout_4->addWidget(primerReturn);

        exposedBase = new QCheckBox(groupBox_3);
        exposedBase->setObjectName("exposedBase");

        horizontalLayout_4->addWidget(exposedBase);

        oil = new QCheckBox(groupBox_3);
        oil->setObjectName("oil");

        horizontalLayout_4->addWidget(oil);

        adhesion = new QCheckBox(groupBox_3);
        adhesion->setObjectName("adhesion");

        horizontalLayout_4->addWidget(adhesion);

        powderBump = new QCheckBox(groupBox_3);
        powderBump->setObjectName("powderBump");

        horizontalLayout_4->addWidget(powderBump);


        verticalLayout_2->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(widget);
        groupBox_4->setObjectName("groupBox_4");
        horizontalLayout_5 = new QHBoxLayout(groupBox_4);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        orangePeel = new QCheckBox(groupBox_4);
        orangePeel->setObjectName("orangePeel");

        horizontalLayout_5->addWidget(orangePeel);

        coarseTexture = new QCheckBox(groupBox_4);
        coarseTexture->setObjectName("coarseTexture");

        horizontalLayout_5->addWidget(coarseTexture);

        sprayFlow = new QCheckBox(groupBox_4);
        sprayFlow->setObjectName("sprayFlow");

        horizontalLayout_5->addWidget(sprayFlow);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 1);
        horizontalLayout_5->setStretch(2, 1);
        horizontalLayout_5->setStretch(3, 2);

        verticalLayout_2->addWidget(groupBox_4);

        groupBox_5 = new QGroupBox(widget);
        groupBox_5->setObjectName("groupBox_5");
        horizontalLayout_6 = new QHBoxLayout(groupBox_5);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        deformation = new QCheckBox(groupBox_5);
        deformation->setObjectName("deformation");

        horizontalLayout_6->addWidget(deformation);

        dent = new QCheckBox(groupBox_5);
        dent->setObjectName("dent");

        horizontalLayout_6->addWidget(dent);

        hangerMark = new QCheckBox(groupBox_5);
        hangerMark->setObjectName("hangerMark");

        horizontalLayout_6->addWidget(hangerMark);

        broken = new QCheckBox(groupBox_5);
        broken->setObjectName("broken");

        horizontalLayout_6->addWidget(broken);

        horizontalSpacer_4 = new QSpacerItem(212, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);

        horizontalLayout_6->setStretch(0, 1);
        horizontalLayout_6->setStretch(1, 1);
        horizontalLayout_6->setStretch(2, 1);
        horizontalLayout_6->setStretch(3, 1);
        horizontalLayout_6->setStretch(4, 2);

        verticalLayout_2->addWidget(groupBox_5);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 3);
        verticalLayout_2->setStretch(2, 3);
        verticalLayout_2->setStretch(3, 3);
        verticalLayout_2->setStretch(4, 3);
        verticalLayout_2->setStretch(5, 3);

        verticalLayout->addWidget(widget);

        buttonBox = new QDialogButtonBox(AlgorithmDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(AlgorithmDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, AlgorithmDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, AlgorithmDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AlgorithmDialog);
    } // setupUi

    void retranslateUi(QDialog *AlgorithmDialog)
    {
        AlgorithmDialog->setWindowTitle(QCoreApplication::translate("AlgorithmDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("AlgorithmDialog", "\346\243\200\346\265\213\346\226\271\346\241\210", nullptr));
        groupBox->setTitle(QCoreApplication::translate("AlgorithmDialog", "\345\244\226\350\247\202\345\210\222\344\274\244\347\261\273", nullptr));
        scuff->setText(QCoreApplication::translate("AlgorithmDialog", "\346\223\246\350\212\261", nullptr));
        scratch->setText(QCoreApplication::translate("AlgorithmDialog", "\345\210\222\344\274\244", nullptr));
        coatingScratch->setText(QCoreApplication::translate("AlgorithmDialog", "\345\226\267\346\266\202\345\210\222\344\274\244", nullptr));
        grindingMark->setText(QCoreApplication::translate("AlgorithmDialog", "\346\211\223\347\243\250\345\215\260", nullptr));
        coatingCrack->setText(QCoreApplication::translate("AlgorithmDialog", "\346\266\202\345\261\202\345\274\200\350\243\202", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("AlgorithmDialog", "\347\202\271\347\212\266 / \345\274\202\347\211\251\347\261\273", nullptr));
        dirt->setText(QCoreApplication::translate("AlgorithmDialog", "\350\204\217\347\202\271 ", nullptr));
        whitePoint->setText(QCoreApplication::translate("AlgorithmDialog", "\346\211\223\347\231\275\347\202\271", nullptr));
        aluminumChip->setText(QCoreApplication::translate("AlgorithmDialog", "\351\223\235\345\261\221", nullptr));
        crater->setText(QCoreApplication::translate("AlgorithmDialog", "\347\201\253\345\261\261\345\217\243 ", nullptr));
        pushDamage->setText(QCoreApplication::translate("AlgorithmDialog", " \346\216\250\344\274\244 ", nullptr));
        bubble->setText(QCoreApplication::translate("AlgorithmDialog", " \346\260\224\346\263\241 ", nullptr));
        pit->setText(QCoreApplication::translate("AlgorithmDialog", "\350\265\267\345\235\221   ", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("AlgorithmDialog", "\350\211\262\345\267\256 / \346\266\202\345\261\202\347\261\273", nullptr));
        colorDifference->setText(QCoreApplication::translate("AlgorithmDialog", "\346\235\202\350\211\262", nullptr));
        primerReturn->setText(QCoreApplication::translate("AlgorithmDialog", "\350\277\224\345\272\225", nullptr));
        exposedBase->setText(QCoreApplication::translate("AlgorithmDialog", "\346\274\217\345\272\225", nullptr));
        oil->setText(QCoreApplication::translate("AlgorithmDialog", "\346\262\271\345\215\260", nullptr));
        adhesion->setText(QCoreApplication::translate("AlgorithmDialog", "\347\262\230\346\216\245", nullptr));
        powderBump->setText(QCoreApplication::translate("AlgorithmDialog", "\345\207\270\347\262\211", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("AlgorithmDialog", "\350\241\250\351\235\242\347\272\271\347\220\206\347\261\273 ", nullptr));
        orangePeel->setText(QCoreApplication::translate("AlgorithmDialog", "\346\241\224\347\232\256  ", nullptr));
        coarseTexture->setText(QCoreApplication::translate("AlgorithmDialog", "\347\272\271\347\262\227", nullptr));
        sprayFlow->setText(QCoreApplication::translate("AlgorithmDialog", "\345\226\267\346\265\201", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("AlgorithmDialog", "\345\236\213\346\235\220\345\275\242\347\212\266\347\261\273", nullptr));
        deformation->setText(QCoreApplication::translate("AlgorithmDialog", "\345\217\230\345\275\242", nullptr));
        dent->setText(QCoreApplication::translate("AlgorithmDialog", "\347\242\260\345\207\271", nullptr));
        hangerMark->setText(QCoreApplication::translate("AlgorithmDialog", "\346\214\202\345\205\267\345\215\260", nullptr));
        broken->setText(QCoreApplication::translate("AlgorithmDialog", "\351\251\263\345\217\243 ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AlgorithmDialog: public Ui_AlgorithmDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALGORITHMDIALOG_H
