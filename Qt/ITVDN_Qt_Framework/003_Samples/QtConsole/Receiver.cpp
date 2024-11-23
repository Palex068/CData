#include "Receiver.h"

#include <QDebug>

Receiver::Receiver(QObject* parent)
    : QObject(parent)
{
}

void Receiver::receiveMessage(QString message)
{
    qDebug() << "Receive: " << message;
}
