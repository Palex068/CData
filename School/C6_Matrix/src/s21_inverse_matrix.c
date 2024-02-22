#include "s21_matrix.h"
#include "s21_utils.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  // Checking for correctness of matrices
  if (matrix_existence(A) || !result) return ERROR;

  // Checking for the determinant condition
  if (matrix_equal_size(A)) return CALC_ERROR;

  // Creating support parametres
  double supNum = 0;
  matrix_t supMatrix = {0};

  // Creating a result matrix and support matrix of the special size
  if (s21_create_matrix(A->rows, A->columns, result) != OK) return ERROR;
  if (s21_create_matrix(A->rows, A->columns, &supMatrix) != OK) return ERROR;

  // Checking for the inverse condition
  if (s21_determinant(A, &supNum) != OK || supNum == 0) return CALC_ERROR;

  // Finding the matrix of algebraic complements
  if (s21_calc_complements(A, &supMatrix) != OK) return ERROR;

  // The transpose of matrix of algebraic complements
  s21_transpose(&supMatrix, A);

  // Calculation the inverse matrix
  supNum = 1 / supNum;
  s21_mult_number(A, supNum, result);

  return OK;
}
