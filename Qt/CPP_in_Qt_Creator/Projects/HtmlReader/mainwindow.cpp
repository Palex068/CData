#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QFileDialog>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    // В четвертом параметре можно задать фильтры вида файлов в диалоге
    QString path = QFileDialog::getOpenFileName(0, "Открыть html файл", "", "*.html *.htm");
    QFile document(path);
    QString data;

    if ((document.exists())&&(document.open(QIODevice::ReadOnly))) {
        data = document.readAll();
        // вывод в TextBrowser
        ui->textBrowser->setText(data);
        // вывод в TextEdit
        ui->textEdit->setPlainText(data);
        // установим TextEdit запрет на редактирование
        ui->textEdit->setReadOnly(true);
        document.close();
    };
}

