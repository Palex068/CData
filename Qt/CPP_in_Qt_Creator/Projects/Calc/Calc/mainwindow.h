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

private slots:
    void on_but_0_clicked();

    void on_but_1_clicked();

    void on_but_2_clicked();

    void on_but_3_clicked();

    void on_but_4_clicked();

    void on_but_5_clicked();

    void on_but_6_clicked();

    void on_but_7_clicked();

    void on_but_8_clicked();

    void on_but_9_clicked();

    void on_but_c_clicked();

    void on_but_a_clicked();

    void on_but_s_clicked();

    void on_but_m_clicked();

    void on_but_d_clicked();

    void on_but_e_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
