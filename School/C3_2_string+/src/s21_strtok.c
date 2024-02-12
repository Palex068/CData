#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *result = s21_NULL;
  if (str) {
    result = str;
    while (*result && s21_strchr(delim, *result)) *result++ = '\0';
  }
  if (*result != '\0') {
    str = result;
    while (*result && !s21_strchr(delim, *result)) ++result;
    while (*result && s21_strchr(delim, *result)) *result++ = '\0';
  } else {
    str = s21_NULL;
  }
  return str;
}
