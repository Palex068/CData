#ifndef VIEWER_H
#define VIEWER_H

#include <QMouseEvent>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QWheelEvent>
#include <QtOpenGL>

extern "C" {
#include "../common/common.h"
}

#define CENTRAL_PR 0
#define PARALLEL_PR 1
#define SOLID_LINE 0
#define DASH_LINE 1
#define NONE 0
#define ROUND 1
#define SQUARE 2

class Viewer : public QOpenGLWidget {
  Q_OBJECT

 public:
  Figure *new_data;
  double curr_scale = 1;

  Viewer(QWidget *parent = nullptr);
  ~Viewer();
  void loadModel(QString filename);
  void update_alpha(int valueX, int valueY);
  void update_move_vector(int valueX, int valueY);
  void update_scale(int value);

  double vertex_r = 0, vertex_g = 0, vertex_b = 1;
  double polygon_r = 0, polygon_g = 1, polygon_b = 0;
  double bg_r = 1, bg_g = 1, bg_b = 1;
  double line_width = 1, vertex_size = 3;
  int projection_type = CENTRAL_PR;  // PARALLEL_PR
  int line_type = SOLID_LINE;        // DASH_LINE
  int vertex_type = SQUARE;          // NONE, ROUND

 protected:
  void initializeGL() override;
  void paintGL() override;
  void resizeGL(int w, int h) override;
  void mousePressEvent(QMouseEvent *event) override;
  void mouseMoveEvent(QMouseEvent *event) override;
  void wheelEvent(QWheelEvent *event) override;

  QPoint cur_pos;
  QPoint new_pos;
  QString start_file = QString("./obj_files/3dviewer.obj");
  double move_coef;
};
#endif  // VIEWER_H
