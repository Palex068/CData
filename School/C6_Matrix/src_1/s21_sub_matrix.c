#include "s21_matrix.h"
#include "s21_utils.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  // Checking for correctness of matrices
  if (matrix_existence(A) || matrix_existence(B) || !result) return ERROR;

  // Checking matrices for equal size
  if (equal_size(A, B)) return CALC_ERROR;

  // Creating a result matrix of the same size
  if (s21_create_matrix(A->rows, A->columns, result) != OK) return ERROR;

  // Subtraction up each element
  for (int i = 0; i < A->rows; i++)
    for (int j = 0; j < A->columns; j++)
      result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];

  return OK;
}
