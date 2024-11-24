#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QFileSystemModel>
#include <QMessageBox>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    auto fyleSystemModel = new QFileSystemModel(this);
    fyleSystemModel->setRootPath(QDir::rootPath());
    fyleSystemModel->setReadOnly(false);

    ui->listView->setModel(fyleSystemModel);
    ui->listView->setRootIndex(fyleSystemModel->index(QDir::homePath()));

    ui->treeView->setModel(fyleSystemModel);
    ui->treeView->setSelectionModel(ui->listView->selectionModel());

    ui->tableView->setModel(fyleSystemModel);
    ui->tableView->setRootIndex(fyleSystemModel->index(QDir::homePath()));

    mDisplayWithTooltipModel = new DisplayWithTooltipListModel(this);
    ui->listView_2->setModel(mDisplayWithTooltipModel);
    ui->treeView_2->setModel(mDisplayWithTooltipModel);
    ui->tableView_2->setModel(mDisplayWithTooltipModel);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    auto text = mDisplayWithTooltipModel->index(1, 0, QModelIndex()).data().toString();
    mDisplayWithTooltipModel->addDisplayWithTooltip({ text, "Dog" });
}
