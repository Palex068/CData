#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFileDialog>
#include <QMainWindow>
#include <QTimer>
#include <cstring>

#include "QSettings"
#include "QtGifImage/gifimage/qgifimage.h"
#include "backend/3d_viewer.h"
#include "options.h"
#include "ui_mainwindow.h"

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
  QString __buffpath;
  Ui::MainWindow *ui;
  QSettings *settings;  // настройки

 private:
  QTimer *_timer;
  QGifImage *_gif;

 private slots:
  void on_actionClose_triggered();
  void on_button_open_path_clicked();
  void on_button_jpeg_clicked();
  void on_button_bmp_clicked();
  void on_button_gif_clicked();
  void takeFrame();
  // установка значений по нажанию на Enter
  void on_rotate_x_returnPressed();
  void on_rotate_y_returnPressed();
  void on_rotate_z_returnPressed();
  void on_translate_x_returnPressed();
  void on_translate_y_returnPressed();
  void on_translate_z_returnPressed();
  void on_scaleLineEdit_returnPressed();
  // установка значений по нажанию на соответствующую кнопку
  void on_button_Rotate_pressed();
  void on_button_Translate_pressed();
  void on_scalingButton_pressed();

  void on_button_setting_clicked();
  void load_Settings();  // подгрузить настройки
};

#endif  // MAINWINDOW_H
