#include "s21_tests.h"

START_TEST(test_s21_ceil) {
  double values[] = {-1.5, -0.5, 0.5, 1.5, 2.5, 5.000001, 2.3, 0.49};
  int lengths = sizeof(values) / sizeof(values[0]);
  for (int i = 0; i < lengths; i++) {
    double value = values[i];
    ck_assert_int_eq(s21_ceil(value), (int)ceil(value));
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