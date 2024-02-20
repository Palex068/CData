#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  if (src == s21_NULL || str == s21_NULL || start_index > s21_strlen(src)) {
    return s21_NULL;
  }
  s21_size_t i = 0;
  char *new_str;
  new_str = calloc(4098, sizeof(char));
  s21_strcpy(new_str, str);
  s21_strcat(new_str, src);
  for (i = 0; i < start_index; i++) {
    *new_str = *src;
    new_str++;
    src++;
  }
  while (*str != '\0') {
    *new_str = *str;
    new_str++;
    str++;
    i++;
  }
  while (*src != '\0') {
    *new_str = *src;
    new_str++;
    src++;
    i++;
  }
  new_str[i] = '\0';
  new_str = new_str - i;
  return new_str;
}