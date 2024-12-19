#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QPainter>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QTimer *timer_cycle;

    //размер планеты
    int planet_size;

    //насколько увеличивается шапка атмосферы
    int atmosphere_up_size;

    //скорость вращения планеты
    double speed_planet_rotation;

    //счетчик вращения планеты
    double planet_rotation = 0;

    //скорость вращения атмосферы
    double speed_atmosphere_rotation;

    //счетчик вращения атмосферы
    double atmosphere_rotation = 0;

    //звездный фон
    QImage star_background;

    //текстурная карта планеты
    QImage planet_texture;

    //маска альфа смешивания планеты
    QImage planet_alpha;

    //итоговый объект планеты
    QImage planet;

    //тень планеты
    QImage planet_shadow;

    //текстурная карта ночных огней городов
    QImage planet_lights_texture;

    //маска альфа-смешивания ночных огней городов
    QImage planet_lights_alpha;

    //итоговый объект ночных огней городов
    QImage planet_lights;

    //текстурная карта атмосферы
    QImage planet_atmosphere_texture;

    //маска альфа-смешивания атмосферы
    QImage planet_atmosphere_alpha;

    //итоговый объект атмосферы
    QImage planet_atmosphere;

private:
    Ui::MainWindow *ui;

private slots:
    void paintEvent(QPaintEvent *event);
    void cycle();
};
#endif // MAINWINDOW_H
