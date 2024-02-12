#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  s21_size_t n1 = s21_strlen(src);
  s21_size_t n2 = s21_strlen(str);
  void *ch = s21_NULL;
  if (n1 > 0) {
    unsigned char *newS =
        (unsigned char *)calloc(s21_strlen(src), sizeof(unsigned char));
    if (newS) {
      s21_strcpy((char *)newS, src);
      for (s21_size_t i = 0; i < n1 - start_index; i++) {
        newS[n1 + n2 - i - 1] = newS[n1 - i - 1];
      }
      for (s21_size_t j = 0; j < n2; j++) {
        newS[start_index + j] = str[j];
      }
      newS[n1 + n2] = '\0';
      ch = (void *)newS;
    }
  }
  return ch;
}
