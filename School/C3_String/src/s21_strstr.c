#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  int i = 0, j = 0;
  while (haystack[i] != needle[j]) {
    if (!*haystack++) {
      return s21_NULL;
    }
  }
  return (char *)haystack;
}
