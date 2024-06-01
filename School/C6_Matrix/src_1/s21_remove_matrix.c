#include "s21_matrix.h"
#include "s21_utils.h"

void s21_remove_matrix(matrix_t *A) {
  if (A != NULL || !matrix_error(A->rows, A->columns)) {
    for (int i = 0; i < A->rows; i++) free(A->matrix[i]);

    free(A->matrix);
  }

  A->rows = 0;
  A->columns = 0;
}
