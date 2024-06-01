#include "s21_other.h"

/** @brief Проверка матрицы на наличие строк и столбцов (больше 0)
 * @param int `rows` количество строк
 * @param int `columns` количество столбцов
 * @return `int` - `0` - OK `1` - Ошибка, некорректная матрица
 */
int matrix_error(int rows, int columns) { return rows < 1 || columns < 1; }

/** @brief Проверка матрицы на существование и наличие строк и столбцов (больше
 * 0)
 * @param matrix_t `*A` указатель на матрицу
 * @return `int` - `0` - OK `1` - Ошибка, некорректная матрица
 */
int matrix_existence(matrix_t *A) {
  return !A || A->rows < 1 || A->columns < 1;
}

/** @brief Сравнение количества строк и столбцов двух матриц
 * @param matrix_t `*A` указатель на матрицу
 * @param matrix_t `*B` указатель на матрицу
 * @return `int` - `0` - OK, равны `1` - Ошибка, не равны
 */
int equal_size(matrix_t *A, matrix_t *B) {
  return A->rows != B->rows || A->columns != B->columns;
}

/** @brief Проверка размеров матриц для умножения
 * @param matrix_t `*A` указатель на матрицу (Первый множитель)
 * @param matrix_t `*B` указатель на матрицу (Второй множитель)
 * @return `int` - `0` - OK `1` - Ошибка, некорректная матрица
 */
int mult_size(matrix_t *A, matrix_t *B) { return A->columns != B->rows; }

/** @brief Сравнение строк и столбцов матрицы (равенство)
 * @param matrix_t `*A` указатель на матрицу
 * @return `int` - `0` - OK `1` - Ошибка, некорректная матрица
 */
int matrix_equal_size(matrix_t *A) { return A->columns != A->rows; }

/** @brief Нахождение определителя матрицы
 * @param matrix_t `*A` указатель на матрицу
 * @return `double` Определитель матрицы
 */
double det(matrix_t *A) {
  int matrixRow = A->rows;
  double result = A->matrix[0][0];

  if (matrixRow > 2) {
    int changeSign = 1;
    result = 0;

    for (int i = 0; i < A->rows; i++) {
      matrix_t supMatrix = {0};

      s21_minor(A, &supMatrix, 0, i);

      result += changeSign * A->matrix[0][i] * det(&supMatrix);

      changeSign *= -1;

      s21_remove_matrix(&supMatrix);
    }
  }

  if (matrixRow == 2) result = det_2x2(A);

  return result;
}

/** @brief Нахождение определителя матрицы 2x2
 * @param matrix_t `*A` указатель на матрицу
 * @return `double` Определитель матрицы
 */
double det_2x2(matrix_t *A) {
  return A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
}

/** @brief Матрица миноров
 * @param matrix_t `*A` указатель на матрицу
 * @param matrix_t `*result` указатель на матрицу миноров
 * @param int `rows` строка
 * @param int `columns` столбец
 */
void s21_minor(matrix_t *A, matrix_t *res, int row, int column) {
  s21_create_matrix(A->rows - 1, A->rows - 1, res);

  for (int i = 0, iSup = 0; i < A->rows; i++) {
    if (i == row) continue;
    for (int j = 0, jSup = 0; j < A->columns; j++) {
      if (j == column) continue;
      res->matrix[iSup][jSup] = A->matrix[i][j];
      jSup++;
    }
    iSup++;
  }
}

/** @brief Нахождение случайного числа типа double из переданного диапазона
 * @param double `min` начало диапазона
 * @param double `max` окончание диапазона
 * @return `double` случайное число
 */
double get_rand(double min, double max) {
  double val = (double)rand() / RAND_MAX;
  return min + val * (max - min);
}
