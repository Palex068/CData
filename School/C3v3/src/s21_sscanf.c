#include "s21_string.h"

int s21_sscanf(char *str, const char *format, ...) {
  int result = 0;
  if (s21_strlen(str) == 0 || format == s21_NULL) result = -1;
  return result;
}