#ifndef GLVIEW_H
#define GLVIEW_H
#define GL_SILENCE_DEPRECATION

#include <QColor>
#include <QMouseEvent>
#include <QOpenGLWidget>

#include "../Controller/controller.h"

class glView : public QOpenGLWidget {
  Q_OBJECT
 public:
  glView(QWidget *parent = nullptr);

  bool GetIsOrtho() const { return ortho_; };
  QColor GetBackgroundColor() const { return background_color_; }

  QColor GetVertexColor() const { return vertex_color_; }
  char GetVertexType() const { return p_type_; }
  float GetVertexSize() const { return vertex_size_; }

  QColor GetEdgeColor() const { return edge_color_; }
  bool GetIsDottedEdge() const { return dotted_edge_; }
  float GetEdgeSize() const { return edge_size_; }

  void SetData(s21::Controller *controller) { c_ = controller; };

  void SetBackgroundColor(QColor color = Qt::black);
  ;
  void SetIsOrtho(bool ortho) { ortho_ = ortho; }

  void SetEdge(bool dotted = false, QColor color = Qt::white, float size = 0.5);
  void SetEdgeSize(float size = 0.5) { edge_size_ = size; }
  void SetEdgeColor(QColor color) { edge_color_ = color; }
  void SetIsDottedEdge(bool dotted) { dotted_edge_ = dotted; }

  void SetVertex(QColor color = Qt::green, float size = 0.5, char p_type = 'n');
  void SetVertexType(char p_type) { p_type_ = p_type; }
  void SetVertexSize(float size = 0.5) { vertex_size_ = size; }
  void SetVertexColor(QColor color) { vertex_color_ = color; }

 protected:
  void paintGL() override;
  void initializeGL() override;

 private:
  void mousePressEvent(QMouseEvent *mo) override;
  void mouseMoveEvent(QMouseEvent *mo) override;
  // для движения мышкой

  void SetColor(QColor color) const;
  void QColorToRGB(const QColor &color, float &r, float &g, float &b,
                   float &a) const;

  void Projection();
  // проекции

  void DrawObj();
  void DrawPoints();

 private:
  s21::Controller *c_ = nullptr;

  float x_rot_m_ = 0, y_rot_m_ = 0;
  QPoint m_pos_;

  bool ortho_ = true;
  // проекции

  QColor background_color_ = Qt::black;
  QColor vertex_color_ = Qt::white, edge_color_ = Qt::white;
  float vertex_size_ = 0.5, edge_size_ = 0.5;
  // цвет и размер вершин и линий

  char p_type_ = 'n';
  // тип точек(куб 'c', сфера 's' или их нет 'n')

  bool dotted_edge_ = false;
  // пунктирная ли линия
};

#endif  // GLVIEW_H
