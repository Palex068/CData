#include "s21_utils.h"

// Checking a matrix for a given number of rows and columns
int matrix_error(int rows, int columns) { return rows < 1 || columns < 1; }

// Checking a given matrix
int matrix_existence(matrix_t *A) {
  return !A || A->rows < 1 || A->columns < 1;
}

// Comparison of rows and columns of two matrices
int equal_size(matrix_t *A, matrix_t *B) {
  return A->rows != B->rows || A->columns != B->columns;
}

// Matrix multiplication comparison
int mult_size(matrix_t *A, matrix_t *B) { return A->columns != B->rows; }

// Comparison of rows and columns of matricex
int matrix_equal_size(matrix_t *A) { return A->columns != A->rows; }

// Finding determinant for matrix
double det(matrix_t *A) {
  int matrixRow = A->rows;
  double result = A->matrix[0][0];

  if (matrixRow > 2) {
    int changeSign = 1;
    result = 0;

    for (int i = 0; i < A->rows; i++) {
      matrix_t supMatrix = {0};

      matrix_reduction(A, &supMatrix, 0, i);

      result += changeSign * A->matrix[0][i] * det(&supMatrix);

      changeSign *= -1;

      s21_remove_matrix(&supMatrix);
    }
  }

  if (matrixRow == 2) result = doub_det(A);

  return result;
}

// Finding determinant for 2x2 matrix
double doub_det(matrix_t *A) {
  return A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
}

// Reduction matrix with chosen row and columns
void matrix_reduction(matrix_t *A, matrix_t *res, int row, int column) {
  s21_create_matrix(A->rows - 1, A->rows - 1, res);

  for (int i = 0, iSup = 0; i < A->rows; i++) {
    if (i == row) continue;
    for (int j = 0, jSup = 0; j < A->columns; j++) {
      if (j == column) continue;
      res->matrix[iSup][jSup] = A->matrix[i][j];
      jSup += 1;
    }
    iSup += 1;
  }
}

// Finding a random number of type double
double get_rand(double min, double max) {
  double val = (double)rand() / RAND_MAX;
  return min + val * (max - min);
}
