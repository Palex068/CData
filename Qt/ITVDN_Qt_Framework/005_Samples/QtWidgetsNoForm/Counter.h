#ifndef COUNTER_H
#define COUNTER_H

#include <QObject>

class Counter : public QObject
{
    Q_OBJECT
public:
    explicit Counter(int n, QObject *parent = nullptr);

signals:

public slots:
    void count();

private:
    int mN;
};

#endif // COUNTER_H
