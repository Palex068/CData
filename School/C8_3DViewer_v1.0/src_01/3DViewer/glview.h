#ifndef GLVIEW_H
#define GLVIEW_H
#define GL_SILENCE_DEPRECATION
#include <QDebug>
#include <QFileInfo>
#include <QMouseEvent>
#include <QOpenGLWidget>
#include <QTimer>
#include <QWidget>

#include "qgifimage.h"
extern "C" {
#include "../c_part/parser.h"
}

namespace Ui {
class glView;
}

enum points_type { NO, CUBE, SPHERE };

enum errors { NO_ERROR, PARSER_ERROR, FILE_ERROR };

class glView : public QOpenGLWidget {
  Q_OBJECT

 public:
  glView(QWidget *parent = nullptr);
  QString filename;
  // файл

  enum errors error;
  // ошибки

  bool destroy = false;
  // нужно ли очищать память

  bool ortho;
  // проекции

  double scale;
  // масштаб

  QColor background_color;
  QColor vertex_color, edge_color;
  float vertex_size, edge_size;
  // цвет и размер вершин и линий

  enum points_type p_type;
  // тип точек(куб, сфера или их нет)

  bool dotted_edge;
  // пунктирная ли линия

  Point *get_all_points();
  Surface *get_all_surfaces();
  int get_top_pointers();
  int get_count_surfaces();
  int get_edge();
  void set_scale();

  void paint_file_first();
  // чтение файла и заполнение массивов
  void destroy_all();
  // очистка

 private:
  void mousePressEvent(QMouseEvent *mo);
  void mouseMoveEvent(QMouseEvent *mo);
  float xRot_m, yRot_m;
  QPoint mPos;
  // для движения мышкой

  Point *all_points = NULL;
  Surface *all_surfaces = NULL;
  int top_pointers = 0;
  int count_surfaces = 0;
  int edge = 0;
  // парсер

  void projection();
  // проекции
  void drawObj();
  void drawPoints();

  void paintGL();
  bool fileExists(QString path);

  Ui::glView *ui;
};

#endif  // GLVIEW_H
