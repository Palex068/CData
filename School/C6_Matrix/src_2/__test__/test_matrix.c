#include "test_matrix.h"

START_TEST(create_1) {
  matrix_t A = {0};
  int res = s21_create_matrix(10, 20, &A);
  s21_remove_matrix(&A);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(create_2) {
  matrix_t A = {0};
  int res = s21_create_matrix(0, 0, &A);
  s21_remove_matrix(&A);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(create_3) {
  matrix_t A;
  int res = s21_create_matrix(5, 6, &A);
  s21_remove_matrix(&A);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(remove_1) {
  matrix_t A;
  int res = s21_create_matrix(5, 6, &A);
  s21_remove_matrix(&A);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(remove_2) {
  matrix_t A = {0};
  int res = s21_create_matrix(1, 1, &A);
  s21_remove_matrix(&A);
  if (A.matrix != NULL) res = 1;
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(remove_3) {
  matrix_t A = {0};
  int res = s21_create_matrix(3, 8, &A);
  s21_remove_matrix(&A);
  if (A.matrix != NULL) res = 1;
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(eq_matrix_1) {
  matrix_t A, B;
  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < columns; ++j) {
      A.matrix[i][j] = i + j;
    }
  }
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < columns; ++j) {
      B.matrix[i][j] = i + j;
    }
  }
  int res = s21_eq_matrix(&A, &B);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(eq_matrix_2) {
  matrix_t A, B;
  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < columns; ++j) {
      A.matrix[i][j] = i + j;
    }
  }
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < columns; ++j) {
      B.matrix[i][j] = i + j + 1;
    }
  }
  int res = s21_eq_matrix(&A, &B);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(eq_matrix_3) {
  matrix_t A, B;
  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows + 1, columns + 1, &B);
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < columns; ++j) {
      A.matrix[i][j] = i + j;
    }
  }
  for (int i = 0; i < rows + 1; ++i) {
    for (int j = 0; j < columns + 1; ++j) {
      B.matrix[i][j] = i + j;
    }
  }
  int res = s21_eq_matrix(&A, &B);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(transpose_1) {
  matrix_t A, B, R;
  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  //  s21_create_matrix(rows, columns, &B);
  s21_create_matrix(rows, columns, &R);
  for (int i = 0, g = 0; i < rows; ++i) {
    for (int j = 0; j < columns; ++j) {
      A.matrix[i][j] = g++;
    }
  }
  R.matrix[0][0] = 0;
  R.matrix[0][1] = 3;
  R.matrix[0][2] = 6;
  R.matrix[1][0] = 1;
  R.matrix[1][1] = 4;
  R.matrix[1][2] = 7;
  R.matrix[2][0] = 2;
  R.matrix[2][1] = 5;
  R.matrix[2][2] = 8;
  int res_B = s21_transpose(&A, &B);
  int res_R = s21_eq_matrix(&B, &R);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
  ck_assert_int_eq(res_B, 0);
  ck_assert_int_eq(res_R, 1);
}
END_TEST

START_TEST(transpose_2) {
  matrix_t A = {0}, R = {0}, C = {0};
  int rows = 2, columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(columns, rows, &C);
  int sum = 0;
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) A.matrix[i][j] = sum++;
  C.matrix[0][0] = 0;
  C.matrix[0][1] = 3;
  C.matrix[1][0] = 1;
  C.matrix[1][1] = 4;
  C.matrix[2][0] = 2;
  C.matrix[2][1] = 5;
  int res_R = s21_transpose(&A, &R);
  int res_C = s21_eq_matrix(&R, &C);
  ck_assert_int_eq(res_R, 0);
  ck_assert_int_eq(res_C, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(transpose_3) {
  matrix_t *A = NULL, B;
  int res_B = s21_transpose(A, &B);
  ck_assert_int_eq(res_B, 1);
}
END_TEST

Suite *test_matrix() {
  Suite *s = suite_create("matrix");
  TCase *o = tcase_create("matrix");

  tcase_add_test(o, create_1);
  tcase_add_test(o, create_2);
  tcase_add_test(o, create_3);

  tcase_add_test(o, remove_1);
  tcase_add_test(o, remove_2);
  tcase_add_test(o, remove_3);

  tcase_add_test(o, eq_matrix_1);
  tcase_add_test(o, eq_matrix_2);
  tcase_add_test(o, eq_matrix_3);

  tcase_add_test(o, transpose_1);
  tcase_add_test(o, transpose_2);
  tcase_add_test(o, transpose_3);
  suite_add_tcase(s, o);
  return s;
}
