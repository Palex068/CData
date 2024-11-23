#ifndef RECEIVER_H
#define RECEIVER_H

#include <QObject>

class Receiver : public QObject {
    Q_OBJECT
public:
    explicit Receiver(QObject* parent = nullptr);

signals:

public slots:
    void receiveMessage(QString message);
};

#endif // RECEIVER_H
