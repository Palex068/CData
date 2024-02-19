#include "s21_string.h"

#include <ctype.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#if __linux__
#include "s21_linux_errno.h"
#elif __APPLE__
#include "s21_mac_errno.h"
#endif

#define skip_spaces()         \
  while (isspace(*str_ptr)) { \
    str_ptr++;                \
  }

s21_size_t s21_strlen(const char *str) {
  s21_size_t len = 0;
  for (; str[len]; len++)
    ;
  return len;
}

char *s21_strchr(const char *str, int c) {
  while (*str != '\0') {
    if (*str == c) {
      return (char *)str;
    }
    str++;
  }
  if (c == '\0')
    return (char *)str;
  else
    return NULL;
}

void *s21_memchr(const void *str, int c, s21_size_t n) {
  int count = 0;
  void *exit;
  const unsigned char *buff = str;
  for (s21_size_t i = 0; i < n; i++) {
    if (*buff == c && count == 0) {
      exit = (void *)buff;
      count = 1;
    }
    buff++;
  }
  if (count == 0) {
    exit = NULL;
  }
  return (void *)exit;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int exit = 0;
  int count = 0;
  const unsigned char *buff1 = str1;
  const unsigned char *buff2 = str2;
  for (s21_size_t i = 0; i < n; i++) {
    if (*buff1 == *buff2 && count == 0) {
    } else if (*buff1 > *buff2 && count == 0) {
      exit = 1;
      count = 1;
    } else if (*buff1 < *buff2 && count == 0) {
      exit = -1;
      count = 1;
    }
    buff1++;
    buff2++;
  }
  return exit;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *dp = (char *)dest;
  const char *buff = (const char *)src;
  for (s21_size_t i = 0; i < n; i++) {
    dp[i] = buff[i];
  }
  return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *buff = str;
  for (s21_size_t i = 0; i < n; i++) {
    buff[i] = c;
  }
  return str;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  const char *buff = src;
  int len = s21_strlen(dest);
  for (s21_size_t i = 0; i < n; i++) {
    dest[len + i] = buff[i];
  }
  dest[len + n] = '\0';
  return dest;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int exit = 0;
  int count = 0;
  for (s21_size_t i = 0; i < n; i++) {
    if (*str1 == *str2 && count == 0) {
    } else if (*str1 > *str2 && count == 0) {
      exit = 1;
      count = 1;
    } else if (*str1 < *str2 && count == 0) {
      exit = -1;
      count = 1;
    }
    str1++;
    str2++;
  }
  return exit;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t j = 0;
  for (s21_size_t i = 0; i < n; i++) {
    *dest = *src;
    dest++;
    src++;
    j++;
  }
  return dest - j;
}

char *s21_strcat(char *destination, const char *source) {
  int i = 0;
  while (*destination) {
    destination++;
    i++;
  }
  while (*source) {
    *destination = *source;
    destination++;
    source++;
    i++;
  }
  *destination = '\0';
  return destination - i;
}

char *s21_strrchr(const char *str, int c) {
  s21_size_t len = 0;
  for (; str[len]; len++)
    ;

  for (int i = len; i >= 0; i--) {
    if (str[i] == c) {
      return (char *)str + i;
    }
  }

  return NULL;
}

char *s21_strerror(int errnum) {
  static char buf[MAX_ERROR_LEN] = "";
  char tmp_errnum[40] = "";
  if (errnum < 0 || errnum >= _s21_sys_nerr ||
      _s21_sys_errlist[errnum] == NULL) {
    s21_strncpy(buf, UNKNOWN_PREFIX, MAX_ERROR_LEN - 1);
    if (errnum < 0) {
      s21_strcat(buf, "-");
    }
    itoa_float(errnum, tmp_errnum);
    s21_strcat(buf, tmp_errnum);
  } else {
    s21_strncpy(buf, _s21_sys_errlist[errnum], MAX_ERROR_LEN - 1);
    buf[MAX_ERROR_LEN - 1] = '\0';
  }

  return buf;
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

const char *s21_strstr(const char *haystack, const char *needle) {
  if ((haystack[0] == '\0' && needle[0] == '\0') || needle[0] == '\0') {
    return haystack;
  }
  while (*haystack != '\0') {
    if ((*haystack == *needle) && compare(haystack, needle)) {
      return haystack;
    }
    haystack++;
  }

  return NULL;
}

int s21_delim(char ch, const char *delim) {
  while (*delim != '\0') {
    if (ch == *delim) return 1;
    delim++;
  }
  return 0;
}

char *s21_strtok(char *str, const char *delim) {
  static char *p;
  if (!str) {
    str = p;
  }
  if (!str) {
    return NULL;
  }

  while (1) {
    if (s21_delim(*str, delim)) {
      str++;
      continue;
    }
    if (*str == '\0') {
      return NULL;
    }
    break;
  }

  char *ret = str;
  while (1) {
    if (*str == '\0') {
      p = str;
      return ret;
    }
    if (s21_delim(*str, delim)) {
      *str = '\0';
      p = str + 1;
      return ret;
    }
    str++;
  }
}

char *s21_strpbrk(const char *str1, const char *str2) {
  s21_size_t len = 0;
  for (; str2[len]; len++)
    ;

  while (*str1 != '\0') {
    for (s21_size_t i = 0; i < len; i++) {
      if (*str1 == str2[i]) {
        return (char *)str1;
      }
    }
    str1++;
  }
  return NULL;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t count = 0;
  s21_size_t len = 0;
  for (; str2[len]; len++)
    ;

  while (*str1 != '\0') {
    for (s21_size_t i = 0; i < len; i++) {
      if (*str1 == str2[i]) {
        return count;
      }
    }
    str1++;
    count++;
  }
  return count;
}

char *s21_strcpy(char *dest, const char *src) {
  if (dest == NULL) {
    return NULL;
  }
  char *ptr = dest;
  while (*src != '\0') {
    *dest = *src;
    dest++;
    src++;
  }
  *dest = '\0';
  return ptr;
}

void *s21_to_upper(const char *str) {
  if (str == NULL) {
    return NULL;
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

void *s21_to_lower(const char *str) {
  if (str == NULL) {
    return NULL;
  }
  char *new_str;
  int i = 0;
  new_str = malloc(4098 * sizeof(char));
  s21_strcpy(new_str, str);
  while (*new_str != '\0') {
    if (*new_str >= 'A' && *new_str <= 'Z') {
      *new_str = *new_str + 32;
    }
    new_str++;
    i++;
  }
  new_str = new_str - i;
  return new_str;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  if (src == NULL || str == NULL || start_index > s21_strlen(src)) {
    return NULL;
  }
  s21_size_t i = 0;
  char *new_str;
  new_str = malloc(4098 * sizeof(char));
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
  new_str = new_str - i;
  return new_str;
}

void *s21_trim(const char *src, const char *trim_chars) {
  if (src == NULL) {
    return NULL;
  }
  if (trim_chars == NULL || s21_strlen(trim_chars) == 0) {
    trim_chars = " \t\n\v\r\f";
  }
  char *new_str;
  int eq_count = 0, ptr_count = 0;
  new_str = malloc(4098 * sizeof(char));
  while (1) {
    while (*trim_chars != '\0') {
      if (*src == *trim_chars) eq_count++;
      trim_chars++;
      ptr_count++;
    }
    trim_chars = trim_chars - ptr_count;
    if (eq_count == 0) {
      break;
    } else {
      eq_count = 0;
      ptr_count = 0;
      src++;
    }
  }
  eq_count = 0;
  ptr_count = 0;
  s21_strcpy(new_str, src);
  for (int i = s21_strlen(new_str) - 1; i >= 0; i--) {
    while (*trim_chars != '\0') {
      if (new_str[i] == *trim_chars) eq_count++;
      trim_chars++;
      ptr_count++;
    }
    trim_chars = trim_chars - ptr_count;
    if (eq_count == 0) {
      break;
    } else {
      new_str[i] = '\0';
      eq_count = 0;
      ptr_count = 0;
    }
  }

  return new_str;
}

void s21_d_func(long long int int_num, char *str, int *str_ind, int flag,
                int plus_sign, int zero, int length, int left_aligment,
                int accuracy, int sharp, int long_flag) {
  int len, num_system = 10;
  char num_arg[4096];
  if (long_flag == 'l') int_num = (long int)int_num;
  if (long_flag == 'h') int_num = (short int)int_num;
  if (!long_flag) int_num = (int)int_num;
  if (flag == 'o') num_system = 8;
  if (flag == 'x' || flag == 'X' || flag == 'p') num_system = 16;
  if (flag == 'p' && !int_num) {
    s21_strcpy(num_arg, "(nil)");
    if (left_aligment && length > 5) {
      for (int i = 5; i < length; i++) {
        s21_strcat(num_arg, " ");
      }
    } else if (!left_aligment && length > 5) {
      reverse(num_arg, 0, s21_strlen(num_arg) - 1);
      for (int i = 5; i < length; i++) {
        s21_strcat(num_arg, " ");
      }
      reverse(num_arg, 0, s21_strlen(num_arg) - 1);
    }
  } else {
    itoa(int_num, num_arg, num_system, flag, accuracy, long_flag);
    digit_flag_acception(int_num, num_arg, num_system, flag, plus_sign, zero,
                         length, left_aligment, accuracy, sharp);
  }
  uppercase_string(num_arg, flag);
  len = s21_strlen(num_arg);
  s21_strcpy(str + *str_ind, num_arg);
  *str_ind += len;
}

int num_length(long long int int_part) {
  int int_part_length = 0;
  while (int_part != 0) {
    int_part /= 10;
    int_part_length++;
  }
  return int_part_length;
}

void s21_g_func(long double float_num, char *str, int *str_ind, int flag,
                int plus_sign, int zero, int length, int left_aligment,
                int f_accuracy, int sharp) {
  char float_string_part[4096], float_string_full[4096] = "";
  long double int_part, float_part;
  int int_part_length, zero_count = 0, exp_num = 0, sign_flag = 1, exp_flag = 0,
                       count = 0;
  if (float_num == INFINITY) {
    s21_strcpy(float_string_full, "inf");
  } else if (isnan(float_num) != 0) {
    s21_strcpy(float_string_full, "nan");
  } else {
    float_part = modfl(float_num, &int_part);
    int_part_length = num_length(int_part);
    if ((f_accuracy == 0 && fabsl(float_num) >= 1) ||
        (float_num < 1e-4 && float_num > -1e-4 && float_num != 0) ||
        int_part_length > f_accuracy) {
      exp_flag = 1;
    }
    if (exp_flag == 1) {
      exp_calculation(&float_num, &sign_flag, &exp_num);
    }

    if (f_accuracy == int_part_length && f_accuracy != 0) {
      float_part = modfl(float_num, &int_part);
      int_part_length = num_length(int_part);
      float_part = float_part * powl(10, f_accuracy);
      float_part = roundl(float_part) / powl(10, f_accuracy);
      int_part = roundl(float_num);
      exp_round(&int_part, exp_flag, sign_flag, &exp_num);
      itoa_float(int_part, float_string_full);
      if (sharp) s21_strcat(float_string_full, ".");
      exp_part_cat(float_string_full, exp_num, sign_flag, exp_flag);
    } else if (float_num == 0) {
      s21_strcpy(float_string_full, "0");
      if (sharp) {
        s21_strcat(float_string_full, ".");
        for (int j = 0; j < f_accuracy - 1; j++) {
          s21_strcat(float_string_full, "0");
        }
      }

    } else {
      float_part = modfl(float_num, &int_part);
      int_part_length = num_length(int_part);
      if (fabsl(float_num) < 1) {
        while (num_length((float)float_part) < 1) {
          float_part = float_part * 10;
          count++;
        }
        if (float_part) {
          for (int j = 0; j < f_accuracy - 1; j++) {
            float_part = float_part * 10;
            count++;
          }
        }

      } else {
        for (int j = 0;
             f_accuracy >= int_part_length ? j < f_accuracy - int_part_length
                                           : j < f_accuracy - 1;
             j++) {
          float_part = float_part * 10;
          count++;
        }
      }
      int float_part_length_before = num_length(float_part);
      float_part = roundl(float_part) / powl(10, count);
      find_zeros(&float_part, &zero_count, count);
      float_part = roundl(float_part);
      float_num_rounding(&float_part, &int_part, float_num,
                         float_part_length_before);
      if (!sharp && float_part != 0) {
        while ((long long int)float_part % 10 == 0) {
          float_part = float_part / 10;
        }
      }
      exp_round(&int_part, exp_flag, sign_flag, &exp_num);
      itoa_float(int_part, float_string_part);
      s21_strcat(float_string_full, float_string_part);
      if (float_part) {
        s21_strcat(float_string_full, ".");
        for (int j = 0; j < zero_count; j++) {
          s21_strcat(float_string_full, "0");
        }
        if ((long int)float_part != 0) {
          itoa_float(float_part, float_string_part);
          s21_strcat(float_string_full, float_string_part);
        } else {
          for (int j = 0; j < f_accuracy; j++) {
            s21_strcat(float_string_full, "0");
          }
        }
      }
      if (!float_part && sharp) {
        s21_strcat(float_string_full, ".");
        for (int j = num_length(int_part); j < f_accuracy; j++) {
          s21_strcat(float_string_full, "0");
        }
      }
      exp_part_cat(float_string_full, exp_num, sign_flag, exp_flag);
    }
  }
  uppercase_string(float_string_full, flag);
  float_flags_acception(float_num, float_string_full, plus_sign, zero, length,
                        left_aligment);

  s21_strcpy(str + *str_ind, float_string_full);
  *str_ind += s21_strlen(float_string_full);
}

char *float_flags_acception(double value, char *buffer, int plus_sign, int zero,
                            int length, int left_aligment) {
  int i = s21_strlen(buffer);
  reverse(buffer, 0, i - 1);
  if (length > i && !left_aligment) {
    if (!zero) {
      some_flags_acception(buffer, value, &i, plus_sign);
      for (int j = i; j < length; j++) {
        buffer[i++] = ' ';
      }
    } else if (zero) {
      if (value < 0 || (value > 0 && plus_sign != 0)) {
        for (int j = i; j < length - 1; j++) {
          buffer[i++] = '0';
        }
        some_flags_acception(buffer, value, &i, plus_sign);
      } else if (value > 0 && plus_sign == 0) {
        for (int j = i; j < length; j++) {
          buffer[i++] = '0';
        }
      }
    }
  } else if (length > i && left_aligment) {
    some_flags_acception(buffer, value, &i, plus_sign);
    reverse(buffer, 0, i - 1);
    for (int j = i; j < length; j++) {
      buffer[i++] = ' ';
    }
    reverse(buffer, 0, i - 1);
  } else if (length <= i) {
    some_flags_acception(buffer, value, &i, plus_sign);
  }

  buffer[i] = '\0';

  return reverse(buffer, 0, i - 1);
}

void float_num_rounding(long double *float_part, long double *int_part,
                        long double float_num, int accuracy) {
  if (num_length(*float_part) > accuracy) {
    if (float_num > 0) {
      *float_part = *float_part - powl(10, accuracy);
      *int_part = *int_part + 1;
    } else {
      *float_part = *float_part + powl(10, accuracy);
      *int_part = *int_part - 1;
    }
  }
}

void find_zeros(long double *float_part, int *zero_count, int accuracy) {
  long double int_part_temp, float_temp;
  for (int j = 0; j < accuracy; j++) {
    *float_part = *float_part * 10;
    float_temp = modfl((float)*float_part, &int_part_temp);
    if (int_part_temp < 1 && int_part_temp > -1 && float_temp != 0)
      *zero_count = *zero_count + 1;
  }
}

void exp_part_cat(char *string, int exp_num, int sign_flag, int flag) {
  char exp_part[4096];
  if (flag == 'e' || flag == 'E' || flag == 1) {
    s21_strcat(string, !sign_flag ? "e-" : "e+");
    itoa_float(exp_num, exp_part);
    if (exp_num < 10) {
      s21_strcat(string, "0");
    }
    s21_strcat(string, exp_part);
  }
}

char *itoa_float(long double value, char *buffer) {
  unsigned long long int num;
  int i = 0;

  if (value < 0)
    num = -value;
  else
    num = value;

  while (num) {
    unsigned int r = num % 10;
    buffer[i++] = 48 + r;
    num = num / 10;
  }

  if (i == 0) {
    buffer[i++] = '0';
  }

  buffer[i] = '\0';

  return reverse(buffer, 0, i - 1);
}

void exp_round(long double *int_part, int flag, int sign_flag, int *exp_num) {
  if ((*int_part >= 10 || *int_part <= -10) &&
      (flag == 'e' || flag == 'E' || flag == 1)) {
    *int_part = *int_part / 10;
    if (sign_flag == 1)
      *exp_num = *exp_num + 1;
    else
      *exp_num = *exp_num - 1;
  }
}

void exp_calculation(long double *float_num, int *sign_flag, int *exp_num) {
  if (*float_num != 0) {
    while (num_length(*float_num) != 1) {
      if (*float_num < 1 && *float_num > -1) {
        *float_num *= 10;
        *sign_flag = 0;
      } else {
        *float_num /= 10;
      }
      *exp_num = *exp_num + 1;
    }
  }
}

void s21_f_func(long double float_num, char *str, int *str_ind, int flag,
                int plus_sign, int zero, int length, int left_aligment,
                int f_accuracy, int sharp) {
  char float_string_part[4096], float_string_full[4096] = "";
  long double int_part, float_part;
  int zero_count = 0, exp_num = 0, sign_flag = 1;
  if (float_num == INFINITY) {
    s21_strcpy(float_string_full, "inf");
  } else if (isnan(float_num) != 0) {
    s21_strcpy(float_string_full, "nan");
  } else {
    if (flag == 'e' || flag == 'E') {
      exp_calculation(&float_num, &sign_flag, &exp_num);
    }
    if (f_accuracy == 0) {
      int_part = roundl(float_num);
      exp_round(&int_part, flag, sign_flag, &exp_num);
      itoa_float(int_part, float_string_full);
      if (sharp) s21_strcat(float_string_full, ".");
      exp_part_cat(float_string_full, exp_num, sign_flag, flag);
    } else {
      float_part = modfl(float_num, &int_part);
      int count = 0;
      for (int j = 0; j < f_accuracy; j++) {
        float_part = float_part * 10;
        count++;
      }
      float_part = roundl(float_part) / powl(10, count);
      find_zeros(&float_part, &zero_count, f_accuracy);
      float_part = roundl(float_part);
      float_num_rounding(&float_part, &int_part, float_num, f_accuracy);
      exp_round(&int_part, flag, sign_flag, &exp_num);
      itoa_float(int_part, float_string_part);
      s21_strcat(float_string_full, float_string_part);
      s21_strcat(float_string_full, ".");
      for (int j = 0; j < zero_count; j++) {
        s21_strcat(float_string_full, "0");
      }
      if ((long int)float_part != 0) {
        itoa_float(float_part, float_string_part);
        s21_strcat(float_string_full, float_string_part);
      } else {
        for (int j = 0; j < f_accuracy; j++) {
          s21_strcat(float_string_full, "0");
        }
      }
      exp_part_cat(float_string_full, exp_num, sign_flag, flag);
    }
  }
  uppercase_string(float_string_full, flag);
  float_flags_acception(float_num, float_string_full, plus_sign, zero, length,
                        left_aligment);
  s21_strcpy(str + *str_ind, float_string_full);
  *str_ind += s21_strlen(float_string_full);
}

void set_float_length(long double *float_num, va_list arg_list, int long_flag) {
  if (long_flag == 'L')
    *float_num = va_arg(arg_list, long double);
  else
    *float_num = va_arg(arg_list, double);
}

void uppercase_string(char *string, int flag) {
  if (flag == 'E' || flag == 'X' || flag == 'G') {
    char *tmp = s21_to_upper(string);
    s21_strcpy(string, tmp);
    free(tmp);
  }
}
void hex_sharp_fill(char *buffer, long long int value, int sharp, int flag,
                    int *i) {
  if (sharp && flag == 'o' && value != 0) {
    buffer[*i] = '0';
    *i = *i + 1;
  }
  if ((sharp && value && (flag == 'x' || flag == 'X')) || flag == 'p') {
    buffer[*i] = 'x';
    *i = *i + 1;
    buffer[*i] = '0';
    *i = *i + 1;
  }
}

void digit_spase_fill(char *buffer, int length, int *i, char ch) {
  for (int j = *i; j < length; j++) {
    buffer[*i] = ch;
    *i = *i + 1;
  }
}

void some_flags_acception(char *buffer, double value, int *i, int plus_sign) {
  if (value < 0) {
    buffer[*i] = '-';
    *i = *i + 1;
  } else if (value >= 0 && plus_sign == ' ') {
    buffer[*i] = ' ';
    *i = *i + 1;
  } else if (value >= 0 && plus_sign == '+') {
    buffer[*i] = '+';
    *i = *i + 1;
  }
}

char *digit_flag_acception(long long int value, char *buffer, int base,
                           int flag, int plus_sign, int zero, int length,
                           int left_aligment, int accuracy, int sharp) {
  int i = s21_strlen(buffer);
  reverse(buffer, 0, i - 1);
  if (!left_aligment && accuracy <= i) {
    if (base == 10 && flag != 'u' && !zero) {
      some_flags_acception(buffer, value, &i, plus_sign);
      digit_spase_fill(buffer, length, &i, ' ');
    } else if (base == 10 && flag != 'u' && zero) {
      if (value < 0 || (value > 0 && plus_sign != 0)) {
        digit_spase_fill(buffer, length - 1, &i, '0');
        some_flags_acception(buffer, value, &i, plus_sign);
      } else if (value > 0 && plus_sign == 0) {
        digit_spase_fill(buffer, length, &i, '0');
      }
    } else {
      hex_sharp_fill(buffer, value, sharp, flag, &i);
      digit_spase_fill(buffer, length, &i, zero ? '0' : ' ');
    }
  }
  if (left_aligment && accuracy <= i) {
    if (base == 10 && flag != 'u') {
      some_flags_acception(buffer, value, &i, plus_sign);
      reverse(buffer, 0, i - 1);
      digit_spase_fill(buffer, length, &i, ' ');
      reverse(buffer, 0, i - 1);
    } else {
      hex_sharp_fill(buffer, value, sharp, flag, &i);
      reverse(buffer, 0, i - 1);
      digit_spase_fill(buffer, length, &i, ' ');
      reverse(buffer, 0, i - 1);
    }
  }
  if (accuracy > i) {
    if (base == 10 && flag != 'u') {
      digit_spase_fill(buffer, accuracy, &i, '0');
      some_flags_acception(buffer, value, &i, plus_sign);
      if (length > accuracy && !left_aligment) {
        digit_spase_fill(buffer, length, &i, ' ');
      } else if (length > accuracy && left_aligment) {
        reverse(buffer, 0, i - 1);
        digit_spase_fill(buffer, length, &i, ' ');
        reverse(buffer, 0, i - 1);
      }
    } else {
      digit_spase_fill(buffer, accuracy, &i, '0');
      if ((sharp && value && (flag == 'x' || flag == 'X')) || flag == 'p') {
        buffer[i++] = 'x';
        buffer[i++] = '0';
      }
      if (length > accuracy && !left_aligment) {
        digit_spase_fill(buffer, length, &i, ' ');
      } else if (length > accuracy && left_aligment) {
        reverse(buffer, 0, i - 1);
        digit_spase_fill(buffer, length, &i, ' ');
        reverse(buffer, 0, i - 1);
      }
    }
  }
  buffer[i] = '\0';
  return reverse(buffer, 0, i - 1);
}

char *itoa(long long int value, char *buffer, int base, int flag, int accuracy,
           int long_flag) {
  long unsigned int num;
  int i = 0;
  if (flag == 'd' || flag == 'i') {
    num = llabs(value);
  } else {
    if (long_flag == 'l' || flag == 'p')
      num = (long unsigned int)value;
    else
      num = (unsigned int)value;
  }
  while (num) {
    int r = num % base;
    if (r >= 10) {
      buffer[i++] = 97 + (r - 10);
    } else {
      buffer[i++] = 48 + r;
    }
    num = num / base;
  }

  if (i == 0) {
    if (accuracy) buffer[i++] = '0';
  }

  buffer[i] = '\0';

  return reverse(buffer, 0, i - 1);
}

char *reverse(char *buffer, int i, int j) {
  while (i < j) {
    char tmp = buffer[i];
    buffer[i] = buffer[j];
    buffer[j] = tmp;
    i++;
    j--;
  }
  return buffer;
}

void s21_s_func(char *str_arg, char *str, int *str_ind, int s_accuracy,
                int length, int left_aligment) {
  int j, len;
  char str_arg_accur[4096];
  if (str_arg == NULL) {
    str_arg = "(null)";
    len = s21_strlen(str_arg);
    if (s_accuracy >= 6) {
      if (!left_aligment) {
        for (int j = 0; len < length ? j < length - len : j < 0; j++) {
          func_space_fill(str, &str_ind);
        }
      }
      s21_strcpy(str + *str_ind, str_arg);
      *str_ind = *str_ind + len;
      if (left_aligment) {
        for (int j = 0; len < length ? j < length - len : j < 0; j++) {
          func_space_fill(str, &str_ind);
        }
      }
    } else {
      for (int j = 0; j < length; j++) {
        func_space_fill(str, &str_ind);
      }
    }
  } else {
    len = s21_strlen(str_arg);
    for (j = 0; len > s_accuracy ? j < s_accuracy : j < len; j++) {
      str_arg_accur[j] = str_arg[j];
    }
    str_arg_accur[j] = '\0';
    len = s21_strlen(str_arg_accur);
    if (length == 0 || length <= len) {
      s21_strcpy(str + *str_ind, str_arg_accur);
      *str_ind = *str_ind + len;
    } else {
      if (!left_aligment) {
        for (int j = 0; j < length - len; j++) {
          func_space_fill(str, &str_ind);
        }
      }
      s21_strcpy(str + *str_ind, str_arg_accur);
      *str_ind = *str_ind + len;
      if (left_aligment) {
        for (int j = len; j < length; j++) {
          func_space_fill(str, &str_ind);
        }
      }
    }
  }
}

void func_space_fill(char *str, int **str_ind) {
  s21_strcpy(str + **str_ind, " ");
  **str_ind = **str_ind + 1;
}

void s21_c_func(int ch, char *str, int *str_ind, int length,
                int left_aligment) {
  if (length <= 1) {
    str[*str_ind] = ch;
    *str_ind = *str_ind + 1;
  } else {
    if (!left_aligment) {
      for (int j = 0; j < length - 1; j++) {
        func_space_fill(str, &str_ind);
      }
    }
    str[*str_ind] = ch;
    *str_ind = *str_ind + 1;
    if (left_aligment) {
      for (int j = 1; j < length; j++) {
        func_space_fill(str, &str_ind);
      }
    }
  }
}

void s21_sprintf_length_acception(const char *format, int *long_flag, int *i) {
  if (format[*i] == 'l') {
    *long_flag = 'l';
    *i = *i + 1;
  } else if (format[*i] == 'h') {
    *long_flag = 'h';
    *i = *i + 1;
  } else if (format[*i] == 'L') {
    *long_flag = 'L';
    *i = *i + 1;
  }
}

int ch_to_dig(int ch) {
  int digit;
  digit = ch - '0';
  return digit;
}

void s21_sprintf_precision_acception(const char *format, va_list arg_list,
                                     int *accuracy, int *f_accuracy,
                                     int *s_accuracy, int *i) {
  if (format[*i] == '.') {
    *i = *i + 1;
    *f_accuracy = 0;
    *s_accuracy = 0;
    *accuracy = 0;
    if (isdigit(format[*i])) {
      while (isdigit(format[*i])) {
        *accuracy = 10 * *accuracy + ch_to_dig(format[*i]);
        *i = *i + 1;
      }
      *f_accuracy = *accuracy;
      *s_accuracy = *accuracy;
    } else if (format[*i] == '*') {
      *accuracy = va_arg(arg_list, int);
      *f_accuracy = *accuracy;
      *s_accuracy = *accuracy;
      *i = *i + 1;
    }
  }
}
void s21_sprintf_width_acception(const char *format, va_list arg_list,
                                 int *left_aligment, int *length, int *i) {
  if (isdigit(format[*i])) {
    while (isdigit(format[*i])) {
      *length = 10 * *length + ch_to_dig(format[*i]);
      *i = *i + 1;
    }
  } else if (format[*i] == '*') {
    *length = va_arg(arg_list, int);
    *i = *i + 1;
    if (*length < 0) {
      *left_aligment = 1;
      *length = -*length;
    }
  }
}

void s21_sprintf_flags_acception(const char *format, int *left_aligment,
                                 int *sharp, int *plus_sign, int *zero,
                                 int *i) {
  while (1) {
    if (format[*i] == '-') {
      *left_aligment = 1;
    } else if (format[*i] == '#') {
      *sharp = 1;
    } else if (format[*i] == '+') {
      *plus_sign = '+';
    } else if (format[*i] == ' ') {
      if (*plus_sign == 0) *plus_sign = ' ';
    } else {
      break;
    }
    *i = *i + 1;
  }

  if (format[*i] == '0') {
    *zero = 1;
    *i = *i + 1;
  }
}

int s21_sprintf(char *str, const char *format, ...) {
  va_list arg_list;
  va_start(arg_list, format);

  int str_ind = 0, flag = 0;
  long double float_num;

  for (int i = 0; format[i] != '\0'; i++) {
    int length = 0, left_aligment = 0, sharp = 0, plus_sign = 0, zero = 0,
        accuracy = 1, f_accuracy = 6, s_accuracy = 1000, long_flag = 0;
    if (format[i] == '%') {
      i++;

      s21_sprintf_flags_acception(format, &left_aligment, &sharp, &plus_sign,
                                  &zero, &i);

      s21_sprintf_width_acception(format, arg_list, &left_aligment, &length,
                                  &i);

      s21_sprintf_precision_acception(format, arg_list, &accuracy, &f_accuracy,
                                      &s_accuracy, &i);

      s21_sprintf_length_acception(format, &long_flag, &i);

      switch (format[i]) {
        case '%':
          str[str_ind++] = '%';
          break;
        case 'c':
          s21_c_func(va_arg(arg_list, int), str, &str_ind, length,
                     left_aligment);
          break;
        case 's':
          s21_s_func(va_arg(arg_list, char *), str, &str_ind, s_accuracy,
                     length, left_aligment);
          break;
        case 'd':
        case 'i':
          flag = 'd';
          s21_d_func(va_arg(arg_list, long long int), str, &str_ind, flag,
                     plus_sign, zero, length, left_aligment, accuracy, sharp,
                     long_flag);
          break;
        case 'f':
          set_float_length(&float_num, arg_list, long_flag);
          s21_f_func(float_num, str, &str_ind, flag, plus_sign, zero, length,
                     left_aligment, f_accuracy, sharp);
          break;
        case 'g':
          flag = 'g';
          set_float_length(&float_num, arg_list, long_flag);
          s21_g_func(float_num, str, &str_ind, flag, plus_sign, zero, length,
                     left_aligment, f_accuracy, sharp);
          break;
        case 'G':
          flag = 'G';
          set_float_length(&float_num, arg_list, long_flag);
          s21_g_func(float_num, str, &str_ind, flag, plus_sign, zero, length,
                     left_aligment, f_accuracy, sharp);
          break;
        case 'u':
          flag = 'u';
          s21_d_func(va_arg(arg_list, long long int), str, &str_ind, flag,
                     plus_sign, zero, length, left_aligment, accuracy, sharp,
                     long_flag);
          break;
        case 'X':
          flag = 'X';
          s21_d_func(va_arg(arg_list, long long int), str, &str_ind, flag,
                     plus_sign, zero, length, left_aligment, accuracy, sharp,
                     long_flag);
          break;
        case 'x':
          flag = 'x';
          s21_d_func(va_arg(arg_list, long long int), str, &str_ind, flag,
                     plus_sign, zero, length, left_aligment, accuracy, sharp,
                     long_flag);
          break;
        case 'o':
          flag = 'o';
          s21_d_func(va_arg(arg_list, long long int), str, &str_ind, flag,
                     plus_sign, zero, length, left_aligment, accuracy, sharp,
                     long_flag);
          break;
        case 'e':
          flag = 'e';
          set_float_length(&float_num, arg_list, long_flag);
          s21_f_func(float_num, str, &str_ind, flag, plus_sign, zero, length,
                     left_aligment, f_accuracy, sharp);
          break;
        case 'E':
          flag = 'E';
          set_float_length(&float_num, arg_list, long_flag);
          s21_f_func(float_num, str, &str_ind, flag, plus_sign, zero, length,
                     left_aligment, f_accuracy, sharp);
          break;
        case 'p':
          flag = 'p';
          long_flag = 1;
          s21_d_func(va_arg(arg_list, long long int), str, &str_ind, flag,
                     plus_sign, zero, length, left_aligment, accuracy, sharp,
                     long_flag);
          break;
        case 'n':;
          int *n = va_arg(arg_list, int *);
          *n = str_ind;
          break;
      }
    } else
      str[str_ind++] = format[i];
  }
  str[str_ind] = '\0';
  va_end(arg_list);
  return str_ind;
}

int sscanf_unsigned(char *str, const char **format_ptr, const char **str_ptr,
                    int *args_count, unsigned long **ulong_ptr,
                    unsigned short **ushort_ptr, unsigned int **uint_ptr,
                    va_list arg_list, int width, int suppresse, int long_flag) {
  int return_flag = 0, base = 0, i = 0;
  char temp[500], *end_ptr;
  base =
      (**format_ptr == 'u') * 10 + (**format_ptr == 'o') * 8 +
      (**format_ptr == 'x' || **format_ptr == 'X' || **format_ptr == 'p') * 16;
  if (!string_check(str)) {
    *args_count = -1;
    return_flag = -1;
  } else {
    if (suppresse) {
      strtoul(*str_ptr, &end_ptr, base);
    } else if (long_flag == 'l' || **format_ptr == 'p') {
      *ulong_ptr = va_arg(arg_list, unsigned long *);
      if (*ulong_ptr == NULL) return -1;
      if (!width)
        **ulong_ptr = (unsigned long)strtoul(*str_ptr, &end_ptr, base);
      else {
        make_temp_string(temp, &str_ptr, &i, width);
        if (i == 1 && !isdigit(temp[0]) && **format_ptr != 'x' &&
            **format_ptr != 'X' && **format_ptr != 'p')
          return -1;
        if (i == 1 && !isxdigit(temp[0]) && **format_ptr != 'u' &&
            **format_ptr != 'o')
          return -1;
        **ulong_ptr = (unsigned long)(strtol(temp, &end_ptr, base));
      }
    } else if (long_flag == 'h') {
      *ushort_ptr = va_arg(arg_list, unsigned short *);
      if (*ushort_ptr == NULL) return -1;
      if (!width)
        **ushort_ptr = (unsigned short)(strtoul(*str_ptr, &end_ptr, base));
      else {
        make_temp_string(temp, &str_ptr, &i, width);
        if (i == 1 && !isdigit(temp[0]) && **format_ptr != 'x' &&
            **format_ptr != 'X')
          return -1;
        if (i == 1 && !isxdigit(temp[0]) && **format_ptr != 'u' &&
            **format_ptr != 'o')
          return -1;
        **ushort_ptr = (unsigned short)(strtol(temp, &end_ptr, base));
      }
    } else {
      *uint_ptr = va_arg(arg_list, unsigned int *);
      if (*uint_ptr == NULL) return -1;
      if (!width)
        **uint_ptr = (unsigned int)(strtoul(*str_ptr, &end_ptr, base));
      else {
        make_temp_string(temp, &str_ptr, &i, width);
        if (i == 1 && !isdigit(temp[0]) && **format_ptr != 'x' &&
            **format_ptr != 'X')
          return -1;
        if (i == 1 && !isxdigit(temp[0]) && **format_ptr != 'u' &&
            **format_ptr != 'o')
          return -1;
        **uint_ptr = (unsigned int)(strtol(temp, &end_ptr, base));
      }
    }
    if (*str_ptr == end_ptr) return -1;
    if (!width) *str_ptr = end_ptr;
    if (!suppresse) *args_count = *args_count + 1;
  }
  return return_flag;
}

int sscanf_float(char *str, const char **str_ptr, int *args_count,
                 long double **long_double_ptr, double **double_ptr,
                 float **float_ptr, va_list arg_list, int width, int suppresse,
                 int long_flag) {
  int return_flag = 0, i = 0;
  char temp[500], *end_ptr;
  if (!string_check(str)) {
    *args_count = -1;
    return_flag = -1;
  } else {
    if (suppresse) {
      strtod(*str_ptr, &end_ptr);
    } else if (long_flag == 'L') {
      *long_double_ptr = va_arg(arg_list, long double *);
      if (*long_double_ptr == NULL) return -1;
      if (!width)
        **long_double_ptr = (long double)(strtod(*str_ptr, &end_ptr));
      else {
        make_temp_string(temp, &str_ptr, &i, width);
        if ((i == 1 && !isdigit(temp[0])) ||
            (!isdigit(temp[0]) && temp[0] != '-' && temp[0] != '+' &&
             temp[0] != '.'))
          return -1;
        **long_double_ptr = (long double)(strtod(temp, &end_ptr));
      }
    } else if (long_flag == 'l') {
      *double_ptr = va_arg(arg_list, double *);
      if (*double_ptr == NULL) return -1;
      if (!width)
        **double_ptr = (double)(strtod(*str_ptr, &end_ptr));
      else {
        make_temp_string(temp, &str_ptr, &i, width);
        if ((i == 1 && !isdigit(temp[0])) ||
            (!isdigit(temp[0]) && temp[0] != '-' && temp[0] != '+' &&
             temp[0] != '.'))
          return -1;
        **double_ptr = (double)(strtod(temp, &end_ptr));
      }
    } else {
      *float_ptr = va_arg(arg_list, float *);
      if (*float_ptr == NULL) return -1;
      if (!width)
        **float_ptr = (float)(strtod(*str_ptr, &end_ptr));
      else {
        make_temp_string(temp, &str_ptr, &i, width);
        if ((i == 1 && !isdigit(temp[0])) ||
            (!isdigit(temp[0]) && temp[0] != '-' && temp[0] != '+' &&
             temp[0] != '.'))
          return -1;
        **float_ptr = (float)(strtod(temp, &end_ptr));
      }
    }
    if (*str_ptr == end_ptr) return -1;
    if (!width) *str_ptr = end_ptr;
    if (!suppresse) *args_count = *args_count + 1;
  }
  return return_flag;
}

void make_temp_string(char temp[], const char ***str_ptr, int *i, int width) {
  for (*i = 0; *i < width; *i = *i + 1) {
    temp[*i] = ***str_ptr;
    **str_ptr = **str_ptr + 1;
    if (***str_ptr == '\0' || isspace(***str_ptr)) {
      *i = *i + 1;
      break;
    }
  }
  temp[*i] = '\0';
}

int sscanf_signed(char *str, const char **format_ptr, const char **str_ptr,
                  int *args_count, long **long_ptr, short **short_ptr,
                  int **int_ptr, va_list arg_list, int width, int suppresse,
                  int long_flag) {
  int return_flag = 0, base = 0, i = 0;
  char temp[500], *end_ptr;
  if (!string_check(str)) {
    *args_count = -1;
    return_flag = -1;
  } else {
    base = (**format_ptr == 'd') * 10;
    if (suppresse) {
      strtol(*str_ptr, &end_ptr, base);
    } else if (long_flag == 'l') {
      *long_ptr = va_arg(arg_list, long *);
      if (*long_ptr == NULL) return -1;
      if (!width)
        **long_ptr = (long)strtol(*str_ptr, &end_ptr, base);
      else {
        make_temp_string(temp, &str_ptr, &i, width);
        if (i == 1 && !isdigit(temp[0])) return -1;
        **long_ptr = (long)(strtol(temp, &end_ptr, base));
      }
    } else if (long_flag == 'h') {
      *short_ptr = va_arg(arg_list, short *);
      if (*short_ptr == NULL) return -1;
      if (!width)
        **short_ptr = (short)(strtol(*str_ptr, &end_ptr, base));
      else {
        make_temp_string(temp, &str_ptr, &i, width);
        if (i == 1 && !isdigit(temp[0])) return -1;
        **short_ptr = (short)(strtol(temp, &end_ptr, base));
      }
    } else {
      *int_ptr = va_arg(arg_list, int *);
      if (*int_ptr == NULL) return -1;
      if (!width)
        **int_ptr = (int)(strtol(*str_ptr, &end_ptr, base));
      else {
        make_temp_string(temp, &str_ptr, &i, width);
        if (i == 1 && !isdigit(temp[0])) return -1;
        **int_ptr = (int)(strtol(temp, &end_ptr, base));
      }
    }
    if (*str_ptr == end_ptr) return -1;
    if (!width) *str_ptr = end_ptr;
    if (!suppresse) *args_count = *args_count + 1;
  }
  return return_flag;
}

int string_check(char *str) {
  int count = 0;
  while (*str != '\0') {
    if (*str > 32) {
      count++;
      break;
    }
    str++;
  }
  return count;
}

int sscanf_s(char *str, const char **format_ptr, const char **str_ptr,
             int *args_count, char **char_ptr, va_list arg_list, int suppresse,
             int width) {
  int return_flag = 0;
  if (!string_check(str)) {
    *args_count = -1;
    return_flag = -1;
  } else {
    while (isspace(**str_ptr)) {
      *str_ptr = *str_ptr + 1;
    }
    if (width == 0) width = 3000;

    if (suppresse) {
      for (; width > 0; width--) {
        *str_ptr = *str_ptr + 1;
        if (**str_ptr == '\0' || (isspace(**str_ptr))) {
          break;
        }
      }
      *format_ptr = *format_ptr + 1;
      return_flag = 1;
    } else {
      *char_ptr = va_arg(arg_list, char *);
      if (*char_ptr == NULL) {
        return_flag = -1;
        return return_flag;
      }
      for (; width > 0; width--) {
        **char_ptr = **str_ptr;
        if (**str_ptr == '\0' || (isspace(**str_ptr))) {
          break;
        }
        *char_ptr = *char_ptr + 1;
        *str_ptr = *str_ptr + 1;
      }
      **char_ptr = '\0';
      *args_count = *args_count + 1;
    }
  }
  return return_flag;
}

int sscanf_c(const char **format_ptr, const char **str_ptr, int *args_count,
             char **char_ptr, va_list arg_list, int suppresse) {
  int return_flag = 0;
  if (**str_ptr == '\0') {
    *args_count = -1;
    return_flag = -1;
  } else {
    if (suppresse) {
      *str_ptr = *str_ptr + 1;
      *format_ptr = *format_ptr + 1;
      return_flag = 1;
    } else {
      *char_ptr = va_arg(arg_list, char *);
      if (*char_ptr == NULL)
        return_flag = -1;
      else {
        **char_ptr = **str_ptr;
        *str_ptr = *str_ptr + 1;
        *args_count = *args_count + 1;
      }
    }
  }

  return return_flag;
}

int sscanf_n(const char **format_ptr, char *str, const char *str_ptr,
             int **int_ptr, va_list arg_list) {
  int return_flag = 0;
  *int_ptr = va_arg(arg_list, int *);
  if (*int_ptr == NULL)
    return_flag = 1;
  else {
    **int_ptr = (int)(str_ptr - str);
    if (*int_ptr == 0)
      return_flag = 1;
    else
      *format_ptr = *format_ptr + 1;
  }

  return return_flag;
}

void set_flags(const char **format_ptr, int *suppresse, int *width,
               int *long_flag) {
  char *end_ptr;
  if (**format_ptr == '*') {
    *suppresse = 1;
    *format_ptr = *format_ptr + 1;
  } else {
    *suppresse = 0;
  }

  if (isdigit(**format_ptr)) {
    *width = strtoul(*format_ptr, &end_ptr, 0);
    *format_ptr = end_ptr;
  }

  if (**format_ptr == 'l') {
    *long_flag = 'l';
    *format_ptr = *format_ptr + 1;
  } else if (**format_ptr == 'L') {
    *long_flag = 'L';
    *format_ptr = *format_ptr + 1;
  } else if (**format_ptr == 'h') {
    *long_flag = 'h';
    *format_ptr = *format_ptr + 1;
  } else {
    *long_flag = 0;
  }
}

int s21_sscanf(char *str, const char *format, ...) {
  int args_count = 0, suppresse, width, long_flag;
  const char *str_ptr = str;
  const char *format_ptr = format;
  long *long_ptr;
  int *int_ptr;
  short *short_ptr;
  unsigned long *ulong_ptr;
  unsigned short *ushort_ptr;
  unsigned int *uint_ptr;
  long double *long_double_ptr;
  double *double_ptr;
  float *float_ptr;
  char *char_ptr;
  va_list arg_list;
  va_start(arg_list, format);
  if (str == NULL || format == NULL) {
    args_count = -1;
  } else {
    while (*format_ptr != '\0') {
      suppresse = 0, width = 0, long_flag = 0;
      if (isspace(*format_ptr)) {
        skip_spaces();
        format_ptr++;
        continue;
      }
      if (*format_ptr == '%') {
        format_ptr++;
        set_flags(&format_ptr, &suppresse, &width, &long_flag);

        if ('n' == *format_ptr) {
          if (sscanf_n(&format_ptr, str, str_ptr, &int_ptr, arg_list)) break;
          continue;
        }
        if ('%' == *format_ptr) {
          skip_spaces();
          if (*str_ptr != *format_ptr) break;
          str_ptr++;
        } else if (*format_ptr == 'c') {
          int c = sscanf_c(&format_ptr, &str_ptr, &args_count, &char_ptr,
                           arg_list, suppresse);
          if (c == -1)
            break;
          else if (c == 1)
            continue;
        } else if (*format_ptr == 's') {
          int s = sscanf_s(str, &format_ptr, &str_ptr, &args_count, &char_ptr,
                           arg_list, suppresse, width);
          if (s == -1)
            break;
          else if (s == 1)
            continue;
        } else if (*format_ptr == 'i' || *format_ptr == 'd') {
          skip_spaces();
          int d = sscanf_signed(str, &format_ptr, &str_ptr, &args_count,
                                &long_ptr, &short_ptr, &int_ptr, arg_list,
                                width, suppresse, long_flag);
          if (d) break;
        } else if (*format_ptr == 'g' || *format_ptr == 'e' ||
                   *format_ptr == 'f' || *format_ptr == 'G' ||
                   *format_ptr == 'E' || *format_ptr == 'F') {
          skip_spaces();
          int f = sscanf_float(str, &str_ptr, &args_count, &long_double_ptr,
                               &double_ptr, &float_ptr, arg_list, width,
                               suppresse, long_flag);
          if (f) break;
        } else if (*format_ptr == 'u' || *format_ptr == 'o' ||
                   *format_ptr == 'x' || *format_ptr == 'X') {
          skip_spaces();
          int u = sscanf_unsigned(str, &format_ptr, &str_ptr, &args_count,
                                  &ulong_ptr, &ushort_ptr, &uint_ptr, arg_list,
                                  width, suppresse, long_flag);
          if (u) break;

        } else if (*format_ptr == 'p') {
          skip_spaces();
          int u = sscanf_unsigned(str, &format_ptr, &str_ptr, &args_count,
                                  &ulong_ptr, &ushort_ptr, &uint_ptr, arg_list,
                                  width, suppresse, long_flag);
          if (u) break;
        } else {
          break;
        }
      } else {
        if (*format_ptr != *str_ptr) {
          break;
        }
        str_ptr++;
      }
      format_ptr++;
    }
  }
  va_end(arg_list);
  return args_count;
}
