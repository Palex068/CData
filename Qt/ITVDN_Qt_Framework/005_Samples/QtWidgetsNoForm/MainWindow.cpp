#include "MainWindow.h"
#include <QDebug>
#include <QLabel>
#include <QPushButton>

#include <Counter.h>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    resize(600, 400);

    auto roorWidget = new QWidget();
    setCentralWidget(roorWidget);

    mLabel = new QLabel("Label Label Label Label", roorWidget);
    mLabel->move(0, 10);
    auto worldButton = new QPushButton("World", roorWidget);
    worldButton->move(50, 50);

    auto helloButton = new QPushButton("Hello", roorWidget);
    helloButton->move(100, 100);

    auto someWidget = new QWidget(roorWidget);
    someWidget->move(150, 150);
    auto childLabel = new QLabel("Child", someWidget);
    childLabel->move(10, 10);
    qDebug() << "childLabel->pos()" << childLabel->pos();
    qDebug() << "childLabel->mapToGlobal({0,0})" << childLabel->mapToGlobal({ 0, 0 });

    connect(worldButton, &QPushButton::clicked, [this]() { mLabel->setText("World"); });
    connect(helloButton, &QPushButton::clicked, this, &MainWindow::setLabelTextFromButton);

    auto counter = new Counter(10);
    mCounterThread = new QThread(this);
    counter->moveToThread(mCounterThread);
    connect(worldButton, &QPushButton::clicked, counter, &Counter::count);
    mCounterThread->start();
}

MainWindow::~MainWindow()
{
    mCounterThread->quit();
    mCounterThread->wait();
}

void MainWindow::setLabelTextFromButton()
{
    auto button = qobject_cast<QPushButton*>(QObject::sender());
    mLabel->setText(button->text());
}
