#include "s21_matrix.h"
#include "s21_other.h"

/** @brief Создание матриц (create_matrix)
 * @param int `rows` количество строк матрицы
 * @param int `columns` количество столбцов матрицы
 * @param matrix_t `*result` указатель на создаваемую матрицу
 * @return  `0` - OK `1` - Ошибка, некорректная матрица
 */
int s21_create_matrix(int rows, int columns, matrix_t *result) {
  // Проверка правильности построения матрицы
  if (matrix_error(rows, columns) || result == NULL) return ERROR;

  // Передача указанных данных
  result->rows = rows;
  result->columns = columns;
  result->matrix = (double **)calloc(rows, sizeof(double *));

  // Проверка ошибок при выделении памяти
  if (!result->matrix) return ERROR;

  // Выделение памяти для всей матрицы
  for (int i = 0; i < rows; i++) {
    result->matrix[i] = (double *)calloc(columns, sizeof(double));
  }
  return OK;
}
