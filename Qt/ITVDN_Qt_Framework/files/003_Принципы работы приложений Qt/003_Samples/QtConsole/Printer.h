#ifndef PRINTER_H
#define PRINTER_H

#include <QObject>

class Printer : public QObject {
    Q_OBJECT
public:
    explicit Printer(unsigned long delay, QObject* parent = nullptr);

signals:

public slots:
    void print(QString text);

private:
    unsigned long mDelay;
};

#endif // PRINTER_H
