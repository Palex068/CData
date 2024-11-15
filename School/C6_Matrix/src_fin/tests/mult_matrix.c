#include "test.h"

START_TEST(mult_matrix_1) {
  // Checking mult of equal matrix with nulls
  const int rows = rand() % 100 + 1;
  const int columns = rand() % 100 + 1;
  const int commonNum = rand() % 100 + 1;
  matrix_t test1 = {0};
  matrix_t test2 = {0};
  matrix_t check = {0};
  matrix_t total = {0};
  s21_create_matrix(rows, commonNum, &test1);
  s21_create_matrix(commonNum, columns, &test2);
  s21_create_matrix(rows, columns, &total);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      total.matrix[i][j] = 0;
    }
  }
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < commonNum; j++) {
      test1.matrix[i][j] = 0;
    }
  }
  for (int i = 0; i < commonNum; i++) {
    for (int j = 0; j < columns; j++) {
      test2.matrix[i][j] = 0;
    }
  }
  ck_assert_int_eq(s21_mult_matrix(&test1, &test2, &check), OK);
  ck_assert_int_eq(s21_eq_matrix(&total, &check), SUCCESS);
  s21_remove_matrix(&test1);
  s21_remove_matrix(&test2);
  s21_remove_matrix(&check);
  s21_remove_matrix(&total);
}
END_TEST

START_TEST(mult_matrix_2) {
  // Checking an example with simple numbers
  const int rows = 2;
  const int columns = 3;
  int num = 1;
  matrix_t test1 = {0};
  matrix_t test2 = {0};
  matrix_t check = {0};
  matrix_t total = {0};
  s21_create_matrix(rows, columns, &test1);
  s21_create_matrix(columns, rows, &test2);
  s21_create_matrix(rows, rows, &total);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      test1.matrix[i][j] = num;
      test2.matrix[j][i] = -num;
      num += 1;
    }
  }
  total.matrix[0][0] = -14;
  total.matrix[0][1] = -32;
  total.matrix[1][0] = -32;
  total.matrix[1][1] = -77;
  ck_assert_int_eq(s21_mult_matrix(&test1, &test2, &check), OK);
  ck_assert_int_eq(s21_eq_matrix(&total, &check), SUCCESS);
  s21_remove_matrix(&test1);
  s21_remove_matrix(&test2);
  s21_remove_matrix(&check);
  s21_remove_matrix(&total);
}
END_TEST

START_TEST(mult_matrix_3) {
  // Checking an example with complex numbers
  const int rows = rand() % 100 + 1;
  const int columns = rand() % 100 + 1;
  matrix_t test1 = {0};
  matrix_t test2 = {0};
  matrix_t check = {0};
  matrix_t total = {0};
  s21_create_matrix(rows, columns, &test1);
  s21_create_matrix(columns, rows, &test2);
  s21_create_matrix(rows, rows, &total);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++)
      test1.matrix[i][j] = get_rand(-10e10, 10e10);
  for (int i = 0; i < columns; i++)
    for (int j = 0; j < rows; j++) test2.matrix[i][j] = get_rand(-10e10, 10e10);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < rows; j++) {
      total.matrix[i][j] = 0;
      for (int k = 0; k < columns; k++)
        total.matrix[i][j] += test1.matrix[i][k] * test2.matrix[k][j];
    }
  }
  ck_assert_int_eq(s21_mult_matrix(&test1, &test2, &check), OK);
  ck_assert_int_eq(s21_eq_matrix(&total, &check), SUCCESS);
  s21_remove_matrix(&test1);
  s21_remove_matrix(&test2);
  s21_remove_matrix(&check);
  s21_remove_matrix(&total);
}
END_TEST

START_TEST(mult_matrix_4) {
  // The multiplication condition is not fulfilled
  const int rows = 11;
  const int columns = 12;
  matrix_t test1 = {0};
  matrix_t test2 = {0};
  matrix_t check = {0};
  s21_create_matrix(rows, columns, &test1);
  s21_create_matrix(rows, columns, &test2);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      double num = get_rand(DBL_MIN, DBL_MAX);
      test1.matrix[i][j] = num;
      test2.matrix[i][j] = num;
    }
  }
  ck_assert_int_eq(s21_mult_matrix(&test1, &test2, &check), CALC_ERROR);
  s21_remove_matrix(&test1);
  s21_remove_matrix(&test2);
}
END_TEST

START_TEST(mult_matrix_5) {
  // Result matrix is NULL
  const int rows = rand() % 100 + 1;
  matrix_t test = {0};
  s21_create_matrix(rows, rows, &test);
  ck_assert_int_eq(s21_mult_matrix(&test, &test, NULL), ERROR);
  s21_remove_matrix(&test);
}
END_TEST

START_TEST(mult_matrix_6) {
  // Set matrix is NULL
  const int rows = rand() % 100 + 1;
  const int columns = rand() % 100 + 1;
  matrix_t test = {0};
  matrix_t check = {0};
  s21_create_matrix(rows, columns, &test);
  ck_assert_int_eq(s21_mult_matrix(&test, NULL, &check), ERROR);
  s21_remove_matrix(&test);
}
END_TEST

Suite *s21_tests_mult_matrix(void) {
  Suite *s = suite_create("s21_mult_matrix");
  TCase *tc = tcase_create("s21_matrix");
  suite_add_tcase(s, tc);

  tcase_add_test(tc, mult_matrix_1);
  tcase_add_test(tc, mult_matrix_2);
  tcase_add_test(tc, mult_matrix_3);
  tcase_add_test(tc, mult_matrix_4);
  tcase_add_test(tc, mult_matrix_5);
  tcase_add_test(tc, mult_matrix_6);

  return s;
}