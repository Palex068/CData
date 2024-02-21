#include "unit_tests.h"

void runtest(Suite *make_suite, int *result);

int main(void) {
  int result = 0;
  runtest(make_memchr_suite(), &result);
  runtest(make_memcpy_suite(), &result);
  runtest(make_memcmp_suite(), &result);
  runtest(make_memmove_suite(), &result);
  runtest(make_memset_suite(), &result);

  runtest(make_strlen_suite(), &result);
  runtest(make_strcat_suite(), &result);
  runtest(make_strchr_suite(), &result);
  runtest(make_strcmp_suite(), &result);
  runtest(make_strcpy_suite(), &result);

  runtest(make_strcspn_suite(), &result);
  runtest(make_strerror_suite(), &result);
  runtest(make_strncat_suite(), &result);
  runtest(make_strncmp_suite(), &result);
  runtest(make_strncpy_suite(), &result);

  runtest(make_strpbrk_suite(), &result);
  runtest(make_strrchr_suite(), &result);
  runtest(make_strspn_suite(), &result);
  runtest(make_strstr_suite(), &result);
  runtest(make_strtok_suite(), &result);

  runtest(make_to_lower_suite(), &result);
  runtest(make_to_upper_suite(), &result);
  runtest(make_insert_suite(), &result);
  runtest(make_trim_suite(), &result);

  runtest(make_sprintf_suite(), &result);

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
