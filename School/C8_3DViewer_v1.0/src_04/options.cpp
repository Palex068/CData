#include "options.h"

#include "mainwindow.h"
#include "ui_options.h"

options::options(QWidget *parent) : QDialog(parent), ui(new Ui::options) {
  settings = new QSettings("3Danger_Masters", "3DViewer_v1", this);
  loadSettings();
  ui->setupUi(this);
}

options::~options() { delete ui; }

void options::saveSettings() {
  // задаем значения(имя настройки, значение)
  settings->setValue("projection_type", projection_type);
  settings->setValue("edge_type", edge_type);
  settings->setValue("vertex_type", vertex_type);
  settings->setValue("edge_color_red", edge_color[0]);
  settings->setValue("edge_color_green", edge_color[1]);
  settings->setValue("edge_color_blue", edge_color[2]);
  settings->setValue("edge_color_alpha", edge_color[3]);
  settings->setValue("vertex_color_red", vertex_color[0]);
  settings->setValue("vertex_color_green", vertex_color[1]);
  settings->setValue("vertex_color_blue", vertex_color[2]);
  settings->setValue("vertex_color_alpha", vertex_color[3]);
  settings->setValue("background_color_red", background_color[0]);
  settings->setValue("background_color_green", background_color[1]);
  settings->setValue("background_color_blue", background_color[2]);
  settings->setValue("background_color_alpha", background_color[3]);
  settings->setValue("edge_width", edge_width);
  settings->setValue("vertex_width", vertex_width);
}

void options::loadSettings() {
  // выгружаем значения(имя настройки, значение по умолчанию(если не задано))
  projection_type = settings->value("projection_type", 0).toInt();
  edge_type = settings->value("edge_type", 0).toInt();
  vertex_type = settings->value("vertex_type", 0).toInt();
  background_color[0] = settings->value("background_color_red", 0.0).toFloat();
  background_color[1] =
      settings->value("background_color_green", 0.0).toFloat();
  background_color[2] = settings->value("background_color_blue", 0.0).toFloat();
  background_color[3] =
      settings->value("background_color_alpha", 1.0).toFloat();
  edge_color[0] = settings->value("edge_color_red", 255.0).toFloat();
  edge_color[1] = settings->value("edge_color_green", 255.0).toFloat();
  edge_color[2] = settings->value("edge_color_blue", 255.0).toFloat();
  edge_color[3] = settings->value("edge_color_alpha", 1.0).toFloat();
  vertex_color[0] = settings->value("vertex_color_red", 0.0).toFloat();
  vertex_color[1] = settings->value("vertex_color_green", 255.0).toFloat();
  vertex_color[2] = settings->value("vertex_color_blue", 0.0).toFloat();
  vertex_color[3] = settings->value("vertex_color_alpha", 1.0).toFloat();
  edge_width = settings->value("edge_width", 1.0).toFloat();
  vertex_width = settings->value("vertex_width", 1.0).toFloat();
}

void options::on_button_apply_clicked() {
  saveSettings();
  QWidget::close();
}

void options::on_button_cancel_clicked() { QWidget::close(); }

void options::on_button_background_clicked() {
  QColor color = QColorDialog::getColor(Qt::white, this, tr("Select Color"));
  background_color[0] = color.redF();
  background_color[1] = color.greenF();
  background_color[2] = color.blueF();
  background_color[3] = color.alphaF();
  QString s("background: rgb(" + QString::number(color.redF() * 255) + "," +
            QString::number(color.greenF() * 255) + "," +
            QString::number(color.blueF() * 255) + ")");
  ui->button_background->setStyleSheet(s);
}

void options::on_button_color_vertexes_clicked() {
  QColor color = QColorDialog::getColor(Qt::white, this, tr("Select Color"));
  vertex_color[0] = color.redF();
  vertex_color[1] = color.greenF();
  vertex_color[2] = color.blueF();
  vertex_color[3] = color.alphaF();
  QString s("background: rgb(" + QString::number(color.redF() * 255) + "," +
            QString::number(color.greenF() * 255) + "," +
            QString::number(color.blueF() * 255) + ")");
  ui->button_color_vertexes->setStyleSheet(s);
}

void options::on_button_color_edges_clicked() {
  QColor color = QColorDialog::getColor(Qt::white, this, tr("Select Color"));
  edge_color[0] = color.redF();
  edge_color[1] = color.greenF();
  edge_color[2] = color.blueF();
  edge_color[3] = color.alphaF();
  QString s("background: rgb(" + QString::number(color.redF() * 255) + "," +
            QString::number(color.greenF() * 255) + "," +
            QString::number(color.blueF() * 255) + ")");
  ui->button_color_edges->setStyleSheet(s);
}

void options::on_horizontalSlider_size_vertexes_sliderMoved(int position) {
  vertex_width = position;
}
void options::on_horizontalSlider_wigth_edges_sliderMoved(int position) {
  edge_width = position;
}

void options::on_radioButton_solid_clicked() { edge_type = 0; }
void options::on_radioButton_dashed_clicked() { edge_type = 1; }

void options::on_radioButton_vertex_shere_clicked() { vertex_type = 1; }
void options::on_radioButton_vertex_cube_clicked() { vertex_type = 2; }
void options::on_radioButton_vertex_nope_clicked() { vertex_type = 0; }

void options::on_radioButton_central_clicked() { projection_type = 1; }
void options::on_radioButton_parallel_clicked() { projection_type = 0; }
