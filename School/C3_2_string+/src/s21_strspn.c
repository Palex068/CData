#include "s21_string.h"

s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t count = 0, flag = 0;
  s21_size_t len1 = s21_strlen(str1);
  s21_size_t len2 = s21_strlen(str2);
  for (s21_size_t i = 0; i < len1; i++) {
    for (s21_size_t j = 0; j < len2; j++) {
      if (str2[j] == str1[i]) {
        count++;
        flag = 1;
        break;
      }
    }
    if (!flag) break;
  }
  return count;
}
