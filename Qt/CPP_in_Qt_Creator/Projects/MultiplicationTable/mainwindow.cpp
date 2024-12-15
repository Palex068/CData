#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // установим количество строк в таблице
    ui->tableWidget->setRowCount(10);

    // установим количество столбцов в таблице
    ui->tableWidget->setColumnCount(10);

    // спрячем заголовки по умолчанию (мы сделаем свои в одном стиле)
    ui->tableWidget->horizontalHeader()->hide();

    // цикл обхода столбцов
    for (int cnt_col = 0; cnt_col < ui->tableWidget->columnCount(); cnt_col++) {

        // цикл обхода строк
        for (int cnt_row = 0; cnt_row < ui->tableWidget->rowCount(); cnt_row++) {

            // инициализируем новую ячейку
            ui->tableWidget->setItem(cnt_row, cnt_col, new QTableWidgetItem(0));

            // установим форматирование вывода по центру ячейки, для красоты
            ui->tableWidget->item(cnt_row, cnt_col)->setTextAlignment(Qt::AlignCenter);

            // если ячейка нулевой строки или колонки, то оформить как шапку
            if (cnt_row == 0 or cnt_col == 0) {
                ui->tableWidget->item(cnt_row, cnt_col)->setBackground(QBrush(Qt::lightGray));

                // заполняем шапку строк
                if (cnt_col != 0) {
                    ui->tableWidget->item(cnt_row, cnt_col)->setText(QString::number(cnt_col));
                }
                // заполняем шапку колонок
                if (cnt_row != 0) {
                    ui->tableWidget->item(cnt_row, cnt_col)->setText(QString::number(cnt_row));
                }
            } else {

                // ячейки для значений
                ui->tableWidget->item(cnt_row, cnt_col)->setText(QString::number(cnt_row * cnt_col));
            };
        };
    };
}

MainWindow::~MainWindow()
{
    delete ui;
}
