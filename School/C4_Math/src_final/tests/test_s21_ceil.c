#include "s21_tests.h"

START_TEST(test_s21_ceil) {
  double values[] = {-1.5, -0.5, 0.5, 1.5, 2.5,         5.000001,    2.3,
                     0.49, 0,    -1,  2,   S21_INF_POS, S21_INF_NEG, S21_NAN};
  int lengths = sizeof(values) / sizeof(values[0]);
  for (int i = 0; i < lengths; i++) {
    double value = values[i];
    ck_assert_double_eq(s21_ceil(value), (long)ceil(value));
  }
}
END_TEST

Suite *ceil_suite(void) {
  Suite *s = suite_create("ceil");
  TCase *tc_ceil = tcase_create("math");
  suite_add_tcase(s, tc_ceil);
  tcase_add_test(tc_ceil, test_s21_ceil);
  return s;
}