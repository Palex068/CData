#include "s21_string.h"

void *s21_to_upper(const char *str) {
  s21_size_t len_to_upper = s21_strlen(str);
  void *ch = s21_NULL;
  if (len_to_upper > 0) {
    char *buff = (char *)calloc(sizeof(char), (len_to_upper + 1));
    if (buff) {
      for (s21_size_t i = 0; i <= len_to_upper; i++)
        if (str[i] >= 'a' && str[i] <= 'z') {
          (buff[i] = str[i] - 32);
        } else
          (buff[i] = str[i]);
      ch = (void *)buff;
    }
  }
  return ch;
}
