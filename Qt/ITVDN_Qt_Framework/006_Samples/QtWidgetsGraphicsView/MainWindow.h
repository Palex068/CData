#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsScene>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionAddRectangle_triggered();

private:
    Ui::MainWindow* ui;
    QGraphicsScene* m_scene;
};

#endif // MAINWINDOW_H
