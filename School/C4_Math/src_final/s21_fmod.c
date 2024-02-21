#include "s21_math.h"

long double s21_fmod(double x, double y) { return x - (long)(x / y) * y; }