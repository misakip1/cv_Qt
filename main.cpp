#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include<QIcon>

int main(int argc, char *argv[])
{
    cv::setUseOptimized(false);
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "opencv_invoke_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    MainWindow w;
    w.setWindowIcon(QIcon("E:\\Qt_projet\\opencv_invoke\\logo.png"));
    w.setWindowTitle("yonyon");
    w.show();
    return a.exec();
}
