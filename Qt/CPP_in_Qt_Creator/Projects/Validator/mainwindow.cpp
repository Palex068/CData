#include <QDoubleValidator>
#include <QValidator>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setValidator(new QDoubleValidator(-100, 100, 1000, ui->lineEdit));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    int i = 0;
    QString str = arg1;
    QDoubleValidator *val = (QDoubleValidator *) ui->lineEdit->validator();
    QValidator::State st = val->validate(str, i);
    if (st == QValidator::Acceptable) { //правильное число
        ui->label->setText(str);
    } else { //неправильное число
        ui->label->setText("Ошибка ввода числа с плавающей запятой, на позиции " + QString::number(i) );
    };
}

