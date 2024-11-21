#include "view.h"

#include <QColorDialog>
#include <QFileDialog>
#include <QImageWriter>
#include <QMessageBox>
#include <QSettings>
#include <QStandardPaths>

#include "dialog.h"
#include "ui_view.h"

View::View(QWidget *parent, s21::Controller *controller)
    : QMainWindow(parent), ui(new Ui::View), c_(controller) {
  ui->setupUi(this);
  setFixedSize(1300, 1000);
  ui->widget->SetData(c_);
  LoadSettings();
}

View::~View() {
  SaveSettings();
  delete ui;
}

void View::on_button_filename_clicked() {
  QString str =
      QFileDialog::getOpenFileName(this, "Open a file", "./models/", "(*.obj)");

  QString err = c_->ParseFile(str);

  if (err.isEmpty()) {
    c_->Scale(100);

    QStringList parts = str.split("/");
    QString lastBit = parts.at(parts.size() - 1);
    ui->label_filename->setText(lastBit);
    ui->label_edge_amount->setText(QString::number(c_->GetCountEdge()));
    ui->label_vertex_amount->setText(QString::number(c_->GetVertexCount()));

    ui->widget->update();
  } else {
    QMessageBox::warning(this, tr("Parse Error"), err);
  }
}

void View::on_pushButton_apply_rotate_clicked() {
  x_rot_sum_ += ui->lineEdit_xRot->text().toDouble();
  y_rot_sum_ += ui->lineEdit_yRot->text().toDouble();
  z_rot_sum_ += ui->lineEdit_zRot->text().toDouble();
  c_->Rotate(ui->lineEdit_xRot->text().toDouble(),
             ui->lineEdit_yRot->text().toDouble(),
             ui->lineEdit_zRot->text().toDouble());
  ui->widget->update();
}

void View::on_pushButton_apply_move_clicked() {
  x_move_sum_ += ui->lineEdit_x_move->text().toDouble();
  y_move_sum_ += ui->lineEdit_y_move->text().toDouble();
  z_move_sum_ += ui->lineEdit_z_move->text().toDouble();
  c_->Move(ui->lineEdit_x_move->text().toDouble(),
           ui->lineEdit_y_move->text().toDouble(),
           ui->lineEdit_z_move->text().toDouble());
  ui->widget->update();
}

void View::on_pushButton_minus_clicked() {
  int zoom = ui->label_scale->text().toInt();
  zoom -= kStepScale;
  SetZoom(zoom);
}

void View::on_pushButton_plus_clicked() {
  int zoom = ui->label_scale->text().toInt();
  zoom += kStepScale;
  SetZoom(zoom);
}

void View::SetZoom(int zoom) {
  if (zoom > 20 && zoom <= 200) {
    ui->label_scale->setText(QString::number(zoom));
  }
}

void View::SaveScreen(QString format) {
  QPixmap originalPixmap = QWidget::grab(ui->widget->frameGeometry());

  QString fileName;
  SaveAs(format, fileName);
  if (!originalPixmap.save(fileName)) {
    QMessageBox::warning(this, tr("Save Error"),
                         tr("The image could not be saved to \"%1\".")
                             .arg(QDir::toNativeSeparators(fileName)));
  }
}

void View::SaveAs(const QString &format, QString &filename) {
  QString initialPath =
      QStandardPaths::writableLocation(QStandardPaths::PicturesLocation);
  if (initialPath.isEmpty()) initialPath = QDir::currentPath();
  initialPath += tr("/untitled.") + format;

  QFileDialog fileDialog(this, tr("Save As"), initialPath);
  fileDialog.setAcceptMode(QFileDialog::AcceptSave);
  fileDialog.setFileMode(QFileDialog::AnyFile);
  fileDialog.setDirectory(initialPath);
  QStringList mimeTypes;
  const QList<QByteArray> baMimeTypes = QImageWriter::supportedMimeTypes();
  for (const QByteArray &bf : baMimeTypes) mimeTypes.append(QLatin1String(bf));
  fileDialog.setMimeTypeFilters(mimeTypes);
  fileDialog.selectMimeTypeFilter("image/" + format);
  fileDialog.setDefaultSuffix(format);
  if (fileDialog.exec() != QDialog::Accepted) return;

  filename = fileDialog.selectedFiles().first();
}

void View::LoadSettings() {
  ui->label_film_process->hide();
  ui->label_film_process_5->hide();

  ui->radioButton_ortho->setChecked(true);
  ui->widget->SetIsOrtho(true);

  ui->widget->SetBackgroundColor();

  ui->radioButton_no_point->setChecked(true);
  ui->lineEdit_dot_size->setText("0.5");
  ui->widget->SetVertex();

  ui->radioButton_solid_edge->setChecked(true);
  ui->lineEdit_thickness_edge->setText("0.5");
  ui->widget->SetEdge();

  QSettings settings("3D", "AbobaAbiba");

  // --------------------------------------------------

  settings.beginGroup("Vertex");
  char type = settings.value("type").toInt();
  float v_size = settings.value("size").toFloat();
  if (type == 'n') {
    ui->radioButton_no_point->setChecked(true);
  } else if (type == 's') {
    ui->radioButton_sphere->setChecked(true);
  } else if (type == 'c') {
    ui->radioButton_cube->setChecked(true);
  }
  ui->lineEdit_dot_size->setText(QString::number(v_size));
  ui->widget->SetVertex(settings.value("color").toString(),
                        v_size, type);

  settings.endGroup();

  // --------------------------------------------------

  settings.beginGroup("Edge");
  bool dotted = settings.value("dotted").toBool();
  float e_size = settings.value("size").toFloat();

  if (dotted) {
    ui->radioButton_dotted_edge->setChecked(true);
  } else {
    ui->radioButton_solid_edge->setChecked(true);
  }
  ui->lineEdit_thickness_edge->setText(QString::number(e_size));
  ui->widget->SetEdge(dotted, settings.value("color").toString(),
                      e_size);

  settings.endGroup();

  // --------------------------------------------------

  settings.beginGroup("Other");
  bool ortho = settings.value("ortho").toBool();
  if (ortho) {
    ui->radioButton_ortho->setChecked(true);
  } else {
    ui->radioButton_central->setChecked(true);
  }
  ui->widget->SetIsOrtho(ortho);
  ui->widget->SetBackgroundColor(settings.value("back_color").toString());

  settings.endGroup();

  // --------------------------------------------------

  settings.beginGroup("Rotation");
  ui->lineEdit_xRot->setText(settings.value("x").toString());
  ui->lineEdit_yRot->setText(settings.value("y").toString());
  ui->lineEdit_zRot->setText(settings.value("z").toString());
  settings.endGroup();

  // --------------------------------------------------

  settings.beginGroup("Move");
  ui->lineEdit_x_move->setText(settings.value("x").toString());
  ui->lineEdit_y_move->setText(settings.value("y").toString());
  ui->lineEdit_z_move->setText(settings.value("z").toString());
  settings.endGroup();
}

void View::SaveSettings() const {
  QSettings settings("3D", "AbobaAbiba");

  settings.setValue("title", windowTitle());
  settings.beginGroup("Vertex");
  settings.setValue("type", ui->widget->GetVertexType());
  settings.setValue("color", ui->widget->GetVertexColor());
  settings.setValue("size", ui->widget->GetVertexSize());
  settings.endGroup();

  settings.beginGroup("Edge");
  settings.setValue("dotted", ui->widget->GetIsDottedEdge());
  settings.setValue("color", ui->widget->GetEdgeColor());
  settings.setValue("size", ui->widget->GetEdgeSize());
  settings.endGroup();

  settings.beginGroup("Other");
  settings.setValue("back_color", ui->widget->GetBackgroundColor());
  settings.setValue("ortho", ui->radioButton_ortho->isChecked());
  settings.endGroup();

  settings.beginGroup("Rotation");
  settings.setValue("x", x_rot_sum_);
  settings.setValue("y", y_rot_sum_);
  settings.setValue("z", z_rot_sum_);
  settings.endGroup();

  settings.beginGroup("Move");
  settings.setValue("x", x_move_sum_);
  settings.setValue("y", y_move_sum_);
  settings.setValue("z", z_move_sum_);
  settings.endGroup();
}

void View::MakeGif() {
  QImage add_img;
  if (timer_count_ < kFps) {
    ui->label_film_process->setText(QString::number((timer_count_ + 1) * 2));
    c_->Rotate(x_rot_gif_ / 50.0, y_rot_gif_ / 50.0, z_rot_gif_ / 50.0);
    timer_count_++;
    gif_->setDefaultDelay(10);
    add_img = ui->widget->grabFramebuffer().scaled(640, 480);
    gif_->addFrame(add_img);

  } else {
    timer_count_ = 0;
    time_gif_->stop();
    gif_->save(filename_gif_);
    delete time_gif_;
    delete gif_;
    ui->pushButton_film->setEnabled(true);
    ui->label_film_process->hide();
    ui->label_film_process_5->hide();
  }
}

void View::StartGif(double x, double y, double z) {
  x_rot_gif_ = x;
  y_rot_gif_ = y;
  z_rot_gif_ = z;
  if (filename_gif_ != "") {
    if (ui->pushButton_film->isEnabled()) {
      time_gif_ = new QTimer();
      gif_ = new QGifImage();
    }

    time_gif_->start(100);
    connect(time_gif_, SIGNAL(timeout()), this, SLOT(MakeGif()));

    ui->pushButton_film->setDisabled(true);
  }
}

void View::on_pushButton_scale_clicked() {
  c_->Scale(ui->label_scale->text().toDouble());
  ui->widget->update();
}

void View::on_radioButton_solid_edge_clicked(bool checked) {
  if (checked) {
    ui->widget->SetIsDottedEdge(false);
    ui->widget->update();
  }
}

void View::on_radioButton_dotted_edge_clicked(bool checked) {
  if (checked) {
    ui->widget->SetIsDottedEdge(true);
    ui->widget->update();
  }
}

void View::on_pushButton_color_edge_clicked() {
  QColor color = QColorDialog::getColor(Qt::white, this, "Выберите цвет ребра");
  if (color.isValid()) {
    ui->widget->SetEdgeColor(color);
    ui->widget->update();
  }
}

void View::on_radioButton_no_point_clicked(bool checked) {
  if (checked) {
    ui->widget->SetVertexType('n');
    ui->widget->update();
  }
}

void View::on_radioButton_sphere_clicked(bool checked) {
  if (checked) {
    ui->widget->SetVertexType('s');
    ui->widget->update();
  }
}

void View::on_radioButton_cube_clicked(bool checked) {
  if (checked) {
    ui->widget->SetVertexType('c');
    ui->widget->update();
  }
}

void View::on_pushButton_color_vertex_clicked() {
  QColor color =
      QColorDialog::getColor(Qt::white, this, "Выберите цвет вершин");
  if (!color.isValid()) {
    ui->widget->SetVertexColor(ui->widget->GetEdgeColor().darker());
  } else {
    ui->widget->SetVertexColor(color);
  }
  ui->widget->update();
}

void View::on_lineEdit_thickness_edge_editingFinished() {
  double edge = ui->lineEdit_thickness_edge->text().toFloat();
  ui->widget->SetEdgeSize(edge);
  if (edge < 0) {
    ui->widget->SetEdgeSize(0.5);
    ui->lineEdit_thickness_edge->setText("0.5");
  }
  ui->widget->update();
}

void View::on_lineEdit_dot_size_editingFinished() {
  double dot = ui->lineEdit_dot_size->text().toFloat();
  ui->widget->SetVertexSize(dot);
  if (dot < 0) {
    ui->widget->SetVertexSize(0.5);
    ui->lineEdit_dot_size->setText("0.5");
  }
  ui->widget->update();
}

void View::on_pushButton_color_background_clicked() {
  ui->widget->SetBackgroundColor(
      QColorDialog::getColor(Qt::white, this, "Выберите цвет фона"));
  ui->widget->update();
}

void View::on_radioButton_central_clicked(bool checked) {
  if (checked) {
    ui->widget->SetIsOrtho(false);
    ui->widget->update();
  }
}

void View::on_radioButton_ortho_clicked(bool checked) {
  if (checked) {
    ui->widget->SetIsOrtho(true);
    ui->widget->update();
  }
}

void View::on_pushButton_save_image_bmp_clicked() { SaveScreen("bmp"); }

void View::on_pushButton_save_image_jpeg_clicked() { SaveScreen("jpeg"); }

void View::on_pushButton_film_clicked() {
  filename_gif_ = "";
  Dialog window(this);
  SaveAs("gif", filename_gif_);
  if (!filename_gif_.isEmpty()) {
    ui->label_film_process->show();
    ui->label_film_process_5->show();
    connect(&window, SIGNAL(apply(double, double, double)),
            SLOT(StartGif(double, double, double)));
    window.exec();
  } else {
    QMessageBox::warning(this, tr("Save Error"),
                         tr("Выберите файл для сохранения"));
  }
}



void View::on_pushButton_x_move_right_clicked()
{
    double number = ui->lineEdit_x_move->text().toDouble();
    ui->lineEdit_x_move->setText(QString::number(number + (kStepMove)));
}


void View::on_pushButton_x_move_left_clicked()
{
    double number = ui->lineEdit_x_move->text().toDouble();
    ui->lineEdit_x_move->setText(QString::number(number - (kStepMove)));
}


void View::on_pushButton_y_move_right_clicked()
{
    double number = ui->lineEdit_y_move->text().toDouble();
    ui->lineEdit_y_move->setText(QString::number(number + (kStepMove)));
}


void View::on_pushButton_y_move_left_clicked()
{
    double number = ui->lineEdit_y_move->text().toDouble();
    ui->lineEdit_y_move->setText(QString::number(number - (kStepMove)));
}


void View::on_pushButton_z_move_right_clicked()
{
    double number = ui->lineEdit_z_move->text().toDouble();
    ui->lineEdit_z_move->setText(QString::number(number + (kStepMove)));
}


void View::on_pushButton_z_move_left_clicked()
{
    double number = ui->lineEdit_z_move->text().toDouble();
    ui->lineEdit_z_move->setText(QString::number(number - (kStepMove)));
}



void View::on_pushButton_xRot_left_clicked()
{
    double number = ui->lineEdit_xRot->text().toDouble();
      ui->lineEdit_xRot->setText(QString::number(number - (kStepRot)));
}


void View::on_pushButton_yRot_left_clicked()
{
    double number = ui->lineEdit_yRot->text().toDouble();
    ui->lineEdit_yRot->setText(QString::number(number - (kStepRot)));
}


void View::on_pushButton_zRot_left_clicked()
{
    double number = ui->lineEdit_zRot->text().toDouble();
    ui->lineEdit_zRot->setText(QString::number(number - (kStepRot)));
}


void View::on_pushButton_xRot_right_clicked()
{
    double number = ui->lineEdit_xRot->text().toDouble();
    ui->lineEdit_xRot->setText(QString::number(number + (kStepRot)));
}


void View::on_pushButton_yRot_right_clicked()
{
    double number = ui->lineEdit_yRot->text().toDouble();
    ui->lineEdit_yRot->setText(QString::number(number + (kStepRot)));
}


void View::on_pushButton_zRot_right_clicked()
{
    double number = ui->lineEdit_zRot->text().toDouble();
    ui->lineEdit_zRot->setText(QString::number(number + (kStepRot)));
}


void View::on_lineEdit_dot_size_returnPressed()
{
    on_lineEdit_dot_size_editingFinished();
}


void View::on_lineEdit_thickness_edge_returnPressed()
{
    on_lineEdit_thickness_edge_editingFinished();
}

