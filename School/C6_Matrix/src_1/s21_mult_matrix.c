#include "s21_matrix.h"
#include "s21_utils.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  // Checking for correctness of matrices
  if (matrix_existence(A) || matrix_existence(B) || !result) return ERROR;

  // Checking for the multiplication condition
  if (mult_size(A, B)) return CALC_ERROR;

  // Creating a result matrix of the special size
  if (s21_create_matrix(A->rows, B->columns, result) != OK) return ERROR;

  // Multiplication of each matrix element
  for (int i = 0; i < A->rows; i++)
    for (int j = 0; j < B->columns; j++)
      for (int k = 0; k < A->columns; k++)
        result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];

  return OK;
}
