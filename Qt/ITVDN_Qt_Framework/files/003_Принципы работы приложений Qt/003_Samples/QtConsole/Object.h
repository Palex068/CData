#ifndef OBJECT_H
#define OBJECT_H

#include <QObject>

class Object : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString someProperty READ getSomeProperty WRITE setSomeProperty NOTIFY propertyChanged)
public:
    explicit Object(QString name, QObject* parent = nullptr);
    ~Object();

    QString getSomeProperty();
    void setSomeProperty(QString str);

    Q_INVOKABLE double invokable(int intArgument, double doubleArgument = 0.1);

signals:
    void propertyChanged(QString someProperty);

public slots:

private:
    QString mSomeProperty;

    void resetSomeProperty();
};

#endif // OBJECT_H
