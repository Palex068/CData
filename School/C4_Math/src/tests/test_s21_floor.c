#include "s21_tests.h"

START_TEST(test_s21_floor) {
  double values[] = {-1.5, -0.5, 0.5, 1.5, 2.5};
  int lengths = sizeof(values) / sizeof(values[0]);
  for (int i = 0; i < lengths; i++) {
    double value = values[i];
    ck_assert_int_eq(s21_floor(value), (long)floor(value));
  }
}
END_TEST

Suite *floor_suite(void) {
  Suite *s = suite_create("floor");
  TCase *tc_floor = tcase_create("math");

  suite_add_tcase(s, tc_floor);
  tcase_add_test(tc_floor, test_s21_floor);
  return s;
}
