#include "s21_string.h"

void *s21_to_upper(const char *str) {
  if (str == s21_NULL || !s21_strcmp(str, "")) {
    return s21_NULL;
  }
  char *new_str;
  int i = 0;
  new_str = malloc(4098 * sizeof(char));
  s21_strcpy(new_str, str);
  while (*new_str != '\0') {
    if (*new_str >= 'a' && *new_str <= 'z') {
      *new_str = *new_str - 32;
    }
    new_str++;
    i++;
  }
  new_str = new_str - i;
  return new_str;
}
