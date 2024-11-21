#ifndef C8_3DVIEWER_V1_0_1_S21_3DVIEWER_H
#define C8_3DVIEWER_V1_0_1_S21_3DVIEWER_H

#define _GNU_SOURCE
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct to render 3d wireframe from Wavefront .obj file
typedef struct data {
  size_t vertices_count;
  double *vertices_arr;
  size_t vertex_indices_count;
  int *vertex_indices_arr;
} obj_data;

enum exec_statuses { OK, ERROR };

#endif  // C8_3DVIEWER_V1_0_1_S21_3DVIEWER_H
