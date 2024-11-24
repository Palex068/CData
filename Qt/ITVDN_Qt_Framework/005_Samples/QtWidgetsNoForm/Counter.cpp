#include "Counter.h"
#include <QDebug>
#include <QThread>

Counter::Counter(int n, QObject* parent)
    : QObject(parent)
    , mN(n)
{
}

void Counter::count()
{
    for (int i = 0; i < mN; ++i) {
        qDebug() << i;
        QThread::sleep(1);
    }
}
