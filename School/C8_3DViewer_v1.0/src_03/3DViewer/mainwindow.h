#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QColorDialog>
#include <QFileDialog>
#include <QMainWindow>
#include <QSettings>

#include "viewer.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void on_open_button_clicked();

  void on_bg_color_clicked();

  void on_line_color_clicked();

  void on_point_color_clicked();
  void shift_view(int new_pos, int ax);
  void rotate_view(int new_degree, int ax);
  void scale_view(int new_scale);
  void on_moov_x_valueChanged(int value);

  void on_moov_y_valueChanged(int value);

  void on_moov_z_valueChanged(int value);

  void on_scale_valueChanged(int value);

  void on_point_size_ui_valueChanged(int value);

  void on_point_type_ui_currentIndexChanged(int index);

  void on_thickness_valueChanged(int value);

  void on_line_type_ui_currentIndexChanged(int index);

  void on_rotate_x_valueChanged(int value);

  void on_rotate_y_valueChanged(int value);

  void on_rotate_z_valueChanged(int value);

  void on_projection_currentIndexChanged(int index);

  void on_screenshot_clicked();

 private:
  Ui::MainWindow *ui;
  void saveSettings();
  void loadSettings();
  void default_settings();
  int slider_x_pos;
  int slider_y_pos;
  int slider_z_pos;
  int slider_x_rot;
  int slider_y_rot;
  int slider_z_rot;
  int scale;
};
#endif  // MAINWINDOW_H
