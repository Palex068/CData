#include "s21_matrix.h"
#include "s21_other.h"

/** @brief Определитель матрицы (determinant)
 * @param matrix_t `*A` указатель на матрицу
 * @param matrix_t `*result` указатель на определитель
 * @return `int` - `0` - `OK`, `ERROR` - `1` - Ошибка, некорректная матрица,
 * `CALC_ERROR` - `2` - Ошибка вычисления
 */
int s21_determinant(matrix_t *A, double *result) {
  // Проверка правильности матрицы и числа
  if (matrix_existence(A) || !result) return ERROR;

  // Проверка определяющего условия
  if (matrix_equal_size(A)) return CALC_ERROR;

  // Нахождение определителя
  *result = det(A);

  return OK;
}
