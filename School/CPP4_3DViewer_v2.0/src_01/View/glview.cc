#include "glview.h"

glView::glView(QWidget *parent) : QOpenGLWidget(parent) {}

void glView::SetBackgroundColor(QColor color) { background_color_ = color; }

void glView::paintGL() {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  Projection();  // Вызываем функцию настройки проекци

  float r, g, b, a;

  QColorToRGB(background_color_, r, g, b, a);
  glClearColor(r, g, b, a);  // Устанавливаем цвет фона

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glRotatef(x_rot_m_, 1, 0, 0);
  glRotatef(y_rot_m_, 0, 1, 0);

  if (p_type_ != 'n') DrawPoints();
  DrawObj();
}

void glView::initializeGL() {
  glEnable(GL_DEPTH_TEST);
}

void glView::DrawObj() {
  glLineWidth(edge_size_);

  if (dotted_edge_) {
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x1010);
  }

  for (int i = 0; i < c_->GetCountSurfaces(); ++i) {
    for (int j = 0; j < c_->GetVertexInSurface(i); ++j) {
      glBegin(GL_LINE_LOOP);
      SetColor(edge_color_);
      glVertex3d(c_->GetX(i, j), c_->GetY(i, j), c_->GetZ(i, j));
    }
    glEnd();
  }
  if (dotted_edge_) glDisable(GL_LINE_STIPPLE);
}

void glView::DrawPoints() {
  if (p_type_ == 's') glEnable(GL_POINT_SMOOTH);
  glPointSize(vertex_size_);

  for (int i = 0; i < c_->GetCountSurfaces(); ++i) {
    for (int j = 0; j < c_->GetVertexInSurface(i); ++j) {
      glBegin(GL_POINTS);
      SetColor(vertex_color_);
      glVertex3d(c_->GetX(i, j), c_->GetY(i, j), c_->GetZ(i, j));
    }
    glEnd();
  }
  if (p_type_ == 's') glDisable(GL_POINT_SMOOTH);
}

void glView::Projection() {
  if (ortho_) {
    glOrtho(-1.5, 1.5, -1.5, 1.5, -2, 1000);
  } else {
    glFrustum(-1, 1, -1, 1, 1, 99999);
    glTranslatef(0, 0, -2.8);
  }
}

void glView::QColorToRGB(const QColor &color, float &r, float &g, float &b,
                         float &a) const {
  r = color.redF();
  g = color.greenF();
  b = color.blueF();
  a = color.alphaF();
}

void glView::SetColor(QColor color) const {
  glColor3d(color.redF(), color.greenF(), color.blueF());
}

void glView::SetEdge(bool dotted, QColor color, float size) {
  edge_color_ = color;
  edge_size_ = size;
  dotted_edge_ = dotted;
}

void glView::SetVertex(QColor color, float size, char p_type) {
  vertex_color_ = color;
  vertex_size_ = size;
  p_type_ = p_type;
}

void glView::mousePressEvent(QMouseEvent *mo) {
  // запоминаем координату мышки
  m_pos_ = mo->pos();
}
void glView::mouseMoveEvent(QMouseEvent *mo) {
  x_rot_m_ = 1 / M_PI * (mo->pos().y() - m_pos_.y());
  y_rot_m_ = 1 / M_PI * (mo->pos().x() - m_pos_.x());
  update();
}
