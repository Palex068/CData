#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ui->obj_info->hide();
  set_mainwindow_attributes();
  set_fonts();
  bind_slots();
  settings = new QSettings("21school", "3D_Viewer", this);
  load_settings();
}

MainWindow::~MainWindow() {
  save_settings();
  data_destructor(&ui->OpenGlWidget->data);
  delete settings;
  delete ui;
}

void MainWindow::set_mainwindow_attributes() {
  this->setWindowFlags(Qt::WindowType::FramelessWindowHint);
  this->setAttribute(Qt::WA_TranslucentBackground);
  this->setAutoFillBackground(true);
  timer = new QTimer(0);
}

void MainWindow::set_fonts() {
  // creating
  int id = QFontDatabase::addApplicationFont(
      ":/res/assets/fonts/SpaceCrusadersItalic-ZV1Zx.ttf");
  QString family = QFontDatabase::applicationFontFamilies(id).at(0);
  QFont titleFont(family);
  int id2 = QFontDatabase::addApplicationFont(
      ":/res/assets/fonts/Montserrat-Regular.ttf");
  QString family2 = QFontDatabase::applicationFontFamilies(id2).at(0);
  QFont mainFont(family2);
  int id3 = QFontDatabase::addApplicationFont(
      ":/res/assets/fonts/TechnoCharmDemoVersionRegular-ALaZm.otf");
  QString family3 = QFontDatabase::applicationFontFamilies(id3).at(0);
  QFont footerFont(family3);

  // applying
  ui->h1->setFont(titleFont);
  ui->obj_info->setFont(mainFont);
  ui->filename_val->setFont(footerFont);
  ui->edges_numb_val->setFont(footerFont);
  ui->vert_numb_val->setFont(footerFont);
}

void MainWindow::bind_slots() {
  connect(ui->closeBtn, SIGNAL(clicked()), this, SLOT(close()));
  connect(ui->minimizeBtn, SIGNAL(clicked()), this, SLOT(showMinimized()));
  connect(timer, SIGNAL(timeout()), this, SLOT(make_gif()));
}

void MainWindow::restore_default_values() {
  ui->scale_val->setValue(50);
  ui->rotate_x_val->setValue(0);
  ui->rotate_y_val->setValue(0);
  ui->rotate_z_val->setValue(0);
  ui->translate_x_val->setValue(0);
  ui->translate_y_val->setValue(0);
  ui->translate_z_val->setValue(0);
}

void MainWindow::save_settings() {
  settings->setValue("are_settings", 1);
  settings->setValue("projection_type", ui->OpenGlWidget->projection_type);
  settings->setValue("v_display_method", ui->OpenGlWidget->v_display_method);
  settings->setValue("vertices_size", ui->OpenGlWidget->vertices_size);
  settings->setValue("v_red", ui->OpenGlWidget->v_red);
  settings->setValue("v_green", ui->OpenGlWidget->v_green);
  settings->setValue("v_blue", ui->OpenGlWidget->v_blue);
  settings->setValue("edges_type", ui->OpenGlWidget->edges_type);
  settings->setValue("edges_thickness", ui->OpenGlWidget->edges_thickness);
  settings->setValue("e_red", ui->OpenGlWidget->e_red);
  settings->setValue("e_green", ui->OpenGlWidget->e_green);
  settings->setValue("e_blue", ui->OpenGlWidget->e_blue);
  settings->setValue("bg_red", ui->OpenGlWidget->bg_red);
  settings->setValue("bg_green", ui->OpenGlWidget->bg_green);
  settings->setValue("bg_blue", ui->OpenGlWidget->bg_blue);
}

void MainWindow::load_settings() {
  if (settings->value("are_settings").toInt()) {
    char rgba_color[40];
    ui->projection_types->setCurrentIndex(
        settings->value("projection_type").toInt());
    int v_mode = settings->value("v_display_method").toInt();
    if (v_mode == 0) {
      ui->vert_none_val->setChecked(true);
      ui->OpenGlWidget->v_display_method = 0;
    } else if (v_mode == 1) {
      ui->vert_circle_val->setChecked(true);
      ui->OpenGlWidget->v_display_method = 1;
    } else if (v_mode == 2) {
      ui->vert_square_val->setChecked(true);
      ui->OpenGlWidget->v_display_method = 2;
    }
    ui->vert_size_val->setValue(settings->value("vertices_size").toDouble());
    ui->OpenGlWidget->v_red = settings->value("v_red").toDouble();
    ui->OpenGlWidget->v_green = settings->value("v_green").toDouble();
    ui->OpenGlWidget->v_blue = settings->value("v_blue").toDouble();
    sprintf(rgba_color, "background-color: rgb(%d,%d,%d)",
            (int)(ui->OpenGlWidget->v_red * 255),
            (int)(ui->OpenGlWidget->v_green * 255),
            (int)(ui->OpenGlWidget->v_blue * 255));
    ui->vert_color_val->setStyleSheet(rgba_color);
    int edges_mode = settings->value("edges_type").toInt();
    if (edges_mode == 0) {
      ui->edge_solid_val->setChecked(true);
      ui->OpenGlWidget->edges_type = 0;
    } else if (edges_mode == 1) {
      ui->edge_dashed_val->setChecked(true);
      ui->OpenGlWidget->edges_type = 1;
    }
    ui->edge_thic_val->setValue(settings->value("edges_thickness").toInt() *
                                10);
    ui->OpenGlWidget->e_red = settings->value("e_red").toDouble();
    ui->OpenGlWidget->e_green = settings->value("e_green").toDouble();
    ui->OpenGlWidget->e_blue = settings->value("e_blue").toDouble();
    sprintf(rgba_color, "background-color: rgb(%d,%d,%d)",
            (int)(ui->OpenGlWidget->e_red * 255),
            (int)(ui->OpenGlWidget->e_green * 255),
            (int)(ui->OpenGlWidget->e_blue * 255));
    ui->edge_color_val->setStyleSheet(rgba_color);
    ui->OpenGlWidget->bg_red = settings->value("bg_red").toDouble();
    ui->OpenGlWidget->bg_green = settings->value("bg_green").toDouble();
    ui->OpenGlWidget->bg_blue = settings->value("bg_blue").toDouble();
    sprintf(rgba_color, "background-color: rgb(%d,%d,%d)",
            (int)(ui->OpenGlWidget->bg_red * 255),
            (int)(ui->OpenGlWidget->bg_green * 255),
            (int)(ui->OpenGlWidget->bg_blue * 255));
    ui->background_color_val->setStyleSheet(rgba_color);
  }
}

void MainWindow::on_openObjBtn_clicked() {
  QString QString_filename = QFileDialog::getOpenFileName(
      this, tr("Open .obj file:"), "~/", tr("Obj Files (*.obj)"));
  ui->pathObj->setText(QString_filename);
}

void MainWindow::on_renderBtn_clicked() {
  restore_default_values();
  std::string std_filename = ui->pathObj->text().toStdString();
  ui->OpenGlWidget->filename = (char *)std_filename.c_str();
  ui->OpenGlWidget->parse_obj();
  if (ui->OpenGlWidget->filename[0] != '\0') {
    isObjFile = 1;
    char *start = strrchr((char *)std_filename.c_str(), '/') + 1;
    char *ext = strrchr((char *)std_filename.c_str(), '.');
    *ext = '\0';
    ui->filename_val->setText(start);
    ui->obj_info->show();
  } else {
    isObjFile = 0;
    ui->obj_info->hide();
  }

  ui->vert_numb_val->setText(
      QString::number(ui->OpenGlWidget->data.vertices_count));
  ui->edges_numb_val->setText(
      QString::number(ui->OpenGlWidget->data.vertex_indices_count));
}

void MainWindow::mouseMoveEvent(QMouseEvent *event) {
  new_pos = QPoint(event->globalPosition().toPoint() - cur_pos);
  move(x() + new_pos.x(), y() + new_pos.y());
  cur_pos = event->globalPosition().toPoint();
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
  cur_pos = event->globalPosition().toPoint();
}

void MainWindow::on_projection_types_currentIndexChanged(int index) {
  if (index == 0) {
    ui->OpenGlWidget->projection_type = PARALLEL;
  } else if (index == 1) {
    ui->OpenGlWidget->projection_type = CENTRAL;
  }
  ui->OpenGlWidget->update();
}

void MainWindow::on_vert_color_val_clicked() {
  QColor vert_color =
      QColorDialog::getColor(Qt::white, this->ui->tabWidget, "Choose color");
  if (vert_color.isValid()) {
    ui->OpenGlWidget->v_red = vert_color.redF();
    ui->OpenGlWidget->v_green = vert_color.greenF();
    ui->OpenGlWidget->v_blue = vert_color.blueF();
    char rgba_color[40];
    sprintf(rgba_color, "background-color: rgb(%d,%d,%d)", vert_color.red(),
            vert_color.green(), vert_color.blue());
    ui->vert_color_val->setStyleSheet(rgba_color);
    ui->OpenGlWidget->update();
  }
}

void MainWindow::on_vert_none_val_clicked() {
  ui->OpenGlWidget->v_display_method = NONE;
  ui->OpenGlWidget->update();
}

void MainWindow::on_vert_circle_val_clicked() {
  ui->OpenGlWidget->v_display_method = CIRCLE;
  ui->OpenGlWidget->update();
}

void MainWindow::on_vert_square_val_clicked() {
  ui->OpenGlWidget->v_display_method = SQUARE;
  ui->OpenGlWidget->update();
}

void MainWindow::on_vert_size_val_valueChanged(int value) {
  ui->OpenGlWidget->vertices_size = value;
  ui->OpenGlWidget->update();
}

void MainWindow::on_edge_solid_val_clicked() {
  ui->OpenGlWidget->edges_type = SOLID;
  ui->OpenGlWidget->update();
}

void MainWindow::on_edge_dashed_val_clicked() {
  ui->OpenGlWidget->edges_type = DASHED;
  ui->OpenGlWidget->update();
}

void MainWindow::on_edge_thic_val_valueChanged(int value) {
  ui->OpenGlWidget->edges_thickness = value / 10;
  ui->OpenGlWidget->update();
}

void MainWindow::on_edge_color_val_clicked() {
  QColor edge_color =
      QColorDialog::getColor(Qt::white, this->ui->tabWidget, "Choose color");
  if (edge_color.isValid()) {
    ui->OpenGlWidget->e_red = edge_color.redF();
    ui->OpenGlWidget->e_green = edge_color.greenF();
    ui->OpenGlWidget->e_blue = edge_color.blueF();
    char rgba_color[40];
    sprintf(rgba_color, "background-color: rgb(%d,%d,%d)", edge_color.red(),
            edge_color.green(), edge_color.blue());
    ui->edge_color_val->setStyleSheet(rgba_color);
    ui->OpenGlWidget->update();
  }
}

void MainWindow::on_background_color_val_clicked() {
  QColor bg_color =
      QColorDialog::getColor(Qt::white, this->ui->tabWidget, "Choose color");
  if (bg_color.isValid()) {
    ui->OpenGlWidget->bg_red = bg_color.redF();
    ui->OpenGlWidget->bg_green = bg_color.greenF();
    ui->OpenGlWidget->bg_blue = bg_color.blueF();
    char rgba_color[40];
    sprintf(rgba_color, "background-color: rgb(%d,%d,%d)", bg_color.red(),
            bg_color.green(), bg_color.blue());
    ui->background_color_val->setStyleSheet(rgba_color);
    ui->OpenGlWidget->update();
  }
}

void MainWindow::on_scale_val_valueChanged(int value) {
  double val = (double)value / ui->OpenGlWidget->scale_val;
  scale(&ui->OpenGlWidget->data, val);
  ui->OpenGlWidget->scale_val = value;
  ui->OpenGlWidget->update();
}

void MainWindow::on_rotate_x_val_valueChanged(int value) {
  rotate_X(&ui->OpenGlWidget->data, (value - ui->OpenGlWidget->rotate_x));
  ui->OpenGlWidget->rotate_x = value;
  ui->OpenGlWidget->update();
}

void MainWindow::on_rotate_y_val_valueChanged(int value) {
  rotate_Y(&ui->OpenGlWidget->data, (value - ui->OpenGlWidget->rotate_y));
  ui->OpenGlWidget->rotate_y = value;
  ui->OpenGlWidget->update();
}

void MainWindow::on_rotate_z_val_valueChanged(int value) {
  rotate_Z(&ui->OpenGlWidget->data, (value - ui->OpenGlWidget->rotate_z));
  ui->OpenGlWidget->rotate_z = value;
  ui->OpenGlWidget->update();
}

void MainWindow::on_translate_x_val_valueChanged(int value) {
  move_X(&ui->OpenGlWidget->data, (value - ui->OpenGlWidget->translate_x) *
                                      ui->OpenGlWidget->normalize_coef / 100);
  ui->OpenGlWidget->translate_x = value;
  ui->OpenGlWidget->update();
}

void MainWindow::on_translate_y_val_valueChanged(int value) {
  move_Y(&ui->OpenGlWidget->data, (value - ui->OpenGlWidget->translate_y) *
                                      ui->OpenGlWidget->normalize_coef / 100);
  ui->OpenGlWidget->translate_y = value;
  ui->OpenGlWidget->update();
}

void MainWindow::on_translate_z_val_valueChanged(int value) {
  move_Z(&ui->OpenGlWidget->data, (value - ui->OpenGlWidget->translate_z) *
                                      ui->OpenGlWidget->normalize_coef / 100);
  ui->OpenGlWidget->translate_z = value;
  ui->OpenGlWidget->update();
}

void MainWindow::on_out_btn_clicked() {
  ui->scale_val->setValue(ui->scale_val->value() - 10);
}

void MainWindow::on_in_btn_clicked() {
  ui->scale_val->setValue(ui->scale_val->value() + 10);
}

void MainWindow::on_snap_btn_clicked() {
  if (isObjFile) {
    QFileDialog dialogConnectImage(this);
    QDateTime current_date = QDateTime::currentDateTime();
    QString formattedTime = current_date.toString("yyyy-MM-dd hh.mm.ss");
    QString name_pattern = "Screen Shot " + formattedTime + ".jpeg";
    QString image_name = dialogConnectImage.getSaveFileName(
        this, tr("Save a screenshot"), name_pattern,
        tr("image (*.jpeg *.bmp)"));
    if (image_name.length() >= 1) {
      QImage img = ui->OpenGlWidget->grabFramebuffer();
      img.save(image_name);
      QMessageBox messageBoxImage;
      messageBoxImage.information(0, "", "Screenshot saved successfully");
    }
  } else {
    QMessageBox warning = QMessageBox();
    warning.setWindowTitle("Error");
    warning.setText("Please open .obj file to take a screenshot");
    warning.setIcon(QMessageBox::Warning);
    warning.exec();
  }
}

void MainWindow::on_gif_btn_clicked() {
  if (isObjFile) {
    QDateTime current_date = QDateTime::currentDateTime();
    QString formattedTime = current_date.toString("yyyy-MM-dd hh.mm.ss");
    QString name_pattern = "Screen Cast " + formattedTime + ".gif";
    gif_name = QFileDialog::getSaveFileName(this, tr("Save a gif animation"),
                                            name_pattern, tr("gif (*.gif)"));
    if (gif_name != "") {
      ui->gif_btn->setDisabled(true);
      gif_frame = new QGifImage;
      gif_frame->setDefaultDelay(10);
      timer->setInterval(100);
      timer->start();
    }
  } else {
    QMessageBox warning = QMessageBox();
    warning.setWindowTitle("Error");
    warning.setText("Please open .obj file to take a screencast");
    warning.setIcon(QMessageBox::Warning);
    warning.exec();
  }
}

void MainWindow::make_gif() {
  QImage image = ui->OpenGlWidget->grabFramebuffer();
  QSize image_size(640, 480);
  QImage scaled_image = image.scaled(image_size);
  gif_frame->addFrame(scaled_image);
  if (frames_counter == 50) {
    timer->stop();
    gif_frame->save(gif_name);
    frames_counter = 0;
    QMessageBox messageBoxGif;
    messageBoxGif.information(0, "", "Gif animation saved successfully");
    delete gif_frame;
    ui->gif_btn->setText("");
    ui->gif_btn->setEnabled(true);
  }
  frames_counter++;
  if (!ui->gif_btn->isEnabled()) {
    ui->gif_btn->setText(QString::number(frames_counter / 10) + "s");
  }
}
