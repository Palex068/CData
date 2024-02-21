#include "s21_string.h"

int s21_delim(char ch, const char *delim) {
  while (*delim != '\0') {
    if (ch == *delim) return 1;
    delim++;
  }
  return 0;
}

char *s21_strtok(char *str, const char *delim) {
  static char *p;
  if (!str) {
    str = p;
  }
  if (!str) {
    return s21_NULL;
  }

  while (1) {
    if (s21_delim(*str, delim)) {
      str++;
      continue;
    }
    if (*str == '\0') {
      return s21_NULL;
    }
    break;
  }

  char *ret = str;
  while (1) {
    if (*str == '\0') {
      p = str;
      return ret;
    }
    if (s21_delim(*str, delim)) {
      *str = '\0';
      p = str + 1;
      return ret;
    }
    str++;
  }
}
