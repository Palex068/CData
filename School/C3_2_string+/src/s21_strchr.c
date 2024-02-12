#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  while (*str != c) {
    if (!*str++) {
      return s21_NULL;
    }
  }
  return (char *)str;
}
