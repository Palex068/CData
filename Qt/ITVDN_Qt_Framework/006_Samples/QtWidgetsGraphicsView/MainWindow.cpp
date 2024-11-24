#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QGraphicsItem>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_scene = new QGraphicsScene({ 0, 0, 400, 400 }, this);
    m_scene->setBackgroundBrush(QBrush(Qt::white));

    ui->graphicsView->setScene(m_scene);
    ui->graphicsView->rotate(20);
    ui->graphicsView_2->setScene(m_scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAddRectangle_triggered()
{
    auto item = new QGraphicsRectItem(100, 100, 100, 100);
    item->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
    m_scene->addItem(item);
}
