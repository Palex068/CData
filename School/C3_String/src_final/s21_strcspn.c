#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t i;
  s21_size_t len1 = s21_strlen(str1);
  s21_size_t len2 = s21_strlen(str2);
  for (i = 0; i < len1; i++) {
    for (s21_size_t j = 0; j < len2; j++) {
      if (str2[j] == str1[i]) {
        return i;
      }
    }
  }
  return i;
}
