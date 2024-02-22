#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (rows < 1 || columns < 1 || !result) return INCORRECT_MATRIX;

  result->rows = rows;
  result->columns = columns;
  result->matrix = calloc(rows, sizeof(double *));

  if (!result->matrix) return INCORRECT_MATRIX;

  for (int i = 0; i < rows; i++) {
    result->matrix[i] = calloc(columns, sizeof(double));
    if (!result->matrix[i]) {
      s21_remove_matrix(result);
      return CALCULATION_ERROR;
    }
  }

  return OK;
}

void s21_remove_matrix(matrix_t *A) {
  if (A->matrix) {
    for (int i = 0; i < A->rows; i++)
      if (A->matrix[i]) free(A->matrix[i]);
    free(A->matrix);
    A->matrix = NULL;
  }
  A->rows = 0;
  A->columns = 0;
}

int iteraciyaDlyaLohov(matrix_t *A, matrix_t *B, int rows, int column) {
  if (A->rows == rows + 1 && A->columns == column + 1) return SUCCESS;

  if (fabs(A->matrix[rows][column] - B->matrix[rows][column]) > 1e-7)
    return FAILURE;

  int isEdgeColumn = column + 1 >= A->columns;

  return iteraciyaDlyaLohov(A, B, isEdgeColumn ? rows + 1 : rows,
                            isEdgeColumn ? 0 : column + 1);
}

int isEqualSize(matrix_t *A, matrix_t *B) {
  if (!A || !B || A->rows != B->rows || A->columns != B->columns)
    return FAILURE;
  return SUCCESS;
}

int isCorrect(matrix_t *A, matrix_t *B) {
  if (!A || !B || !A->matrix || !B->matrix || A->rows < 1 || A->columns < 1 ||
      B->rows < 1 || B->columns < 1)
    return FAILURE;
  return SUCCESS;
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  if (!isEqualSize(A, B)) return FAILURE;
  return iteraciyaDlyaLohov(A, B, 0, 0);
}

int resultHOF(matrix_t *A, matrix_t *B, matrix_t *result,
              double (*callback)(double, double), double *defaul) {
  if (!isCorrect(A, B)) return INCORRECT_MATRIX;
  if (!isEqualSize(A, B)) return CALCULATION_ERROR;

  int error = s21_create_matrix(A->rows, A->columns, result);
  if (error) return error;

  for (int i = 0; i < A->rows; i++)
    for (int j = 0; j < A->columns; j++)
      result->matrix[i][j] =
          callback(A->matrix[i][j], defaul ? *defaul : B->matrix[i][j]);

  return OK;
}

double sum(double a, double b) { return a + b; }

double sub(double a, double b) { return a - b; }

double mult(double a, double b) { return a * b; }

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  return resultHOF(A, B, result, sum, NULL);
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  return resultHOF(A, B, result, sub, NULL);
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  double newNubmer = number;
  return resultHOF(A, A, result, mult, &newNubmer);
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (!isCorrect(A, B)) return INCORRECT_MATRIX;
  if (A->columns != B->rows) return CALCULATION_ERROR;

  int error = s21_create_matrix(A->rows, B->columns, result);
  if (error) return error;

  for (int i = 0; i < A->rows; i++)
    for (int j = 0; j < B->columns; j++)
      for (int k = 0; k < B->rows; k++)
        result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];

  return OK;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  if (!isCorrect(A, A)) return INCORRECT_MATRIX;

  int error = s21_create_matrix(A->columns, A->rows, result);
  if (error) return error;

  for (int i = 0; i < A->rows; ++i)
    for (int j = 0; j < A->columns; ++j) result->matrix[j][i] = A->matrix[i][j];

  return OK;
}

void minor(int rows, int columns, matrix_t *A, matrix_t *B) {
  int $rows = 0;
  int $columns = 0;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (j != columns && i != rows) {
        B->matrix[$rows][$columns] = A->matrix[i][j];
        $columns++;
        if ($columns == A->columns - 1) {
          $rows++;
          $columns = 0;
        }
      }
    }
  }
}

int s21_determinant(matrix_t *A, double *result) {
  if (!isCorrect(A, A)) return INCORRECT_MATRIX;
  if (A->rows != A->columns) return CALCULATION_ERROR;

  if (A->rows == 1) *result = A->matrix[0][0];
  if (A->rows == 2)
    *result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];

  int res = OK;
  if (A->rows > 2) {
    for (int i = 0; i < A->rows; i++) {
      matrix_t temp = {0};
      res = s21_create_matrix(A->rows - 1, A->columns - 1, &temp);
      minor(0, i, A, &temp);
      double tmp = 0;
      s21_determinant(&temp, &tmp);
      *result += powf(-1, i) * tmp * A->matrix[0][i];
      s21_remove_matrix(&temp);
    }
  }
  return res;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (!isCorrect(A, A)) return INCORRECT_MATRIX;
  if (A->columns != A->rows || A->rows == 1) return CALCULATION_ERROR;

  matrix_t temp = {0};
  int error = s21_create_matrix(A->rows - 1, A->columns - 1, &temp);
  if (error) return error;

  error = s21_create_matrix(A->rows, A->columns, result);
  if (error) return error;

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      double tmp = 0;
      minor(i, j, A, &temp);
      s21_determinant(&temp, &tmp);
      result->matrix[i][j] = tmp * pow(-1, i + j);
    }
  }

  return OK;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  double d = 0;
  if (!isCorrect(A, A)) return INCORRECT_MATRIX;
  if (s21_determinant(A, &d) || !d) return CALCULATION_ERROR;
  if (A->rows == 1) {
    int error = s21_create_matrix(1, 1, result);
    if (error) return error;
    result->matrix[0][0] = 1.0 / A->matrix[0][0];
  } else {
    matrix_t G = {0};
    s21_calc_complements(A, &G);
    matrix_t GTrans = {0};
    s21_transpose(&G, &GTrans);
    s21_mult_number(&GTrans, 1 / d, result);
    s21_remove_matrix(&GTrans);
    s21_remove_matrix(&G);
  }
  return OK;
}