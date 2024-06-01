#include "s21_matrix.h"
#include "s21_other.h"

/** @brief Очистка матриц (remove_matrix)
 * @param matrix_t  `*A` указатель на удаляемую матрицу
 */
void s21_remove_matrix(matrix_t *A) {
  if (A != NULL || !matrix_error(A->rows, A->columns)) {
    // Освобождаем память строк
    for (int i = 0; i < A->rows; i++) free(A->matrix[i]);
    // Освобождаем память 0 столбца
    free(A->matrix);
    A->matrix = NULL;
  }
  A->rows = 0;
  A->columns = 0;
}
