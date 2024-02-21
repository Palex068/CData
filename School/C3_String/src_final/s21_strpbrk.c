#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  s21_size_t len = 0;
  for (; str2[len]; len++)
    ;

  while (*str1 != '\0') {
    for (s21_size_t i = 0; i < len; i++) {
      if (*str1 == str2[i]) {
        return (char *)str1;
      }
    }
    str1++;
  }
  return NULL;
}
