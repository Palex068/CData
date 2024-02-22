#include "s21_matrix.h"
#include "s21_utils.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  // Checking for correctness of matrices
  if (matrix_existence(A) || !result) return ERROR;

  // Checking for the determinant condition
  if (matrix_equal_size(A)) return CALC_ERROR;

  // Creating a result matrix of the special size
  if (s21_create_matrix(A->rows, A->columns, result) != OK) return ERROR;

  // Minor matrix completion
  for (int i = 0; i < A->rows; i++)
    for (int j = 0; j < A->columns; j++) {
      matrix_t supMatrix = {0};
      double supNum = 0;
      int sign = ((i + j) % 2 == 0) ? 1 : -1;

      matrix_reduction(A, &supMatrix, i, j);
      s21_determinant(&supMatrix, &supNum);

      result->matrix[i][j] = sign * supNum;

      s21_remove_matrix(&supMatrix);
    }

  return OK;
}
