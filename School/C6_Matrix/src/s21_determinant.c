#include "s21_matrix.h"
#include "s21_utils.h"

int s21_determinant(matrix_t *A, double *result) {
  // Checking for correctness of matrix and number
  if (matrix_existence(A) || !result) return ERROR;

  // Checking for the determinant condition
  if (matrix_equal_size(A)) return CALC_ERROR;

  // Finding the determinant
  *result = det(A);

  return OK;
}
