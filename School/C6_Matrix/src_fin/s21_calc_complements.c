#include "s21_matrix.h"
#include "s21_other.h"

/** @brief Минор матрицы и матрица алгебраических дополнений (calc_complements)
 * @param matrix_t `*A` указатель на исходную матрицу
 * @param matrix_t `*result` указатель на транспонированную матрицу
 * @return `int` - `0` - `OK`, `ERROR` - `1` - Ошибка, некорректная матрица
 */
int s21_calc_complements(matrix_t *A, matrix_t *result) {
  // Проверка корректности матрицы
  if (matrix_existence(A) || !result) return ERROR;

  // Проверка определяющего условия (равенство количества строк и столбцов)
  if (matrix_equal_size(A)) return CALC_ERROR;

  // Создание результирующей матрицы, равной исходной
  if (s21_create_matrix(A->rows, A->columns, result) != OK) return ERROR;

  // Заполняем матрицу алгебраических дополнений
  for (int i = 0; i < A->rows; i++)
    for (int j = 0; j < A->columns; j++) {
      matrix_t supMatrix = {0};
      double supNum = 0;
      int sign = ((i + j) % 2 == 0) ? 1 : -1;

      s21_minor(A, &supMatrix, i, j);
      s21_determinant(&supMatrix, &supNum);

      result->matrix[i][j] = sign * supNum;

      s21_remove_matrix(&supMatrix);
    }

  return OK;
}
