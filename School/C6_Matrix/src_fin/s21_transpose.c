#include "s21_matrix.h"
#include "s21_other.h"

/** @brief Транспонирование матрицы (transpose) заключается в замене
 * строк этой матрицы ее столбцами с сохранением их номеров.
 * @param matrix_t `*A` указатель на исходную матрицу
 * @param matrix_t `*result` указатель на транспонированную матрицу
 * @return `int` - `0` - `OK`, `ERROR` - `1` - Ошибка, некорректная матрица
 */
int s21_transpose(matrix_t *A, matrix_t *result) {
  // Проверка корректности матриц
  if (matrix_existence(A) || !result) return ERROR;

  // Создание результирующей матрицы специального размера
  if (s21_create_matrix(A->columns, A->rows, result) != OK) return ERROR;

  // Транспонирование матрицы
  for (int i = 0; i < A->columns; i++)
    for (int j = 0; j < A->rows; j++) {
      result->matrix[i][j] = A->matrix[j][i];
    }

  return OK;
}
