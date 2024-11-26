#ifndef GLVIEW_H
#define GLVIEW_H

#include <QColorDialog>
#include <QMouseEvent>
#include <QOpenGLFunctions>
#include <QWheelEvent>
#include <QtOpenGLWidgets/QOpenGLWidget>
#include <cmath>

#include "backend/3d_viewer.h"

#define GL_SILENCE_DEPRECATION

class glview : public QOpenGLWidget {
  Q_OBJECT
 public:
  QPoint mPos;
  object_t object;
  int scaleVal = 1;
  int prev_scale = 1;
  glview(QWidget *parent = nullptr);
  void initializeGL() override;
  void paintGL() override;
  void mousePressEvent(QMouseEvent *) override;
  void mouseMoveEvent(QMouseEvent *) override;
  void wheelEvent(QWheelEvent *) override;

  int projection_type,        // Тип проекции
      edge_type,              // Тип ребра
      vertex_type;            // Тип вершины
  float background_color[4],  // Цвет фона {red, green, blue}
      edge_color[4],          // Цвет ребра {red, green, blue}
      vertex_color[4],        // Цвет вершины {red, green, blue}
      edge_width,             // Толщина ребра
      vertex_width;           // толщина вершины
};

#endif  // GLVIEW_H
