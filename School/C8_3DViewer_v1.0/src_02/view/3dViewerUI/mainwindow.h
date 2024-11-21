#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <glwidget.h>
#include <qgifimage.h>

#include <QColorDialog>
#include <QDateTime>
#include <QDialog>
#include <QFileDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QSettings>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  Ui::MainWindow *ui;

  /* VARIABLES FOR OPENGL LOGIC */
  bool isObjFile;
  int vertices_count;
  int edges_count;

  // ENUM MODES
  enum display_method { NONE, CIRCLE, SQUARE };
  enum projection_type { PARALLEL, CENTRAL };
  enum edges_type { SOLID, DASHED };

  ~MainWindow();

 private slots:
  void on_openObjBtn_clicked();
  void on_renderBtn_clicked();
  void on_projection_types_currentIndexChanged(int index);
  void on_vert_color_val_clicked();
  void on_vert_circle_val_clicked();
  void on_vert_none_val_clicked();
  void on_vert_square_val_clicked();
  void on_vert_size_val_valueChanged(int value);
  void on_edge_solid_val_clicked();
  void on_edge_dashed_val_clicked();
  void on_edge_thic_val_valueChanged(int value);
  void on_edge_color_val_clicked();
  void on_background_color_val_clicked();
  void on_scale_val_valueChanged(int value);
  void on_rotate_x_val_valueChanged(int value);
  void on_rotate_y_val_valueChanged(int value);
  void on_rotate_z_val_valueChanged(int value);
  void on_translate_x_val_valueChanged(int value);
  void on_translate_y_val_valueChanged(int value);
  void on_translate_z_val_valueChanged(int value);
  void on_out_btn_clicked();
  void on_in_btn_clicked();
  void on_snap_btn_clicked();
  void save_settings();
  void load_settings();
  void on_gif_btn_clicked();
  void make_gif();

 private:
  void set_mainwindow_attributes();
  void set_fonts();
  void bind_slots();
  void restore_default_values();

  // Windows transition
  QPoint cur_pos;
  QPoint new_pos;
  void mousePressEvent(QMouseEvent *event);
  void mouseMoveEvent(QMouseEvent *event);

  QSettings *settings;
  QString gif_name;
  QGifImage *gif_frame;
  int frames_counter = 0;
  QTimer *timer;
};
#endif  // MAINWINDOW_H
