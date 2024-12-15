#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPainter>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer;

    connect(timer, SIGNAL(timeout()), this, SLOT(refresh()));
    timer->start(10);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPen pen;
    // QPen pen2;
    QBrush brush;

    // pen.setColor(Qt::red);
    // pen.setWidth(10);
    // pen.setStyle(Qt::DotLine);
    // pen.setCapStyle(Qt::RoundCap);
    // pen.setJoinStyle(Qt::MiterJoin);

    // brush.setColor(Qt::blue);
    // brush.setStyle(Qt::SolidPattern);

    // painter.setPen(pen);
    // painter.setBrush(brush);
    // painter.setViewport(ui->screen->geometry().x(), ui->screen->geometry().y(),
    //                     ui->screen->geometry().width(), ui->screen->geometry().height());

    // pen2.setColor(Qt::green);
    // pen2.setWidth(10);

    // painter.drawLine(0, 0, 500, 500);
    // painter.drawRect(400, 50, 300, 300);

    // painter.setPen(pen2);
    // painter.drawRect(50, 400, 200, 200);

    // painter.drawRect(x, y, 200, 200);

    //нарисуем круг частично перекрывающий квадрат с заливкой желтого цвета и окружностью черного, при этом половинной прозрачности
    pen.setColor(QColor(0,0,0,127));
    pen.setWidth(3);
    // brush.setColor(QColor(255,255,0,127));
    // brush.setStyle(Qt::SolidPattern);

    //применим настройки кисти для пэйнтера
    // painter.setBrush(brush);
    // painter.setPen(pen);
    // painter.drawEllipse(50,50,100,100);

    //нарисуем многоугольник, в виде подобия стрелки, красного цвета заливки и черными контурами и развернем его на 30 градусов по часовой стрелке
    pen.setColor(QColor(0,0,0));
    pen.setWidth(1);
    brush.setColor(QColor(255,0,0));
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);
    painter.setPen(pen);

    //зададим точки стрелки
    QPolygon polygon;
    // polygon.push_back(QPoint( 50,50));
    // polygon.push_back(QPoint(0,-50));
    polygon.push_back(QPoint(50,50));
    polygon.push_back(QPoint(0,0));

    //сохраним параметры сцены
    // painter.save();

    //сместим центр координат на свободное место
    painter.translate(200,200);

    // //повернем сцену
    painter.rotate(rot);

    //отрисуем стрелку
    painter.drawPolygon(polygon);

    //восстановим состояние сцены
    // painter.restore();

}

void MainWindow::refresh()
{
    if ((x + 200) >= ui->screen->geometry().width()) dirx = -1;

    if (x < ui->screen->geometry().x()) dirx = 1;

    if ((y + 200) >= ui->screen->geometry().height()) diry = -1;

    if (y < ui->screen->geometry().y()) diry = 1;


    x += dirx;
    y += diry;

    rot = (rot + 1) % 360;

    update();
}
