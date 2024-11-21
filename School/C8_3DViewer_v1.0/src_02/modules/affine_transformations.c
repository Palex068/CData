#include "affine_transformations.h"

void rotate_X(obj_data *obj, double angle) {
  angle = angle * M_PI / 180;
  for (size_t i = 0; i < obj->vertices_count * 3; i += 3) {
    double Y = obj->vertices_arr[i + 1];
    double Z = obj->vertices_arr[i + 2];
    obj->vertices_arr[i + 1] = Y * cos(angle) + Z * sin(angle);
    obj->vertices_arr[i + 2] = -Y * sin(angle) + Z * cos(angle);
  }
}

void rotate_Y(obj_data *obj, double angle) {
  angle = angle * M_PI / 180;
  for (size_t i = 0; i < obj->vertices_count * 3; i += 3) {
    double X = obj->vertices_arr[i];
    double Z = obj->vertices_arr[i + 2];
    obj->vertices_arr[i] = X * cos(angle) + Z * sin(angle);
    obj->vertices_arr[i + 2] = -X * sin(angle) + Z * cos(angle);
  }
}

void rotate_Z(obj_data *obj, double angle) {
  angle = angle * M_PI / 180;
  for (size_t i = 0; i < obj->vertices_count * 3; i += 3) {
    double X = obj->vertices_arr[i];
    double Y = obj->vertices_arr[i + 1];
    obj->vertices_arr[i] = X * cos(angle) + Y * sin(angle);
    obj->vertices_arr[i + 1] = -X * sin(angle) + Y * cos(angle);
  }
}

void scale(obj_data *obj, const double k) {
  if (k != 0) {
    for (size_t i = 0; i < obj->vertices_count * 3; i++) {
      obj->vertices_arr[i] *= k;
    }
  }
}

void move_X(obj_data *obj, const double k) {
  for (size_t i = 0; i < obj->vertices_count * 3; i += 3) {
    obj->vertices_arr[i] += k;
  }
}

void move_Y(obj_data *obj, const double k) {
  for (size_t i = 1; i < obj->vertices_count * 3; i += 3) {
    obj->vertices_arr[i] += k;
  }
}

void move_Z(obj_data *obj, const double k) {
  for (size_t i = 2; i < obj->vertices_count * 3; i += 3) {
    obj->vertices_arr[i] += k;
  }
}