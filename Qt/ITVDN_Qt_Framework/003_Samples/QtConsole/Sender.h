#ifndef SENDER_H
#define SENDER_H

#include <QObject>

class Sender : public QObject {
    Q_OBJECT
public:
    explicit Sender(int timeout, QObject* parent = nullptr);

signals:
    void sendMessage(QString message);

public slots:

protected:
    void timerEvent(QTimerEvent*) override;
};

#endif // SENDER_H
