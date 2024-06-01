#ifndef S21_OTHER_H
#define S21_OTHER_H

#include "s21_matrix.h"

int matrix_error(int rows, int columns);
int equal_size(matrix_t *A, matrix_t *B);
int matrix_existence(matrix_t *A);
int mult_size(matrix_t *A, matrix_t *B);
int matrix_equal_size(matrix_t *A);

double det(matrix_t *A);
double det_2x2(matrix_t *A);
void s21_minor(matrix_t *A, matrix_t *res, int row, int column);

double get_rand(double min, double max);

#endif  // S21_OTHER_H
