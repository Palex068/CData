#ifndef S21_STRING_H
#define S21_STRING_H

#define S21_NULL ((void *)0)
#include <stdarg.h>

typedef long unsigned s21_size_t;

s21_size_t s21_strlen(const char *str);
char *s21_strchr(const char *str, int c);
void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
char *s21_strcat(char *destination, const char *source);
char *s21_strrchr(const char *str, int c);
char *s21_strerror(int errnum);
int compare(const char *haystack, const char *needle);
const char *s21_strstr(const char *haystack, const char *needle);
int s21_delim(char ch, const char *delim);
char *s21_strtok(char *str, const char *delim);
char *s21_strpbrk(const char *str1, const char *str2);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strcpy(char *dest, const char *src);
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);
char *reverse(char *buffer, int i, int j);
void some_flags_acception(char *buffer, double value, int *i, int plus_sign);
void digit_spase_fill(char *buffer, int length, int *i, char ch);
void hex_sharp_fill(char *buffer, long long int value, int sharp, int flag,
                    int *i);
char *digit_flag_acception(long long int value, char *buffer, int base,
                           int flag, int plus_sign, int zero, int length,
                           int left_aligment, int accuracy, int sharp);
char *itoa(long long int value, char *buffer, int base, int flag, int accuracy,
           int long_flag);
int ch_to_dig(int ch);
char *float_flags_acception(double value, char *buffer, int plus_sign, int zero,
                            int length, int left_aligment);
char *itoa_float(long double value, char *buffer);
int num_length(long long int int_part);
void func_space_fill(char *str, int **str_ind);
void exp_calculation(long double *float_num, int *sign_flag, int *exp_num);
void exp_round(long double *int_part, int flag, int sign_flag, int *exp_num);
void exp_part_cat(char *string, int exp_num, int sign_flag, int flag);
void float_num_rounding(long double *float_part, long double *int_part,
                        long double float_num, int accuracy);
void find_zeros(long double *float_part, int *zero_count, int accuracy);
void uppercase_string(char *string, int flag);
void s21_d_func(long long int int_num, char *str, int *str_ind, int flag,
                int plus_sign, int zero, int length, int left_aligment,
                int accuracy, int sharp, int long_flag);
void s21_f_func(long double float_num, char *str, int *str_ind, int flag,
                int plus_sign, int zero, int length, int left_aligment,
                int f_accuracy, int sharp);
void s21_g_func(long double float_num, char *str, int *str_ind, int flag,
                int plus_sign, int zero, int length, int left_aligment,
                int f_accuracy, int sharp);
void s21_c_func(int ch, char *str, int *str_ind, int length, int left_aligment);
void s21_s_func(char *str_arg, char *str, int *str_ind, int s_accuracy,
                int length, int left_aligment);
void s21_sprintf_flags_acception(const char *format, int *left_aligment,
                                 int *sharp, int *plus_sign, int *zero, int *i);
void s21_sprintf_width_acception(const char *format, va_list arg_list,
                                 int *left_aligment, int *length, int *i);
void s21_sprintf_precision_acception(const char *format, va_list arg_list,
                                     int *accuracy, int *f_accuracy,
                                     int *s_accuracy, int *i);
void s21_sprintf_length_acception(const char *format, int *long_flag, int *i);
void set_float_length(long double *float_num, va_list arg_list, int long_flag);
int s21_sprintf(char *str, const char *format, ...);
int string_check(char *str);
void set_flags(const char **format_ptr, int *suppresse, int *width,
               int *long_flag);
void make_temp_string(char temp[], const char ***str_ptr, int *i, int width);
int sscanf_n(const char **format_ptr, char *str, const char *str_ptr,
             int **int_ptr, va_list arg_list);
int sscanf_c(const char **format_ptr, const char **str_ptr, int *args_count,
             char **char_ptr, va_list arg_list, int suppresse);
int sscanf_s(char *str, const char **format_ptr, const char **str_ptr,
             int *args_count, char **char_ptr, va_list arg_list, int suppresse,
             int width);
int sscanf_signed(char *str, const char **format_ptr, const char **str_ptr,
                  int *args_count, long **long_ptr, short **short_ptr,
                  int **int_ptr, va_list arg_list, int width, int suppresse,
                  int long_flag);
int sscanf_float(char *str, const char **str_ptr, int *args_count,
                 long double **long_double_ptr, double **double_ptr,
                 float **float_ptr, va_list arg_list, int width, int suppresse,
                 int long_flag);
int sscanf_unsigned(char *str, const char **format_ptr, const char **str_ptr,
                    int *args_count, unsigned long **ulong_ptr,
                    unsigned short **ushort_ptr, unsigned int **uint_ptr,
                    va_list arg_list, int width, int suppresse, int long_flag);
int s21_sscanf(char *str, const char *format, ...);

#endif
