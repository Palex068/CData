#ifndef S21_STRING_H_
#define S21_STRING_H_

#include <locale.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#define s21_NULL (void *)0
typedef long unsigned s21_size_t;

#define BUFFERSIZE 2048
#define ON 1
#define OFF 0

typedef struct {
  int minus;
  int plus;
  int space;
  int zero;
  int hash;
  int precision;
  int isPrecisionSet;
  int width;
  char length;
  char specifier;
} flags;

s21_size_t s21_strlen(const char *str);
s21_size_t s21_strcspn(const char *str1, const char *str2);
s21_size_t s21_strspn(const char *str1, const char *str2);

int s21_strcmp(const char *str1, const char *str2);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);

void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memmove(void *dest, const void *src, s21_size_t n);
void *s21_memchr(const void *str, int c, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strcat(char *dest, const char *src);
char *s21_strcpy(char *dest, const char *src);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
char *s21_strrchr(const char *str, int c);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strerror(int errnum);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);

void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

int s21_sprintf(char *str, const char *format, ...);
void intToChar(int val, char *ret, int base);
int checkIntCpec(char c);
int isAllZero(char *buff);
void ox(char *buff, flags f);
void doubleToChar(long double val, char *ret, flags f);
void mantiss(char *str, int pow, char sign);
void removeZero(char *buff);
const char *ifFlags(const char *format, flags *f);
const char *width(const char *format, flags *f, va_list va);
const char *precision(const char *format, flags *f, va_list va);
const char *length(const char *format, flags *f);
void menu(flags f, char *buff, va_list va);
void parseInt(flags, char *buff, va_list va);
void parseUnsigned(flags f, char *buff, va_list va);
void parseOctal(flags f, char *buff, va_list va);
void parseHex(flags f, char *buff, va_list va);
void parseChar(flags f, char *buff, va_list va);
void unsignedIntToChar(int val, char *ret, int base);
void formatWidthChar(flags f, char *buff, wchar_t w_c);
void parseString(flags f, char *buff, va_list va);
void formatWideString(flags f, char *buff, wchar_t *wstr);
void formatWidthChar(flags f, char *buff, wchar_t w_c);
void parsePointer(flags f, char *buff, va_list arg_ptr);
void parseFloat(flags f, char *buff, va_list va);
void parseMantiss(flags f, char *buff, va_list va);
void parsegG(flags f, char *buff, va_list va);
void formatPrecision(char *buff, flags f);
void formatFlags(char *buff, flags f);
void formatPrecisiongG(char *buff, int precision);
void formatChar(flags f, char *buff, char c);
void formatString(flags f, char *buff, char *str);
int isDigit(char c);

#endif  //  S21_STRING_H_
