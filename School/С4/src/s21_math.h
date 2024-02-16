#ifndef C4_S21_MATH_1_S21_MATH_H
#define C4_S21_MATH_1_S21_MATH_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define S21_EPS 1e-15
#define S21_NAN 0.0 / 0.0
#define S21_INF_POS 1.0 / 0.0
#define S21_INF_NEG -1.0 / 0.0
#define S21_LN10 2.30258509299
#define S21_PI 3.1415926535897932384626433832795

int s21_abs(int x);
long double s21_ceil(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sqrt(double x);
long double s21_cos(double x);
long double s21_sin(double x);
long double s21_tan(double x);
long double s21_atan(double x);
long double s21_asin(double x);
long double s21_acos(double x);

long double s21_atan_support(double x);
double s21_acos_support(double x);

#endif  // C4_S21_MATH_1_S21_MATH_H
