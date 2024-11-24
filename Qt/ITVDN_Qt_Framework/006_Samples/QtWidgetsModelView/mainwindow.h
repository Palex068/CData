#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "DisplayWithTooltipListModel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    DisplayWithTooltipListModel* mDisplayWithTooltipModel;
    Ui::MainWindow* ui;
};

#endif // MAINWINDOW_H
