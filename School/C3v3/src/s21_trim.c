#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  s21_size_t index = s21_strlen(src);
  void *ch = s21_NULL;
  if (index > 0) {
    char *newS = (char *)calloc(s21_strlen(src), sizeof(char));
    if (newS) {
      s21_strcpy(newS, src);
      char *newT = (char *)trim_chars;
      for (int i = s21_strlen(newS) - 1; s21_strchr(newT, newS[i]) != s21_NULL;
           i--) {
        newS[i] = '\0';
      }
      while (newS[0] != '\0' && s21_strchr(newT, newS[0]) != s21_NULL) {
        s21_memmove(&newS[0], &newS[1], s21_strlen(newS));
      }
      ch = (void *)newS;
    }
  }
  return ch;
}
