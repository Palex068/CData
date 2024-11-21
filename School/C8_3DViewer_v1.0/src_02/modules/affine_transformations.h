#ifndef C8_3DVIEWER_V1_0_1_AFFINE_TRANSFORMATIONS_H
#define C8_3DVIEWER_V1_0_1_AFFINE_TRANSFORMATIONS_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_3dviewer.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif  // M_PI

void rotate_X(obj_data *obj, double angle);
void rotate_Y(obj_data *obj, double angle);
void rotate_Z(obj_data *obj, double angle);

void scale(obj_data *obj, const double k);

void move_X(obj_data *obj, const double k);
void move_Y(obj_data *obj, const double k);
void move_Z(obj_data *obj, const double k);

#endif  // C8_3DVIEWER_V1_0_1_AFFINE_TRANSFORMATIONS_H
