#define GL_SILENCE_DEPRECATION
#include "viewer.h"

#include <iostream>

Viewer::Viewer(QWidget *parent) : QOpenGLWidget{parent} {}
void Viewer::initializeGL() { initializeOpenGLFunctions(); }

void Viewer::parseOBJ() {
  free_data();
  s21_parse_file(name_to_file, &facets, &number_of_lines, &facets_length,
                 &number_of_vertices, &vertices);
  s21_center_vertices(&vertices, number_of_vertices);
  s21_initial_scale(&vertices, number_of_vertices);
}

void Viewer::paintGL() {
  glEnable(GL_DEPTH_TEST);
  glClearColor(bg_color.redF(), bg_color.greenF(), bg_color.blueF(), 0.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  projection_view();

  glPointSize(point_size / 5);
  if (point_type == 0) {
    glEnable(GL_POINT_SMOOTH);
  }
  if (point_type != 2) {
    glBegin(GL_POINTS);
    glColor3f(point_color.redF(), point_color.greenF(), point_color.blueF());
    for (int i = 0; i < number_of_vertices; i++) {
      glVertex3d(vertices[i * 3], vertices[i * 3 + 1], vertices[i * 3 + 2]);
    }
    glEnd();
  }
  if (point_type == 0) {
    glDisable(GL_POINT_SMOOTH);
  }

  if (line_type == 1) {
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 26);
  }

  glLineWidth(line_size / 15);

  if (line_type != 2) {
    glColor3f(line_color.redF(), line_color.greenF(), line_color.blueF());
    glVertexPointer(3, GL_DOUBLE, 0, vertices);
    glEnableClientState(GL_VERTEX_ARRAY);
    glDrawElements(GL_LINES, facets_length, GL_UNSIGNED_INT, facets);
    glDisableClientState(GL_VERTEX_ARRAY);

    if (line_type == 1) {
      glDisable(GL_LINE_STIPPLE);
    }
  }
}

void Viewer::shift_view(double shifted, int ax) {
  if (ax == 0) {
    s21_shift(&vertices, number_of_vertices, shifted, 0, 0);
  } else if (ax == 1) {
    s21_shift(&vertices, number_of_vertices, 0, shifted, 0);
  } else {
    s21_shift(&vertices, number_of_vertices, 0, 0, shifted);
  }

  update();
}
void Viewer::scale_view(double scale) {
  s21_scale(&vertices, number_of_vertices, scale);
  update();
}

void Viewer::rotate_view(double degrees, int ax) {
  s21_rotate(&vertices, number_of_vertices, degrees, ax);
  update();
}

void Viewer::projection_view() {
  if (projection_type == 0) {
    glOrtho(-1, 1, -1, 1, 0, 15);
    glTranslated(0, 0, -6);
  } else {
    glFrustum(-1, 1, -1, 1, 5, 20);
    glTranslated(0, 0, -8);
  }
}

void Viewer::free_data() {
  if (facets != NULL) {
    free(facets);
    facets = NULL;
  }

  if (vertices != NULL) {
    free(vertices);
    vertices = NULL;
  }
}