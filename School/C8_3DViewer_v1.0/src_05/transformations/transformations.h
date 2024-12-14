#ifndef __TRANSFORMATIONS_H__
#define __TRANSFORMATIONS_H__

#include <math.h>

#include "../common/common.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

double max_(double a, double b, double c);

void fill_transformation_matrix(Figure *figure);
void matrix_transpose(double **t_matrix);
void fill_rotation_matrix_crd(double **matrix, double alpha, int crd);
void rotate_helper(Figure *figure, int crd);

#endif