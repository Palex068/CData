#include "mainwindow.h"
#include "calculator.h"
#include "ui_mainwindow.h"

Calculator calc;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    calc.reset();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_but_0_clicked()
{
    calc.digit(0);
    ui->screen->setText(calc.india());
}
void MainWindow::on_but_1_clicked()
{
    calc.digit(1);
    ui->screen->setText(calc.india());
}
void MainWindow::on_but_2_clicked()
{
    calc.digit(2);
    ui->screen->setText(calc.india());
}
void MainWindow::on_but_3_clicked()
{
    calc.digit(3);
    ui->screen->setText(calc.india());
}
void MainWindow::on_but_4_clicked()
{
    calc.digit(4);
    ui->screen->setText(calc.india());
}
void MainWindow::on_but_5_clicked()
{
    calc.digit(5);
    ui->screen->setText(calc.india());
}
void MainWindow::on_but_6_clicked()
{
    calc.digit(6);
    ui->screen->setText(calc.india());
}
void MainWindow::on_but_7_clicked()
{
    calc.digit(7);
    ui->screen->setText(calc.india());
}
void MainWindow::on_but_8_clicked()
{
    calc.digit(8);
    ui->screen->setText(calc.india());
}
void MainWindow::on_but_9_clicked()
{
    calc.digit(9);
    ui->screen->setText(calc.india());
}

void MainWindow::on_but_c_clicked()
{
    calc.reset();
    ui->screen->setText(calc.india());
}
void MainWindow::on_but_a_clicked()
{
    calc.operation(1);
}
void MainWindow::on_but_s_clicked()
{
    calc.operation(2);
}
void MainWindow::on_but_m_clicked()
{
    calc.operation(3);
}
void MainWindow::on_but_d_clicked()
{
    calc.operation(4);
}

void MainWindow::on_but_e_clicked()
{
    calc.calculate();
    ui->screen->setText(calc.india());
}

