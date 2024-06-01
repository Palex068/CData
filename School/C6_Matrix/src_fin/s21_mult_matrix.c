#include "s21_matrix.h"
#include "s21_other.h"

/** @brief Умножение двух матриц (mult_matrix)
 * @param matrix_t `*A` указатель на матрицу (Первый множитель)
 * @param matrix_t `*B` указатель на матрицу (Второй множитель)
 * @param matrix_t `*result` указатель на матрицу (Произведение)
 * @return `int` - `0` - `OK`, `ERROR` - `1` - Ошибка, некорректная матрица,
 * `CALC_ERROR` - `2` - Ошибка вычисления
 */
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  // Проверка корректности матриц
  if (matrix_existence(A) || matrix_existence(B) || !result) return ERROR;

  // Проверка выполнения условия умножения
  if (mult_size(A, B)) return CALC_ERROR;

  // Создание результирующей матрицы специального размера
  if (s21_create_matrix(A->rows, B->columns, result) != OK) return ERROR;

  // Вычисление каждого элемента матрицы
  for (int i = 0; i < A->rows; i++)
    for (int j = 0; j < B->columns; j++)
      for (int k = 0; k < A->columns; k++)
        result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];

  return OK;
}
