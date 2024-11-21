#include "glview.h"

#include <unistd.h>

glView::glView(QWidget *parent) : QOpenGLWidget(parent) {
  all_surfaces = NULL;
  all_points = NULL;
}

// вершинный буфер

void glView::paintGL() {
  glClearColor(background_color.redF(), background_color.greenF(),
               background_color.blueF(), background_color.alphaF());
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  projection();

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glRotatef(xRot_m, 1, 0, 0);
  glRotatef(yRot_m, 0, 1, 0);

  if (destroy) {
    if (p_type != NO) drawPoints();
    drawObj();
  }
}

void glView::destroy_all() {
  if (destroy) {
    if (all_surfaces != NULL) {
      for (int i = 0; i < count_surfaces; ++i) {
        free(all_surfaces[i].one_point);
      }
      free(all_surfaces);
    }
    if (all_points != NULL) {
      free(all_points);
    }
    destroy = false;
  }
}

void glView::paint_file_first() {
  destroy_all();
  all_surfaces = NULL;
  all_points = NULL;
  char file_str[1000] = {0};
  top_pointers = 0;
  edge = 0;
  count_surfaces = 0;
  scale = 1;
  QByteArray temp = filename.toLocal8Bit();
  strlcpy(file_str, temp.data(), filename.length() + 1);

  all_points = return_points(&top_pointers, file_str);
  all_surfaces = return_surfaces(&edge, &count_surfaces, file_str, all_points);
  if (all_points == NULL || all_surfaces == NULL)
    destroy = false;
  else
    destroy = true;
}

void glView::drawObj() {
  glLineWidth(edge_size);

  if (dotted_edge) {
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x1010);
  }
  for (int i = 0; i < count_surfaces; ++i) {
    for (int j = 0; j < all_surfaces[i].amount_of_points; ++j) {
      glBegin(GL_LINE_LOOP);
      glColor3d(edge_color.redF(), edge_color.greenF(), edge_color.blueF());
      glVertex3d(all_surfaces[i].one_point[j]->x,
                 all_surfaces[i].one_point[j]->y,
                 all_surfaces[i].one_point[j]->z);
    }
    glEnd();
  }
  if (dotted_edge) glDisable(GL_LINE_STIPPLE);
}

void glView::drawPoints() {
  if (p_type == SPHERE) glEnable(GL_POINT_SMOOTH);
  glPointSize(vertex_size);

  for (int i = 0; i < count_surfaces; ++i) {
    for (int j = 0; j < all_surfaces[i].amount_of_points; ++j) {
      glBegin(GL_POINTS);
      glColor3d(vertex_color.redF(), vertex_color.greenF(),
                vertex_color.blueF());
      glVertex3d(all_surfaces[i].one_point[j]->x,
                 all_surfaces[i].one_point[j]->y,
                 all_surfaces[i].one_point[j]->z);
    }
    glEnd();
  }
  if (p_type == SPHERE) glDisable(GL_POINT_SMOOTH);
}

void glView::mousePressEvent(QMouseEvent *mo) {
  // запоминаем координату мышки
  mPos = mo->pos();
}
void glView::mouseMoveEvent(QMouseEvent *mo) {
  xRot_m = 1 / M_PI * (mo->pos().y() - mPos.y());
  yRot_m = 1 / M_PI * (mo->pos().x() - mPos.x());
  update();
}

void glView::projection() {
  if (ortho) {
    glOrtho(-1.5, 1.5, -1.5, 1.5, -2, 1000);
  } else {
    glFrustum(-1, 1, -1, 1, 1, 99999);
    glTranslatef(0, 0, -2.8);
  }
}

bool glView::fileExists(QString path) {
  QFileInfo check_file(path);
  // check if file exists and if yes: Is it really a file and no directory?
  return check_file.exists() && check_file.isFile();
}

Point *glView::get_all_points() { return all_points; }

Surface *glView::get_all_surfaces() { return all_surfaces; }

int glView::get_top_pointers() { return top_pointers; }

int glView::get_count_surfaces() { return count_surfaces; }

int glView::get_edge() { return edge; }

void glView::set_scale() {
  if (destroy) {
    figure_scaling(top_pointers, scale, all_points);
    update();
  }
}
