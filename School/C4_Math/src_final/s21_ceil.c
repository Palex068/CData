#include "s21_math.h"

long double s21_ceil(double x) {
  return ((long)x == x || x <= 0) ? (long)x : (long)x + 1;
}