#include "s21_matrix.h"
#include "s21_utils.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  // Checking for correctness of matrices
  if (matrix_existence(A) || !result) return ERROR;

  // Creating a result matrix of the special size
  if (s21_create_matrix(A->columns, A->rows, result) != OK) return ERROR;

  // Matrix transpose
  for (int i = 0; i < A->columns; i++)
    for (int j = 0; j < A->rows; j++) result->matrix[i][j] = A->matrix[j][i];

  return OK;
}
