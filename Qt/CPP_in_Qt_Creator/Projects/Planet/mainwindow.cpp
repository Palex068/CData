#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QImage>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // установим значения параметров отображения
    speed_planet_rotation = 2.5; //< скорость вращения планеты
    speed_atmosphere_rotation = 2.9; // <скорость вращения атмосферы планеты
    planet_size = 400; //< размер планеты, диаметр
    atmosphere_up_size = 6; //<увеличение диаметра под шапку атмосферы

    // загрузка звездного фона
    star_background.load("../../img/star_background.jpg");

    // загрузка текстурной карты планеты
    planet_texture.load("../../img/planet_texture.png");

    // загрузка маски альфа-смешивания планеты
    planet_alpha.load("../../img/planet_alpha.png");

    // масштабируем маску альфа-смешивания планеты под заданный размер планеты
    planet_alpha = planet_alpha.scaled(planet_size, planet_size, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    // загрузка тени планеты
    planet_shadow.load("../../img/planet_shadow.png");

    // масштабируем тень планеты под заданный размер планеты
    planet_shadow = planet_shadow.scaled(planet_size, planet_size, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    // загрузка текстурной карты ночных огней городов
    planet_lights_texture.load("../../img/planet_lights_texture.png");

    // масштабируем текстурную карту ночных огней городов под размер текстурной карты планеты
    planet_lights_texture=planet_lights_texture.scaled(planet_texture.width(),planet_texture.height() , Qt::IgnoreAspectRatio,Qt::SmoothTransformation);

    // загрузка маски альфа-смешивания ночных огней городов
    planet_lights_alpha.load("../../img/planet_lights_alpha.png");

    // масштабируем маску альфа-смешивания ночных огней городов под заданный размер планеты
    planet_lights_alpha=planet_lights_alpha.scaled(planet_size,planet_size,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);

    // загрузка текстурной карты атмосферы
    planet_atmosphere_texture.load("../../img/planet_atmosphere_texture.png");

    // масштабируем текстурную карту атмосферы под заданный размер текстурной карты планеты
    planet_atmosphere_texture=planet_atmosphere_texture.scaled(planet_texture.width(),planet_texture.height(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation);

    // загрузка маски альфа-смешивания атмосферы
    planet_atmosphere_alpha.load("../../img/planet_atmosphere_alpha.png");

    // масштабируем маску альфа смешивания атмосферы под заданный размер планеты + увеличенный размер шапки атмосферы
    planet_atmosphere_alpha = planet_atmosphere_alpha.scaled(planet_size+atmosphere_up_size*2, planet_size+atmosphere_up_size*2,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);

    // инициализация объекта таймера
    timer_cycle = new QTimer();

    // соединим сигнал таймера со слотом обновления экрана
    connect(timer_cycle, SIGNAL(timeout()), this, SLOT(cycle()));

    // запустим таймер
    timer_cycle->start(20);
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    // установим границы отображения для рисовальщика
    painter.setViewport(ui->screen->geometry().x(), ui->screen->geometry().y(), ui->screen->geometry().width(), ui->screen->geometry().height());

    // масштабируем звездный фон
    star_background=star_background.scaled(ui->screen->geometry().width(), ui->screen->geometry().height(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation);

    // и выведем его на экран
    painter.drawImage(0, 0, star_background);

    // запомним состояние сцены
    painter.save();

    // сместим начало координат сцены к центру виджета screen
    painter.translate(ui->screen->geometry().width()/2, ui->screen->geometry().height()/2);

    // выводим изображение планеты
    painter.drawImage(- planet_size / 2, - planet_size / 2, planet);

    // вывод атмосферы
    painter.drawImage(-(planet_size + atmosphere_up_size)/2,- (planet_size + atmosphere_up_size) / 2, planet_atmosphere);

    // вывод тени планеты
    painter.drawImage(- planet_size/2,- planet_size/2,planet_shadow);

    //вывод ночных огней
    painter.drawImage(- planet_size/2,- planet_size/2,planet_lights);

    //восстановим состояние сцены
    painter.restore();
}

void MainWindow::cycle()
{
    // копирование участка текстуры в соответствии с позицией счетчика вращения планеты
    planet = planet_texture.copy(planet_rotation, 0, planet_texture.height(), planet_texture.height());

    // масштабируем итоговое изображение планеты до заданного размера
    planet = planet.scaled(planet_size, planet_size, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    // копирование участка текстуры огней городов в соответствии с позицией счетчика вращения планеты
    planet_lights = planet_lights_texture.copy(planet_rotation, 0, planet_lights_texture.height(), planet_lights_texture.height());

    // масштабируем итоговое изображение огней городов до заданного размера планеты
    planet_lights = planet_lights.scaled(planet_size,planet_size,Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    // копирование участка текстуры атмосферы в соответствии с позицией счетчика вращения атмосферы
    planet_atmosphere = planet_atmosphere_texture.copy(atmosphere_rotation, 0, planet_atmosphere_texture.height(), planet_atmosphere_texture.height());

    // масштабируем итоговое изображение атмосферы до заданного размера планеты + увеличение размера на размер шапки атмосферы
    planet_atmosphere = planet_atmosphere.scaled(planet_size+atmosphere_up_size*2,planet_size + atmosphere_up_size*2,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);

    // инициализируем рисовальщик для преобразования итогового изображения планеты
    QPainter painter(&planet);

    // установим режим композиции альфа-смешивания - прозрачный цвет альфа-маски скопируется  на итоговое изображение
    painter.setCompositionMode(QPainter::CompositionMode_DestinationIn);

    // отрисовка в объект итогового изображения планеты альфа маски
    painter.drawImage(0, 0, planet_alpha);

    // инициализируем рисовальщик для преобразования итогового изображения ночных огней планеты
    QPainter painter2(&planet_lights);

    // установим режим композиции альфа-смешивания - прозрачный цвет альфа-маски скопируется на итоговое изображение
    painter2.setCompositionMode(QPainter::CompositionMode_DestinationIn);

    // отрисовка в объект итогового изображения огней планеты альфа маски
    painter2.drawImage(0, 0, planet_lights_alpha);

    // инициализируем рисовальщик для преобразования итогового изображения атмосферы планеты
    QPainter painter3(&planet_atmosphere);

    // установим режим композиции альфа-смешивания - прозрачный цвет альфа-маски скопируется на итоговое изображение
    painter3.setCompositionMode(QPainter::CompositionMode_DestinationIn);

    // отрисовка в объект итогового изображения атмосферы планеты альфа маски
    painter3.drawImage(0, 0, planet_atmosphere_alpha);

    // увеличим счетчик вращения планеты на величину скорости
    planet_rotation += speed_planet_rotation;

    // если значение счетчика выходит за рамки размера текстуры то обнулить счетчик
    if (planet_rotation+planet_texture.height() >= planet_texture.width()) planet_rotation = 0;

    // увеличим счетчик вращения атмосферы планеты на величину скорости
    atmosphere_rotation += speed_atmosphere_rotation;

    // если значение счетчика выходит за рамки размера текстуры то обнулить счетчик
    if (atmosphere_rotation+planet_atmosphere_texture.height() >= planet_atmosphere_texture.width()) atmosphere_rotation = 0;

    // обновим экран
    update();
}
