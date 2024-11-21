#include "dialog.h"

#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog) {
  ui->setupUi(this);
}

Dialog::~Dialog() { delete ui; }

void Dialog::on_buttonBox_accepted() {
  double x = 0;
  x = ui->lineEdit_xRot->text().toDouble();
  double y = 0;
  y = ui->lineEdit_yRot->text().toDouble();
  double z = 0;
  z = ui->lineEdit_zRot->text().toDouble();
  emit apply(x, y, z);
}
