#include "test.h"

START_TEST(transpose_1) {
  // Checking matrix with same number
  const int rows = rand() % 100 + 1;
  const int columns = rand() % 100 + 1;
  matrix_t test = {0};
  matrix_t total = {0};
  matrix_t check = {0};
  s21_create_matrix(rows, columns, &test);
  s21_create_matrix(columns, rows, &total);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      test.matrix[i][j] = 1;
      total.matrix[j][i] = 1;
    }
  }
  ck_assert_int_eq(s21_transpose(&test, &check), OK);
  ck_assert_int_eq(s21_eq_matrix(&total, &check), SUCCESS);
  s21_remove_matrix(&test);
  s21_remove_matrix(&total);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(transpose_2) {
  // Random number subtraction
  const int rows = rand() % 100 + 1;
  const int columns = rand() % 100 + 1;
  matrix_t test = {0};
  matrix_t check = {0};
  matrix_t total = {0};
  s21_create_matrix(rows, columns, &test);
  s21_create_matrix(columns, rows, &total);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      double randomNum = get_rand(DBL_MIN, DBL_MAX);
      test.matrix[i][j] = randomNum;
      total.matrix[j][i] = randomNum;
    }
  }
  ck_assert_int_eq(s21_transpose(&test, &check), OK);
  ck_assert_int_eq(s21_eq_matrix(&total, &check), SUCCESS);
  s21_remove_matrix(&test);
  s21_remove_matrix(&check);
  s21_remove_matrix(&total);
}
END_TEST

START_TEST(transpose_3) {
  // Result matrix is NULL
  const int rows = rand() % 100 + 1;
  const int columns = rand() % 100 + 1;
  matrix_t test = {0};
  s21_create_matrix(rows, columns, &test);
  ck_assert_int_eq(s21_transpose(&test, NULL), ERROR);
  s21_remove_matrix(&test);
}
END_TEST

START_TEST(transpose_4) {
  // Set matrix is NULL
  matrix_t check = {0};
  ck_assert_int_eq(s21_transpose(NULL, &check), ERROR);
}
END_TEST

Suite *s21_tests_transpose(void) {
  Suite *s = suite_create("s21_transpose");
  TCase *tc = tcase_create("s21_matrix");
  suite_add_tcase(s, tc);

  tcase_add_test(tc, transpose_1);
  tcase_add_test(tc, transpose_2);
  tcase_add_test(tc, transpose_3);
  tcase_add_test(tc, transpose_4);

  return s;
}