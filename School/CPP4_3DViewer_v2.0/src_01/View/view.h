#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>
#include <QTimer>

#include "../Controller/controller.h"
#include "glview.h"
#include "qgifimage.h"

const int kFps = 50;
const int kStepRot = 10;
const int kStepMove = 1;
const int kStepScale = 25;

QT_BEGIN_NAMESPACE
namespace Ui {
class View;
}
QT_END_NAMESPACE

class View : public QMainWindow {
  Q_OBJECT

 public:
  View(QWidget *parent = nullptr, s21::Controller *controller = nullptr);
  ~View();

 private:
  void SetZoom(int zoom);
  void SaveScreen(QString format);
  void SaveAs(const QString &format, QString &filename);
  void LoadSettings();
  void SaveSettings() const;

 private slots:
  void MakeGif();

  void StartGif(double x, double y, double z);

  void on_button_filename_clicked();

  void on_pushButton_apply_rotate_clicked();

  void on_pushButton_apply_move_clicked();

  void on_pushButton_minus_clicked();

  void on_pushButton_plus_clicked();

  void on_pushButton_scale_clicked();

  void on_radioButton_solid_edge_clicked(bool checked);

  void on_radioButton_dotted_edge_clicked(bool checked);

  void on_pushButton_color_edge_clicked();

  void on_radioButton_no_point_clicked(bool checked);

  void on_radioButton_sphere_clicked(bool checked);

  void on_radioButton_cube_clicked(bool checked);

  void on_pushButton_color_vertex_clicked();

  void on_lineEdit_thickness_edge_editingFinished();

  void on_lineEdit_dot_size_editingFinished();

  void on_pushButton_color_background_clicked();

  void on_radioButton_central_clicked(bool checked);

  void on_radioButton_ortho_clicked(bool checked);

  void on_pushButton_save_image_bmp_clicked();

  void on_pushButton_save_image_jpeg_clicked();

  void on_pushButton_film_clicked();

  void on_pushButton_x_move_right_clicked();

  void on_pushButton_x_move_left_clicked();

  void on_pushButton_y_move_right_clicked();

  void on_pushButton_y_move_left_clicked();

  void on_pushButton_z_move_right_clicked();

  void on_pushButton_z_move_left_clicked();

  void on_pushButton_xRot_left_clicked();

  void on_pushButton_yRot_left_clicked();

  void on_pushButton_zRot_left_clicked();

  void on_pushButton_xRot_right_clicked();

  void on_pushButton_yRot_right_clicked();

  void on_pushButton_zRot_right_clicked();

  void on_lineEdit_dot_size_returnPressed();

  void on_lineEdit_thickness_edge_returnPressed();

private:
  Ui::View *ui;
  s21::Controller *c_;

 private:
  double x_rot_sum_ = 0, y_rot_sum_ = 0, z_rot_sum_ = 0;
  double x_move_sum_ = 0, y_move_sum_ = 0, z_move_sum_ = 0;
  double x_rot_gif_ = 0, y_rot_gif_ = 0, z_rot_gif_ = 0;
  int scale_ = 0;
  int timer_count_ = 0;
  QString filename_gif_;
  QGifImage *gif_;
  QTimer *time_gif_;
};
#endif  // VIEW_H
