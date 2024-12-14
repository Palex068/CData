#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet(
        "QPushButton {"
        "background-color: green;"
        "border-radius: 5px;"
        "color: white;"
        "font: 20px \"Impact\";"
        "}"
        "QPushButton:hover {background-color: #588102;}"
        "QPushButton:pressed {background—color: #809040;}");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buttonNext_clicked()
{
    f.show();
    f.setParams(ui->workInMonth->text().toDouble(), ui->salaryInMonth->text().toDouble());
    this->hide();
}
