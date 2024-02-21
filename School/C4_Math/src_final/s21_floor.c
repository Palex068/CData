#include "s21_math.h"

long double s21_floor(double x) {
  if (x == S21_INF_NEG || x != x) return (long)-x;
  return ((long)x == x || x >= 0) ? (long)x : (long)x - 1;
}