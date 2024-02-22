#include "s21_matrix.h"
#include "s21_utils.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  // Checking for correctness of matrices
  if (matrix_existence(A) || !result) return ERROR;

  // Creating a result matrix of the same size
  if (s21_create_matrix(A->rows, A->columns, result) != OK) return ERROR;

  // Multiplication of each matrix element by a number
  for (int i = 0; i < A->rows; i++)
    for (int j = 0; j < A->columns; j++)
      result->matrix[i][j] = A->matrix[i][j] * number;

  return OK;
}
