#include "s21_tests.h"

START_TEST(test_s21_fmod) {
  double x_values[] = {-10.9, -10.5, -10.4, -0.9, -0.5, -0.1, 0,
                       0.1,   0.5,   0.9,   10.4, 10.5, 10.9};
  double y_values[] = {3.0, -3.0};
  size_t lengths = sizeof(x_values) / sizeof(x_values[0]);
  for (size_t i = 0; i < lengths; i++) {  // Изменено int на size_t
    for (size_t j = 0; j < sizeof(y_values) / sizeof(y_values[0]);
         j++) {  // Изменено int на size_t
      double x = x_values[i];
      double y = y_values[j];
      ck_assert_ldouble_eq(s21_fmod(x, y), fmod(x, y));
    }
  }
}
END_TEST

Suite *fmod_suite(void) {
  Suite *s = suite_create("fmod");
  TCase *tc_fmod = tcase_create("math");

  suite_add_tcase(s, tc_fmod);
  tcase_add_test(tc_fmod, test_s21_fmod);
  return s;
}
