#include "s21_matrix.h"
#include "s21_other.h"

/** @brief Сравнение матриц (eq_matrix)
 * @param matrix_t `*A` указатель на матрицу
 * @param matrix_t `*B` указатель на матрицу
 * @return  `SUCCESS` - `1` - OK `FAILURE` - `0` - Ошибка
 */
int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  // Checking for correctness of matrix creation and equal size
  if (matrix_existence(A) || matrix_existence(B) || equal_size(A, B))
    return FAILURE;

  // Сравнение каждого элемента матриц с учетом точности сравнения
  for (int i = 0; i < A->rows; i++)
    for (int j = 0; j < A->columns; j++)
      if (fabs(A->matrix[i][j] - B->matrix[i][j]) > FRACTURE_CHECK)
        return FAILURE;

  return SUCCESS;
}
