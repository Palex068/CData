#include "s21_tests.h"

START_TEST(test_s21_fabs) {
  double values[] = {-1.5, -0.5, 0.5, 1.5, 2.5, 0, -1, 2};
  int lengths = sizeof(values) / sizeof(values[0]);
  for (int i = 0; i < lengths; i++) {
    double value = values[i];
    ck_assert_int_eq(s21_fabs(value), fabs(value));
  }
}
END_TEST

Suite *fabs_suite(void) {
  Suite *s = suite_create("fabs");
  TCase *tc_fabs = tcase_create("math");

  suite_add_tcase(s, tc_fabs);
  tcase_add_test(tc_fabs, test_s21_fabs);
  return s;
}
