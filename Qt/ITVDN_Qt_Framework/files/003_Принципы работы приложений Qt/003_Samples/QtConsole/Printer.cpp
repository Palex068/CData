#include "Printer.h"

#include <QDebug>
#include <QThread>

Printer::Printer(unsigned long delay, QObject* parent)
    : QObject(parent)
    , mDelay(delay)
{
    qDebug() << "Printer with timeout: " << delay;
}

void Printer::print(QString text)
{
    qDebug() << "Printing... in thread: " << QThread::currentThreadId();
    QThread::sleep(mDelay);
    qDebug() << "Printed:" << text;
}
