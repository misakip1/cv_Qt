/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(300, 600);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(300, 600));
        MainWindow->setMaximumSize(QSize(300, 600));
        MainWindow->setStyleSheet(QString::fromUtf8("/* ========== \346\234\200\345\244\226\345\261\202\344\270\273\347\252\227\345\217\243 ========== */\n"
"#MainWindow {\n"
"    background: qlineargradient(\n"
"        x1: 0, y1: 0, x2: 0, y2: 1,\n"
"        stop: 0 #f8ecf7,\n"
"        stop: 1 #eadef7\n"
"    );\n"
"    border: none;\n"
"}\n"
"\n"
"/* QMainWindow \344\270\255\345\277\203\351\203\250\344\273\266\350\256\276\351\200\217\346\230\216\357\274\214\350\256\251\344\270\273\347\252\227\345\217\243\350\203\214\346\231\257\351\200\217\345\207\272\346\235\245 */\n"
"#MainWindow QWidget#centralWidget {\n"
"    background: transparent;\n"
"}\n"
"\n"
"/* ========== \347\231\273\345\275\225\345\215\241\347\211\207\345\256\271\345\231\250 ========== */\n"
"#Loding {\n"
"    background-color: rgba(255, 255, 255, 0.62);\n"
"    border-radius: 16px;\n"
"    border: 1px solid rgba(212, 188, 230, 0.5);\n"
"}\n"
"\n"
"/* ========== \351\200\232\347\224\250\346\240\207\347\255\276\346\226\207\345\255\227 ========== */\n"
"QLabel {\n"
"    color: #6b4a87;\n"
"    fon"
                        "t-size: 13px;\n"
"}\n"
"\n"
"/* ========== \345\244\264\345\203\217\345\233\276\347\211\207 ========== */\n"
"#icon {\n"
"    border-radius: 12px;\n"
"}\n"
"\n"
"/* ========== \350\241\250\345\215\225\345\214\272\345\237\237 ========== */\n"
"#widget_3 {\n"
"    background: transparent;\n"
"}\n"
"\n"
"/* ========== \350\276\223\345\205\245\346\241\206 ========== */\n"
"QLineEdit {\n"
"    background-color: rgba(255, 255, 255, 0.9);\n"
"    border: 1px solid #d4bce6;\n"
"    border-radius: 8px;\n"
"    padding: 7px 12px;\n"
"    color: #5a3d75;\n"
"    font-size: 13px;\n"
"    min-height: 22px;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border-color: #c48fdd;\n"
"    background-color: #ffffff;\n"
"    outline: none;\n"
"}\n"
"\n"
"QLineEdit::placeholder {\n"
"    color: #b39dc9;\n"
"}\n"
"\n"
"/* ========== \347\231\273\345\275\225\346\214\211\351\222\256 ========== */\n"
"QPushButton {\n"
"    background: qlineargradient(\n"
"        x1: 0, y1: 0, x2: 0, y2: 1,\n"
"        stop: 0 #dba8e8,\n"
"        stop: 1 #b"
                        "988da\n"
"    );\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 20px;\n"
"    font-size: 13px;\n"
"    font-weight: 500;\n"
"    min-height: 24px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background: qlineargradient(\n"
"        x1: 0, y1: 0, x2: 0, y2: 1,\n"
"        stop: 0 #e2b3ed,\n"
"        stop: 1 #c395e0\n"
"    );\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background: qlineargradient(\n"
"        x1: 0, y1: 0, x2: 0, y2: 1,\n"
"        stop: 0 #c995d9,\n"
"        stop: 1 #ab79cc\n"
"    );\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 300, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
