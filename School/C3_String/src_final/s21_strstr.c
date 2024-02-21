#include "s21_string.h"

int compare(const char *haystack, const char *needle);

char *s21_strstr(const char *haystack, const char *needle) {
  if ((haystack[0] == '\0' && needle[0] == '\0') || needle[0] == '\0') {
    return (char *)haystack;
  }
  while (*haystack != '\0') {
    if ((*haystack == *needle) && compare(haystack, needle)) {
      return (char *)haystack;
    }
    haystack++;
  }

  return s21_NULL;
}

int compare(const char *haystack, const char *needle) {
  while (*haystack && *needle) {
    if (*haystack != *needle) {
      return 0;
    }
    haystack++;
    needle++;
  }

  return (*needle == '\0');
}
