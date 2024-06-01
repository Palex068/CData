#include "test.h"

START_TEST(mult_number_1) {
  // Checking mult of matrix with null
  const int rows = rand() % 100 + 1;
  const int columns = rand() % 100 + 1;
  double num = 0;
  matrix_t test = {0};
  matrix_t total = {0};
  matrix_t check = {0};
  s21_create_matrix(rows, columns, &test);
  s21_create_matrix(rows, columns, &total);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      test.matrix[i][j] = get_rand(__DBL_MIN__, __DBL_MAX__);
      total.matrix[i][j] = 0;
    }
  }
  ck_assert_int_eq(s21_mult_number(&test, num, &check), OK);
  ck_assert_int_eq(s21_eq_matrix(&total, &check), SUCCESS);
  s21_remove_matrix(&test);
  s21_remove_matrix(&total);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(mult_number_2) {
  // Random number subtraction
  const int rows = rand() % 100 + 1;
  const int columns = rand() % 100 + 1;
  double num = get_rand(__DBL_MIN__, __DBL_MAX__);
  matrix_t test = {0};
  matrix_t check = {0};
  matrix_t total = {0};
  s21_create_matrix(rows, columns, &test);
  s21_create_matrix(rows, columns, &total);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      double randomNum = get_rand(__DBL_MIN__, __DBL_MAX__);
      test.matrix[i][j] = randomNum;
      total.matrix[i][j] = num * randomNum;
    }
  }
  ck_assert_int_eq(s21_mult_number(&test, num, &check), OK);
  ck_assert_int_eq(s21_eq_matrix(&total, &check), SUCCESS);
  s21_remove_matrix(&test);
  s21_remove_matrix(&check);
  s21_remove_matrix(&total);
}
END_TEST

START_TEST(mult_number_3) {
  // Result matrix is NULL
  const int rows = rand() % 100 + 1;
  const int columns = rand() % 100 + 1;
  double num = get_rand(__DBL_MIN__, __DBL_MAX__);
  matrix_t test = {0};
  s21_create_matrix(rows, columns, &test);
  ck_assert_int_eq(s21_mult_number(&test, num, NULL), ERROR);
  s21_remove_matrix(&test);
}
END_TEST

START_TEST(mult_number_4) {
  // Set matrix is NULL
  double num = get_rand(__DBL_MIN__, __DBL_MAX__);
  matrix_t check = {0};
  ck_assert_int_eq(s21_mult_number(NULL, num, &check), ERROR);
}
END_TEST

Suite *s21_tests_mult_number(void) {
  Suite *s = suite_create("s21_mult_number");
  TCase *tc = tcase_create("s21_matrix");
  suite_add_tcase(s, tc);

  tcase_add_test(tc, mult_number_1);
  tcase_add_test(tc, mult_number_2);
  tcase_add_test(tc, mult_number_3);
  tcase_add_test(tc, mult_number_4);

  return s;
}