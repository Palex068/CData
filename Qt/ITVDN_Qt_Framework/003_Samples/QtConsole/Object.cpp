#include "Object.h"

#include <QDebug>

Object::Object(QString name, QObject* parent)
    : QObject(parent)
{
    setObjectName(name);
    qDebug() << "Constructor" << objectName();
}

Object::~Object()
{
    qDebug() << "Destructor" << objectName();
}

QString Object::getSomeProperty()
{
    qDebug() << "getting some property";
    return mSomeProperty;
}

void Object::setSomeProperty(QString str)
{
    qDebug() << "setting some property";
    mSomeProperty = str;
}

double Object::invokable(int intArgument, double doubleArgument)
{
    return intArgument * doubleArgument;
}

void Object::resetSomeProperty()
{
    mSomeProperty = "Cat";
}
