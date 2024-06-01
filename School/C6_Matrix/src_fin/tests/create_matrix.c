#include "test.h"

START_TEST(create_matrix_1) {
  // Checking the number of rows, columns, internal values and total result with
  // null values and remove function
  int rows = rand() % 100 + 1;
  int columns = rand() % 100 + 1;
  matrix_t test = {0};
  ck_assert_int_eq(s21_create_matrix(rows, columns, &test), OK);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_int_eq(0, test.matrix[i][j]);
    }
  }
  ck_assert_int_eq(test.rows, rows);
  ck_assert_int_eq(test.columns, columns);
  s21_remove_matrix(&test);
}
END_TEST

START_TEST(create_matrix_2) {
  // The number of rows is null
  int rows = 0;
  int columns = rand() % 100 + 1;
  matrix_t test = {0};
  ck_assert_int_eq(s21_create_matrix(rows, columns, &test), ERROR);
  s21_remove_matrix(&test);
}
END_TEST

START_TEST(create_matrix_3) {
  // The number of columns is null
  int rows = rand() % 100 + 1;
  int columns = 0;
  matrix_t test = {0};
  ck_assert_int_eq(s21_create_matrix(rows, columns, &test), ERROR);
  s21_remove_matrix(&test);
}
END_TEST

START_TEST(create_matrix_4) {
  // Passing NULL
  int rows = rand() % 100 + 1;
  int columns = rand() % 100 + 1;
  ck_assert_int_eq(s21_create_matrix(rows, columns, NULL), ERROR);
}
END_TEST

Suite *s21_tests_create_matrix(void) {
  Suite *s = suite_create("s21_create_matrix");
  TCase *tc = tcase_create("s21_matrix");
  suite_add_tcase(s, tc);

  tcase_add_test(tc, create_matrix_1);
  tcase_add_test(tc, create_matrix_2);
  tcase_add_test(tc, create_matrix_3);
  tcase_add_test(tc, create_matrix_4);
  return s;
}