#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  loadSettings();
}

MainWindow::~MainWindow() {
  saveSettings();
  ui->widget->free_data();
  delete ui->widget;
  delete ui;
}

void MainWindow::on_open_button_clicked() {
  QString str;
  str = QFileDialog::getOpenFileName(this, "Open file", nullptr,
                                     "OBJ Image (*.obj)");
  if (!str.isEmpty()) {
    ui->file_name->setText(str);
    std::string file = str.toStdString();
    ui->widget->name_to_file = file.data();
    ui->widget->parseOBJ();
    default_settings();

    ui->count_point->setText(QString::number(ui->widget->number_of_vertices));
    ui->count_line->setText(QString::number(ui->widget->number_of_lines));
  }
}

void MainWindow::on_bg_color_clicked() {
  QColor new_bg_color = QColorDialog::getColor(Qt::white, this);
  if (new_bg_color.isValid()) {
    ui->widget->bg_color = new_bg_color;
    ui->widget->update();
  }
}

void MainWindow::on_line_color_clicked() {
  QColor new_line_color = QColorDialog::getColor(Qt::white, this);
  if (new_line_color.isValid()) {
    ui->widget->line_color = new_line_color;
    ui->widget->update();
  }
}

void MainWindow::on_point_color_clicked() {
  QColor new_point_color = QColorDialog::getColor(Qt::white, this);
  if (new_point_color.isValid()) {
    ui->widget->point_color = new_point_color;
    ui->widget->update();
  }
}
void MainWindow::shift_view(int new_pos, int ax) {
  double shifted;

  if (ax == 0) {
    shifted = (new_pos - slider_x_pos) / 30.0;
    slider_x_pos = new_pos;
  } else if (ax == 1) {
    shifted = (new_pos - slider_y_pos) / 30.0;
    slider_y_pos = new_pos;
  } else {
    shifted = (new_pos - slider_z_pos) / 30.0;
    slider_z_pos = new_pos;
  }

  ui->widget->shift_view(shifted, ax);
}

void MainWindow::scale_view(int new_scale) {
  double actual_new_scale = 0.2 + new_scale * 0.04;
  double actual_old_scale = 0.2 + scale * 0.04;

  scale = new_scale;

  ui->widget->scale_view(actual_new_scale / actual_old_scale);
}

void MainWindow::rotate_view(int new_degree, int ax) {
  double degrees;

  if (ax == 0) {
    degrees = (new_degree - slider_x_rot);
    slider_x_rot = new_degree;
  } else if (ax == 1) {
    degrees = (new_degree - slider_y_rot);
    slider_y_rot = new_degree;
  } else {
    degrees = (new_degree - slider_z_rot);
    slider_z_rot = new_degree;
  }

  ui->widget->rotate_view(degrees, ax);
}

void MainWindow::on_moov_x_valueChanged(int value) { shift_view(value, 0); }

void MainWindow::default_settings() {
  slider_x_pos = 0;
  ui->moov_x->setSliderPosition(0);

  slider_y_pos = 0;
  ui->moov_y->setSliderPosition(0);

  slider_z_pos = 0;
  ui->moov_z->setSliderPosition(0);

  slider_x_rot = 0;
  ui->rotate_x->setSliderPosition(180);

  slider_y_rot = 0;
  ui->rotate_y->setSliderPosition(180);

  slider_z_rot = 0;
  ui->rotate_z->setSliderPosition(180);

  scale = 50;
  ui->scale->setSliderPosition(50);
}

void MainWindow::on_moov_y_valueChanged(int value) { shift_view(value, 1); }

void MainWindow::on_moov_z_valueChanged(int value) { shift_view(value, 2); }

void MainWindow::on_scale_valueChanged(int value) { scale_view(value); }

void MainWindow::on_point_size_ui_valueChanged(int value) {
  ui->widget->point_size = value;
  ui->widget->update();
}

void MainWindow::on_point_type_ui_currentIndexChanged(int index) {
  ui->widget->point_type = index;
  ui->widget->update();
}

void MainWindow::on_thickness_valueChanged(int value) {
  ui->widget->line_size = value;
  ui->widget->update();
}

void MainWindow::on_line_type_ui_currentIndexChanged(int index) {
  ui->widget->line_type = index;
  ui->widget->update();
}

void MainWindow::saveSettings() {
  QSettings settings(QCoreApplication::applicationDirPath() + "/settings.ini",
                     QSettings::IniFormat);
  settings.beginGroup("Settings");
  settings.setValue("Line Type", ui->widget->line_type);
  settings.setValue("Point Color", ui->widget->point_color);
  settings.setValue("Bg Color", ui->widget->bg_color);
  settings.setValue("Line Color", ui->widget->line_color);
  settings.endGroup();
}

void MainWindow::loadSettings() {
  QSettings settings(QCoreApplication::applicationDirPath() + "/settings.ini",
                     QSettings::IniFormat);
  settings.beginGroup("Settings");
  ui->line_type_ui->setCurrentIndex(settings.value("Line Type", 0).toInt());
  ui->widget->line_type = settings.value("Line Type", 0).toInt();
  ui->widget->line_size = settings.value("Line Size", 50).toInt();
  ui->thickness->setValue(settings.value("Line Size", 50).toInt());
  ui->widget->line_color =
      settings.value("Line Color", QColor(Qt::black)).value<QColor>();
  ui->point_type_ui->setCurrentIndex(settings.value("Point Type", 0).toInt());
  ui->widget->point_type = settings.value("Poin Type", 0).toInt();
  ui->widget->point_size = settings.value("Poin Type", 50).toInt();
  ui->point_size_ui->setValue(settings.value("Point Type", 50).toInt());
  ui->widget->point_color =
      settings.value("Point Color", QColor(Qt::black)).value<QColor>();
  ui->widget->bg_color =
      settings.value("Bg Color", QColor(Qt::white)).value<QColor>();
  settings.endGroup();
}

void MainWindow::on_rotate_x_valueChanged(int value) { rotate_view(value, 0); }

void MainWindow::on_rotate_y_valueChanged(int value) { rotate_view(value, 1); }

void MainWindow::on_rotate_z_valueChanged(int value) { rotate_view(value, 2); }

void MainWindow::on_projection_currentIndexChanged(int index) {
  ui->widget->projection_type = index;
  ui->widget->update();
}

void MainWindow::on_screenshot_clicked() {
  QImage screenshot = ui->widget->grabFramebuffer();
  QString savePath = QFileDialog::getSaveFileName(this, tr("Save screenshot"),
                                                  nullptr, "Image (*.jpeg)");
  screenshot.save(savePath, "JPEG");
}
