#include "test.h"

START_TEST(eq_matrix_1) {
  // Checking equal matrix
  const int rows = rand() % 100 + 1;
  const int columns = rand() % 100 + 1;
  matrix_t test1 = {0};
  matrix_t test2 = {0};
  s21_create_matrix(rows, columns, &test1);
  s21_create_matrix(rows, columns, &test2);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      double random = get_rand(__DBL_MIN__, __DBL_MAX__);
      test1.matrix[i][j] = random;
      test2.matrix[i][j] = random;
    }
  }
  ck_assert_int_eq(s21_eq_matrix(&test1, &test2), SUCCESS);
  s21_remove_matrix(&test1);
  s21_remove_matrix(&test2);
}
END_TEST

START_TEST(eq_matrix_2) {
  // The number of rows of each matrix is 0
  const int rows = 0;
  const int columns = rand() % 100 + 1;
  matrix_t test1 = {0};
  matrix_t test2 = {0};
  s21_create_matrix(rows, columns, &test1);
  s21_create_matrix(rows, columns, &test2);
  ck_assert_int_eq(s21_eq_matrix(&test1, &test2), FAILURE);
}
END_TEST

START_TEST(eq_matrix_3) {
  // The number of rows is different
  const int rows1 = 5;
  const int rows2 = 6;
  const int columns = rand() % 100 + 1;
  matrix_t test1 = {0};
  matrix_t test2 = {0};
  s21_create_matrix(rows1, columns, &test1);
  s21_create_matrix(rows2, columns, &test2);
  for (int i = 0; i < rows2; i++) {
    for (int j = 0; j < columns; j++) {
      double random = get_rand(__DBL_MIN__, __DBL_MAX__);
      if (i != 5) test1.matrix[i][j] = random;
      test2.matrix[i][j] = random;
    }
  }
  ck_assert_int_eq(s21_eq_matrix(&test1, &test2), FAILURE);
  s21_remove_matrix(&test1);
  s21_remove_matrix(&test2);
}
END_TEST

START_TEST(eq_matrix_4) {
  // The number of columns is different
  const int rows = rand() % 100 + 1;
  const int columns1 = 5;
  const int columns2 = 6;
  matrix_t test1 = {0};
  matrix_t test2 = {0};
  s21_create_matrix(rows, columns1, &test1);
  s21_create_matrix(rows, columns2, &test2);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns2; j++) {
      double random = get_rand(__DBL_MIN__, __DBL_MAX__);
      if (j != 5) test1.matrix[i][j] = random;
      test2.matrix[i][j] = random;
    }
  }
  ck_assert_int_eq(s21_eq_matrix(&test1, &test2), FAILURE);
  s21_remove_matrix(&test1);
  s21_remove_matrix(&test2);
}
END_TEST

START_TEST(eq_matrix_5) {
  // Both matrices are NULL
  ck_assert_int_eq(s21_eq_matrix(NULL, NULL), FAILURE);
}
END_TEST

START_TEST(eq_matrix_6) {
  // One number in second matrix is different
  const int rows = rand() % 100 + 1;
  const int columns = rand() % 100 + 1;
  matrix_t test1 = {0};
  matrix_t test2 = {0};
  s21_create_matrix(rows, columns, &test1);
  s21_create_matrix(rows, columns, &test2);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      double random = get_rand(__DBL_MIN__, __DBL_MAX__);
      test1.matrix[i][j] = random;
      test2.matrix[i][j] = random;
      if (i == (rows - 1) && j == (columns - 1)) {
        test1.matrix[i][j] = 0.000005;
        test2.matrix[i][j] = 0.000007;
      }
    }
  }
  ck_assert_int_eq(s21_eq_matrix(&test1, &test2), FAILURE);
  s21_remove_matrix(&test1);
  s21_remove_matrix(&test2);
}
END_TEST

Suite *s21_tests_eq_matrix(void) {
  Suite *s = suite_create("s21_eq_matrix");
  TCase *tc = tcase_create("s21_matrix");
  suite_add_tcase(s, tc);

  tcase_add_test(tc, eq_matrix_1);
  tcase_add_test(tc, eq_matrix_2);
  tcase_add_test(tc, eq_matrix_3);
  tcase_add_test(tc, eq_matrix_4);
  tcase_add_test(tc, eq_matrix_5);
  tcase_add_test(tc, eq_matrix_6);
  return s;
}