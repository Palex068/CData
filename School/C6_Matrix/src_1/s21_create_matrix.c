#include "s21_matrix.h"
#include "s21_utils.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  // Checking for correctness of matrix creation
  if (matrix_error(rows, columns) || result == NULL) return ERROR;

  // Transmission of specified data
  result->rows = rows;
  result->columns = columns;
  result->matrix = (double **)calloc(rows, sizeof(double *));

  // Memory allocation error accounting
  if (!result->matrix) return ERROR;

  // Memory allocation for the whole matrix
  for (int i = 0; i < rows; i++)
    result->matrix[i] = (double *)calloc(columns, sizeof(double));

  // It is impossible to recreate a memory leak in this case (code coverage is
  // lost, but it is worth generating an error and freeing memory)

  return OK;
}
