#include "s21_string.h"

int s21_strcmp(const char *str1, const char *str2) {
  int result = 0;
  s21_size_t max_len_str = s21_strlen(str1);
  if (max_len_str < s21_strlen(str2)) {
    max_len_str = s21_strlen(str2);
  }
  for (s21_size_t i = 0; i < max_len_str; i++) {
    if (str1[i] != str2[i]) {
      result = str1[i] - str2[i];
      break;
    }
  }
  return result;
}
