#include "s21_matrix.h"
#include "s21_other.h"

/** @brief Сложение (sum_matrix)
 * @param matrix_t `*A` указатель на матрицу (первое слагаемое)
 * @param matrix_t `*B` указатель на матрицу (второе слагаемое)
 * @param matrix_t `*result` указатель на матрицу (сумма)
 * @return `int` - `0` - `OK`, `ERROR` - `1` - Ошибка, некорректная матрица,
 * `CALC_ERROR` - `2` - Ошибка вычисления
 */
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  // Проверка корректности матриц
  if (matrix_existence(A) || matrix_existence(B) || !result) return ERROR;

  // Проверка матриц на одинаковый размер
  if (equal_size(A, B)) return CALC_ERROR;

  // Создание результирующей матрицы того же размера
  if (s21_create_matrix(A->rows, A->columns, result) != OK) return ERROR;

  // Суммирование каждого элемента
  for (int i = 0; i < A->rows; i++)
    for (int j = 0; j < A->columns; j++)
      result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];

  return OK;
}
