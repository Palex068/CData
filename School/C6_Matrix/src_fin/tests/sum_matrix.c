#include "test.h"

START_TEST(sum_matrix_1) {
  // Checking sum of equal matrix with nulls
  const int rows = rand() % 100 + 1;
  const int columns = rand() % 100 + 1;
  matrix_t test1 = {0};
  matrix_t test2 = {0};
  matrix_t check = {0};
  s21_create_matrix(rows, columns, &test1);
  s21_create_matrix(rows, columns, &test2);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      test1.matrix[i][j] = 0;
      test2.matrix[i][j] = 0;
    }
  }
  ck_assert_int_eq(s21_sum_matrix(&test1, &test2, &check), OK);
  ck_assert_int_eq(s21_eq_matrix(&test1, &check), SUCCESS);
  s21_remove_matrix(&test1);
  s21_remove_matrix(&test2);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(sum_matrix_2) {
  // Random number addition
  const int rows = rand() % 100 + 1;
  const int columns = rand() % 100 + 1;
  matrix_t test1 = {0};
  matrix_t test2 = {0};
  matrix_t check = {0};
  matrix_t total = {0};
  s21_create_matrix(rows, columns, &test1);
  s21_create_matrix(rows, columns, &test2);
  s21_create_matrix(rows, columns, &total);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      double firstNum = get_rand(DBL_MIN, DBL_MAX);
      double secondNum = get_rand(DBL_MIN, DBL_MAX);
      test1.matrix[i][j] = firstNum;
      test2.matrix[i][j] = secondNum;
      total.matrix[i][j] = firstNum + secondNum;
    }
  }
  ck_assert_int_eq(s21_sum_matrix(&test1, &test2, &check), OK);
  ck_assert_int_eq(s21_eq_matrix(&total, &check), SUCCESS);
  s21_remove_matrix(&test1);
  s21_remove_matrix(&test2);
  s21_remove_matrix(&check);
  s21_remove_matrix(&total);
}
END_TEST

START_TEST(sum_matrix_3) {
  // Matrices have different number of rows
  const int rows1 = 11;
  const int rows2 = 12;
  const int columns = rand() % 100 + 1;
  matrix_t test1 = {0};
  matrix_t test2 = {0};
  matrix_t check = {0};
  s21_create_matrix(rows1, columns, &test1);
  s21_create_matrix(rows2, columns, &test2);
  for (int i = 0; i < rows2; i++) {
    for (int j = 0; j < columns; j++) {
      double num = get_rand(DBL_MIN, DBL_MAX);
      if (i != rows2 - 1) test1.matrix[i][j] = num;
      test2.matrix[i][j] = num;
    }
  }
  ck_assert_int_eq(s21_sum_matrix(&test1, &test2, &check), CALC_ERROR);
  s21_remove_matrix(&test1);
  s21_remove_matrix(&test2);
}
END_TEST

START_TEST(sum_matrix_4) {
  // Result matrix is NULL
  const int rows = rand() % 100 + 1;
  const int columns = rand() % 100 + 1;
  matrix_t test = {0};
  s21_create_matrix(rows, columns, &test);
  ck_assert_int_eq(s21_sum_matrix(&test, &test, NULL), ERROR);
  s21_remove_matrix(&test);
}
END_TEST

START_TEST(sum_matrix_5) {
  // Set matrix is NULL
  const int rows = rand() % 100 + 1;
  const int columns = rand() % 100 + 1;
  matrix_t test = {0};
  matrix_t check = {0};
  s21_create_matrix(rows, columns, &test);
  ck_assert_int_eq(s21_sum_matrix(&test, NULL, &check), ERROR);
  s21_remove_matrix(&test);
}
END_TEST

Suite *s21_tests_sum_matrix(void) {
  Suite *s = suite_create("s21_sum_matrix");
  TCase *tc = tcase_create("s21_matrix");
  suite_add_tcase(s, tc);

  tcase_add_test(tc, sum_matrix_1);
  tcase_add_test(tc, sum_matrix_2);
  tcase_add_test(tc, sum_matrix_3);
  tcase_add_test(tc, sum_matrix_4);
  tcase_add_test(tc, sum_matrix_5);

  return s;
}