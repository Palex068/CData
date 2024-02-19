#include "s21_string.h"

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  char *newDest = (char *)dest;
  char *newSrc = (char *)src;

  if (dest <= src) {
    for (s21_size_t i = 0; i < n; i++) {
      newDest[i] = newSrc[i];
    }
  } else {
    for (s21_size_t i = n; i > 0; i--) {
      newDest[i - 1] = newSrc[i - 1];
    }
  }
  return dest;
}
