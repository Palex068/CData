#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QThread>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void setLabelTextFromButton();
private:
    QLabel *mLabel;
    QThread *mCounterThread;
};

#endif // MAINWINDOW_H
