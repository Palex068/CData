#ifndef S21_OBJECTS_H
#define S21_OBJECTS_H

#include <inttypes.h>

#define BG_POINT2D_TYPE int_fast32_t
typedef struct {
  int_fast32_t x;
  int_fast32_t y;

} BG_Point2D_t;

typedef enum {
  TTRS_EMPTY = 0,
  TTRS_FULL = 1,

} BG_BoardCeil_t;

#endif