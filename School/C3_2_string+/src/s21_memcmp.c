#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  char *newStr1 = (char *)str1;
  char *newStr2 = (char *)str2;
  int res = 0;
  for (s21_size_t i = 0; i < n; i++, newStr1++, newStr2++) {
    res = *newStr1 - *newStr2;
    if (*newStr1 != *newStr2) {
      break;
    }
  }
  return res;
}
