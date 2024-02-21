#ifndef SRC_UNIT_TESTS_UNIT_TESTS_H
#define SRC_UNIT_TESTS_UNIT_TESTS_H

#include <check.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

Suite *make_strlen_suite(void);

Suite *make_memchr_suite(void);
Suite *make_memcpy_suite(void);
Suite *make_memcmp_suite(void);
Suite *make_memmove_suite(void);
Suite *make_memset_suite(void);

Suite *make_strcat_suite(void);
Suite *make_strchr_suite(void);
Suite *make_strcmp_suite(void);
Suite *make_strcpy_suite(void);
Suite *make_strcspn_suite(void);
Suite *make_strerror_suite(void);
Suite *make_strncat_suite(void);
Suite *make_strncmp_suite(void);
Suite *make_strncpy_suite(void);
Suite *make_strpbrk_suite(void);
Suite *make_strrchr_suite(void);
Suite *make_strspn_suite(void);
Suite *make_strstr_suite(void);
Suite *make_strtok_suite(void);

Suite *make_to_lower_suite(void);
Suite *make_to_upper_suite(void);
Suite *make_insert_suite(void);
Suite *make_trim_suite(void);

Suite *make_sprintf_suite(void);

#endif  // SRC_UNIT_TESTS_UNIT_TESTS_H
