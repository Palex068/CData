#include "s21_tests.h"

void runtest(Suite *make_suite, int *result);

int main(void) {
  int result = 0;
  runtest(abs_suite(), &result);
  runtest(ceil_suite(), &result);
  runtest(exp_suite(), &result);
  runtest(fabs_suite(), &result);
  runtest(floor_suite(), &result);
  runtest(fmod_suite(), &result);
  runtest(log_suite(), &result);
  runtest(pow_suite(), &result);
  runtest(sqrt_suite(), &result);
  runtest(cos_suite(), &result);
  runtest(sin_suite(), &result);
  runtest(tan_suite(), &result);
  runtest(atan_suite(), &result);
  runtest(asin_suite(), &result);
  runtest(acos_suite(), &result);

  return (result == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

void runtest(Suite *make_suite, int *result) {
  int n;
  SRunner *sr;
  sr = srunner_create(make_suite);
  srunner_run_all(sr, CK_NORMAL);
  n = srunner_ntests_failed(sr);
  *result += n;
  srunner_free(sr);
}