#include "test.h"

START_TEST(calc_complements_1) {
  // Checking matrix in the task
  matrix_t test = {0};
  matrix_t check = {0};
  matrix_t total = {0};
  s21_create_matrix(3, 3, &test);
  s21_create_matrix(3, 3, &total);
  test.matrix[0][0] = 1;
  test.matrix[0][1] = 2;
  test.matrix[0][2] = 3;
  test.matrix[1][0] = 0;
  test.matrix[1][1] = 4;
  test.matrix[1][2] = 2;
  test.matrix[2][0] = 5;
  test.matrix[2][1] = 2;
  test.matrix[2][2] = 1;
  total.matrix[0][0] = 0;
  total.matrix[0][1] = 10;
  total.matrix[0][2] = -20;
  total.matrix[1][0] = 4;
  total.matrix[1][1] = -14;
  total.matrix[1][2] = 8;
  total.matrix[2][0] = -8;
  total.matrix[2][1] = -2;
  total.matrix[2][2] = 4;
  ck_assert_int_eq(s21_calc_complements(&test, &check), OK);
  ck_assert_int_eq(s21_eq_matrix(&total, &check), SUCCESS);
  s21_remove_matrix(&test);
  s21_remove_matrix(&check);
  s21_remove_matrix(&total);
}
END_TEST

START_TEST(calc_complements_2) {
  // Checking random matrix
  matrix_t test = {0};
  matrix_t check = {0};
  matrix_t total = {0};
  s21_create_matrix(3, 3, &test);
  s21_create_matrix(3, 3, &total);
  test.matrix[0][0] = 8.32;
  test.matrix[0][1] = 0.01;
  test.matrix[0][2] = 12;
  test.matrix[1][0] = 5;
  test.matrix[1][1] = -1.12;
  test.matrix[1][2] = 7;
  test.matrix[2][0] = 22;
  test.matrix[2][1] = -9.89;
  test.matrix[2][2] = 1;
  total.matrix[0][0] = 68.11;
  total.matrix[0][1] = 149;
  total.matrix[0][2] = -24.81;
  total.matrix[1][0] = -118.69;
  total.matrix[1][1] = -255.68;
  total.matrix[1][2] = 82.5048;
  total.matrix[2][0] = 13.51;
  total.matrix[2][1] = 1.76;
  total.matrix[2][2] = -9.3684;
  ck_assert_int_eq(s21_calc_complements(&test, &check), OK);
  ck_assert_int_eq(s21_eq_matrix(&total, &check), SUCCESS);
  s21_remove_matrix(&test);
  s21_remove_matrix(&check);
  s21_remove_matrix(&total);
}
END_TEST

START_TEST(calc_complements_3) {
  // Result matrix is NULL
  const int rows = rand() % 100 + 1;
  matrix_t test = {0};
  s21_create_matrix(rows, rows, &test);
  ck_assert_int_eq(s21_calc_complements(&test, NULL), ERROR);
  s21_remove_matrix(&test);
}
END_TEST

START_TEST(calc_complements_4) {
  // Set matrix is NULL
  matrix_t check = {0};
  ck_assert_int_eq(s21_calc_complements(NULL, &check), ERROR);
}
END_TEST

START_TEST(calc_complements_5) {
  // The matrix isn't square
  const int rows = 4;
  const int columns = 5;
  matrix_t test = {0};
  matrix_t check = {0};
  s21_create_matrix(rows, columns, &test);
  ck_assert_int_eq(s21_calc_complements(&test, &check), CALC_ERROR);
  s21_remove_matrix(&test);
}
END_TEST

Suite *s21_tests_calc_complements(void) {
  Suite *s = suite_create("s21_calc_complements");
  TCase *tc = tcase_create("s21_matrix");
  suite_add_tcase(s, tc);

  tcase_add_test(tc, calc_complements_1);
  tcase_add_test(tc, calc_complements_2);
  tcase_add_test(tc, calc_complements_3);
  tcase_add_test(tc, calc_complements_4);
  tcase_add_test(tc, calc_complements_5);

  return s;
}