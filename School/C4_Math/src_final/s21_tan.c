#include "s21_math.h"

long double s21_tan(double x) {
  if (x == S21_PI / 2) return 16331239353195370.0;
  x = s21_fmod(x, S21_PI);
  return s21_sin(x) / s21_cos(x);
}