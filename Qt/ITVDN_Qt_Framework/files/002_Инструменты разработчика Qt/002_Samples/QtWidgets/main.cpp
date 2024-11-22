#include "MainWindow.h"
#include <QApplication>

#include <QDebug>
#include <QTranslator>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    translator.load(":/QtWidgets_uk.qm");
    a.installTranslator(&translator);

    MainWindow w;
    w.show();

    return a.exec();
}
