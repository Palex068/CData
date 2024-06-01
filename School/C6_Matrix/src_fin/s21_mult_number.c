#include "s21_matrix.h"
#include "s21_other.h"

/** @brief Умножение матрицы на число (mult_number)
 * @param matrix_t `*A` указатель на матрицу
 * @param double `number` множитель
 * @param matrix_t `*result` указатель на матрицу (результат)
 * @return `int` - `0` - `OK`, `ERROR` - `1` - Ошибка, некорректная матрица
 */
int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  // Проверка корректности матрицы
  if (matrix_existence(A) || !result) return ERROR;

  // Проверка матриц на одинаковый размер
  if (s21_create_matrix(A->rows, A->columns, result) != OK) return ERROR;

  // Умножение каждого элемента матрицы на число
  for (int i = 0; i < A->rows; i++)
    for (int j = 0; j < A->columns; j++)
      result->matrix[i][j] = A->matrix[i][j] * number;

  return OK;
}
