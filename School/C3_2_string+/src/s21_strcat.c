#include "s21_string.h"

char *s21_strcat(char *dest, const char *src) {
  s21_size_t i = 0, j = 0;
  while (dest[i] != '\0') i++;
  while (src[j] != '\0') {
    dest[i + j] = src[j];
    j++;
  }
  dest[i + j + 1] = '\0';
  return dest;
}
