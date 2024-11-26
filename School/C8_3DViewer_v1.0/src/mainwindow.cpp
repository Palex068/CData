#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      _timer(new QTimer),
      _gif(nullptr) {
  ui->setupUi(this);

  connect(_timer, SIGNAL(timeout()), this, SLOT(takeFrame()));
  settings = new QSettings("3Danger_Masters", "3DViewer_v1", this);
  load_Settings();
}

MainWindow::~MainWindow() {
  delete ui;
  delete _timer;
}

void MainWindow::load_Settings() {
  // выгружаем значения(имя настройки, значение по умолчанию(если не задано))
  ui->widget->projection_type = settings->value("projection_type", 0).toInt();
  ui->widget->edge_type = settings->value("edge_type", 0).toInt();
  ui->widget->vertex_type = settings->value("vertex_type", 0).toInt();
  ui->widget->background_color[0] =
      settings->value("background_color_red", 0.0).toFloat();
  ui->widget->background_color[1] =
      settings->value("background_color_green", 0.0).toFloat();
  ui->widget->background_color[2] =
      settings->value("background_color_blue", 0.0).toFloat();
  ui->widget->background_color[3] =
      settings->value("background_color_alpha", 1.0).toFloat();
  ui->widget->edge_color[0] =
      settings->value("edge_color_red", 255.0).toFloat();
  ui->widget->edge_color[1] =
      settings->value("edge_color_green", 255.0).toFloat();
  ui->widget->edge_color[2] =
      settings->value("edge_color_blue", 255.0).toFloat();
  ui->widget->edge_color[3] =
      settings->value("edge_color_alpha", 1.0).toFloat();
  ui->widget->vertex_color[0] =
      settings->value("vertex_color_red", 0.0).toFloat();
  ui->widget->vertex_color[1] =
      settings->value("vertex_color_green", 255.0).toFloat();
  ui->widget->vertex_color[2] =
      settings->value("vertex_color_blue", 0.0).toFloat();
  ui->widget->vertex_color[3] =
      settings->value("vertex_color_alpha", 1.0).toFloat();
  ui->widget->edge_width = settings->value("edge_width", 1.0).toFloat();
  ui->widget->vertex_width = settings->value("vertex_width", 1.0).toFloat();
}

void MainWindow::on_actionClose_triggered() { close(); }

void MainWindow::on_button_open_path_clicked() {
  __buffpath = QFileDialog::getOpenFileName(this, tr("Open File"), "/",
                                            tr("Objects Files (*.obj)"));
  ui->label_path->setText(__buffpath);
  QByteArray ba = __buffpath.toLocal8Bit();  // convert Qstring->char *;
  char *filename = ba.data();                // convert Qstring->char *;
  remove_object_t(&ui->widget->object);
  if (!parsing_object_t(&ui->widget->object, filename)) {
    centralize_object_t(&ui->widget->object);
    double getScale = normalization_object_t(&ui->widget->object);
    zoom_object_t(&ui->widget->object, getScale);
    QString str_edges = QString::number(ui->widget->object.count_of_edges / 2);
    ui->label_edges->setText("Edges : " + str_edges);
    QString str_vertexes =
        QString::number(ui->widget->object.count_of_vertexes / 3);
    ui->label_vertexes->setText("Vertexes : " + str_vertexes);
  }
}

void MainWindow::on_button_jpeg_clicked() {
  QString file = QFileDialog::getSaveFileName(this, "Save as...", "name.jpeg",
                                              "JPEG (*.jpeg)");
  ui->widget->grabFramebuffer().save(file, NULL, 100);
}

void MainWindow::on_button_bmp_clicked() {
  QString file = QFileDialog::getSaveFileName(this, "Save as...", "name.bmp",
                                              "BMP (*.bmp)");
  ui->widget->grabFramebuffer().save(file, NULL, 100);
}

void MainWindow::on_button_gif_clicked() {
  ui->button_gif->setText("Gif is recording");
  _gif = new QGifImage;
  _timer->start(100);
}

void MainWindow::takeFrame() {
  if (_gif->frameCount() < 50) {
    QImage frame = ui->widget->grabFramebuffer();
    _gif->addFrame(frame.scaled(640, 480), 0);
  } else {
    _timer->stop();
    ui->button_gif->setText("Recording is Finish");
    QString file = QFileDialog::getSaveFileName(this, "Save as...", "name.gif",
                                                "GIF (*.gif)");
    _gif->save(file);
    ui->button_gif->setText("Record gif");
  }
}

void MainWindow::on_button_setting_clicked() {
  options options_form;
  options_form.setWindowTitle("Settings");
  options_form.exec();
  load_Settings();
  update();
}

void MainWindow::on_rotate_x_returnPressed() {
  double val = ui->rotate_x->text().toDouble();
  rotation_object_t(&ui->widget->object, val, xAxis);
  ui->widget->update();
}

void MainWindow::on_rotate_y_returnPressed() {
  double val = ui->rotate_y->text().toDouble();
  rotation_object_t(&ui->widget->object, val, yAxis);
  ui->widget->update();
}

void MainWindow::on_rotate_z_returnPressed() {
  double val = ui->rotate_z->text().toDouble();
  rotation_object_t(&ui->widget->object, val, zAxis);
  ui->widget->update();
}

void MainWindow::on_translate_x_returnPressed() {
  double val = ui->translate_x->text().toDouble();
  moving_object_t(&ui->widget->object, val, xAxis);
  ui->widget->update();
}

void MainWindow::on_translate_y_returnPressed() {
  double val = ui->translate_y->text().toDouble();
  moving_object_t(&ui->widget->object, val, yAxis);
  ui->widget->update();
}

void MainWindow::on_translate_z_returnPressed() {
  double val = ui->translate_z->text().toDouble();
  moving_object_t(&ui->widget->object, val, zAxis);
  ui->widget->update();
}

void MainWindow::on_button_Rotate_pressed() {
  on_rotate_x_returnPressed();
  on_rotate_y_returnPressed();
  on_rotate_z_returnPressed();
}

void MainWindow::on_button_Translate_pressed() {
  on_translate_x_returnPressed();
  on_translate_y_returnPressed();
  on_translate_z_returnPressed();
}

void MainWindow::on_scaleLineEdit_returnPressed() {
  double val = ui->scaleLineEdit->text().toDouble();
  zoom_object_t(&ui->widget->object, val);
  ui->widget->update();
}

void MainWindow::on_scalingButton_pressed() {
  on_scaleLineEdit_returnPressed();
}
