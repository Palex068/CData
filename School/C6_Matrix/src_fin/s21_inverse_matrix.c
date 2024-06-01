#include "s21_matrix.h"
#include "s21_other.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  // Проверка корректности матриц
  if (matrix_existence(A) || !result) return ERROR;

  // Проверка определяющего условия
  if (matrix_equal_size(A)) return CALC_ERROR;

  double supNum = 0;
  matrix_t supMatrix = {0};

  // Проверка существования обратной матрицы
  if (s21_determinant(A, &supNum) != OK || supNum == 0) return CALC_ERROR;

  // Нахождение матрицы алгебраических дополнений
  if (s21_calc_complements(A, &supMatrix) != OK) return ERROR;

  // Транспонирование матрицы алгебраических дополнений
  matrix_t Tran = {0};
  s21_transpose(&supMatrix, &Tran);

  // Вычисление обратной матрицы
  supNum = 1.0 / supNum;
  s21_mult_number(&Tran, supNum, result);
  s21_remove_matrix(&supMatrix);
  s21_remove_matrix(&Tran);

  return OK;
}
