#include "s21_string.h"

s21_size_t s21_strlen(const char *str) {
  const char *p;
  p = str;
  while (*p) p++;
  return p - str;
}
