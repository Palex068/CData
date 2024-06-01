#include "s21_matrix.h"
#include "s21_utils.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  // Checking for correctness of matrix creation and equal size
  if (matrix_existence(A) || matrix_existence(B) || equal_size(A, B))
    return FAILURE;

  // Comparison of each element of matrices
  for (int i = 0; i < A->rows; i++)
    for (int j = 0; j < A->columns; j++)
      if (fabs(A->matrix[i][j] - B->matrix[i][j]) > FRACTURE_CHECK)
        return FAILURE;

  return SUCCESS;
}
