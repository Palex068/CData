#include <QCoreApplication>

#include "Object.h"
#include "Printer.h"
#include "Receiver.h"
#include "Sender.h"
#include <QDebug>
#include <QMetaMethod>
#include <QMetaObject>
#include <QThread>
#include <QtConcurrent>
#include <algorithm>
#include <iostream>

class MyFunctor {
public:
    void operator()(const QString& message)
    {
        qDebug() << "Receive in functor: " << message;
    }
};

int loopFunction(int n)
{
    for (int i = 0; i < n; ++i) {
        qDebug() << i;
        QThread::sleep(1);
    }
    return n * n;
}

void objectsHiearchy()
{
    Object parent("parent1");
    auto child1 = new Object("child1", &parent);
    qDebug() << "child1->parent()" << child1->parent();
    new Object("child2", &parent);
    new Object("child3", &parent);
}

void typeInformation()
{
    Object object("test");
    qDebug() << object.metaObject()->className();
    qDebug() << object.inherits("QObject");
    qDebug() << object.inherits("QLable");
    qDebug() << qobject_cast<QThread*>(&object);
    qDebug() << qobject_cast<QObject*>(&object);
}

void properties()
{
    Object test("test");
    qDebug() << test.property("someProperty");
    test.setProperty("someProperty", "dog");
    qDebug() << test.property("someProperty");
}

void invokable()
{
    Object test("test");
    double ret;
    QMetaObject::invokeMethod(&test, "invokable", Qt::DirectConnection,
        Q_RETURN_ARG(double, ret), Q_ARG(int, 9),
        Q_ARG(double, 0.5));
    qDebug() << ret;
    auto method = test.metaObject()->method(
        test.metaObject()->indexOfMethod("invokable(int,double)"));
    qDebug() << method.parameterTypes();
    qDebug() << method.parameterNames();
}

int signalsSlots(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);

    Receiver r;
    auto s = new Sender(2, &r);
    QObject::connect(s, &Sender::sendMessage, &r, &Receiver::receiveMessage);
    QObject::connect(s, &Sender::sendMessage, MyFunctor());
    QObject::connect(s, &Sender::sendMessage, [](QString message) {
        qDebug() << "Receive in lyambda: " << message;
    });
    QObject::connect(s, &Sender::sendMessage,
        []() { qDebug() << "Receive in lyambda"; });
    //    QObject::connect(s, &Sender::sendMessage, [](QString message, int id) { qDebug() << "Receive in lyambda: " << message; });
    a.exec();
}

int threads(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << "Current thread: " << QThread::currentThreadId();
    Printer pr(6);
    QThread th;
    pr.moveToThread(&th);
    th.start();
    Sender sr(2);
    //    QObject::connect(&sr, &Sender::sendMessage, &pr, &Printer::print);
    QObject::connect(&sr, &Sender::sendMessage, &pr, &Printer::print,
        Qt::DirectConnection);

    return a.exec();
}

class LoopTask : public QRunnable {
    void run() override
    {
        loopFunction(5);
    }
};

void threadPool()
{
    QThreadPool::globalInstance()->start(new LoopTask);
    loopFunction(3);
}

void concurency()
{
    auto future = QtConcurrent::run(loopFunction, 4);
    qDebug() << "future.result()" << future.result();
    loopFunction(6);
}

void containers()
{
    QList<int> intQList { 3, 4, 5, 1, 2, 3, 4, 4, 1, 1 };
    auto stdIntList = intQList.toStdList();
    qDebug() << stdIntList;
    std::sort(intQList.begin(), intQList.end());
    qDebug() << intQList;
    qDebug() << stdIntList;

    QListIterator<int> javaIter(intQList);
    while (javaIter.hasNext())
        qDebug() << javaIter.next();
}

int main(int argc, char* argv[])
{
    //    objectsHiearchy();
    //    typeInformation();
    //    properties();
    //    invokable();

    //    return signalsSlots(argc, argv);

    //    return threads(argc, argv);
    //    threadPool();
    /*    concurency()*/;

    containers();
}
