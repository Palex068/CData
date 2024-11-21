#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>

#include "dialog.h"
#include "glview.h"

#define FPS 50
#define STEP_ROT 10
#define STEP_MOVE 1
#define STEP_SCALE 25
#define FILNAME_PATH "../../../../s21_3dViewer/src/models"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  glView *view;
  ~MainWindow();

  double x_rot_sum, y_rot_sum, z_rot_sum;
  double x_rot_gif, y_rot_gif, z_rot_gif;
  double x_move_sum, y_move_sum, z_move_sum;
 private slots:

  void on_button_filename_clicked();

  void full_info();
  void save_settings();
  void load_settings();
  void save_screen(QString format);
  void save_as(const QString &format, QString &fileName);
  void make_gif();

  void start_gif(double x, double y, double z);

  void on_radioButton_central_clicked(bool checked);

  void on_radioButton_ortho_clicked(bool checked);

  void on_pushButton_apply_rotate_clicked();

  void on_pushButton_apply_move_clicked();

  void on_radioButton_no_point_clicked(bool checked);

  void on_radioButton_sphere_clicked(bool checked);

  void on_radioButton_cube_clicked(bool checked);

  void on_lineEdit_thickness_edge_editingFinished();

  void on_lineEdit_dot_size_editingFinished();

  void on_radioButton_solid_edge_clicked(bool checked);

  void on_radioButton_dotted_edge_clicked(bool checked);

  void on_lineEdit_thickness_edge_returnPressed();

  void on_lineEdit_dot_size_returnPressed();

  void on_pushButton_color_edge_clicked();

  void on_pushButton_color_vertex_clicked();

  void on_pushButton_color_background_clicked();

  void on_pushButton_xRot_left_clicked();

  void on_pushButton_yRot_left_clicked();

  void on_pushButton_zRot_left_clicked();

  void on_pushButton_xRot_right_clicked();

  void on_pushButton_yRot_right_clicked();

  void on_pushButton_zRot_right_clicked();

  void on_pushButton_x_move_left_clicked();

  void on_pushButton_y_move_left_clicked();

  void on_pushButton_z_move_left_clicked();

  void on_pushButton_x_move_right_clicked();

  void on_pushButton_y_move_right_clicked();

  void on_pushButton_z_move_right_clicked();

  void on_pushButton_minus_clicked();

  void on_pushButton_plus_clicked();

  void on_pushButton_clicked();

  void on_pushButton_save_image_jpeg_clicked();

  void on_pushButton_save_image_bmp_clicked();

  void on_pushButton_film_clicked();

 private:
  Ui::MainWindow *ui;
  QSettings *settings;
  QPixmap originalPixmap;

  int timer_count;
  QString FileName_gif;
  QGifImage *gif;
  QTimer *time_gif;
  QImage image_arr[100];
};
#endif  // MAINWINDOW_H
