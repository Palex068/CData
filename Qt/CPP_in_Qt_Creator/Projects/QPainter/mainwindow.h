#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

private:
    Ui::MainWindow *ui;
    QTimer *timer;

    int x = 100;
    int y = 77;
    int dirx = 1;
    int diry = 1;
    int rot = 10;

private slots:
    void paintEvent(QPaintEvent * event);
    void refresh();
};
#endif // MAINWINDOW_H
