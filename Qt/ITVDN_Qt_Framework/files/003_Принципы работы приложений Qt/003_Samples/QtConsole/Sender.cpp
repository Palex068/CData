#include "Sender.h"

#include <QDebug>
#include <QTime>
#include <QTimerEvent>

Sender::Sender(int timeout, QObject* parent)
    : QObject(parent)
{
    qDebug() << "Sender with timeout: " << timeout;
    startTimer(timeout * 1000);
}

void Sender::timerEvent(QTimerEvent*)
{
    auto message = QTime::currentTime().toString();
    qDebug() << "Send: " << message;
    emit sendMessage(message);
}
