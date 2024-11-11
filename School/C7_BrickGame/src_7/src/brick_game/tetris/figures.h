#ifndef FIGURES_H_SENTRY
#define FIGURES_H_SENTRY

#include <stdlib.h>
#include <time.h>

#define MAX_BLOCKS 4

enum piece {
  PIECE_I,
  PIECE_O,
  PIECE_L,
  PIECE_J,
  PIECE_T,
  PIECE_S,
  PIECE_Z,
  MAX_PIECES,
};

enum rotation {
  STRAIGHT,
  LEFT,
  RIGHT,
  INVERTED,
  MAX_ROTATION,
};

typedef struct {
  enum piece piece;
  enum rotation rotation;
  int x, y;
} Figures;

typedef char (*choosedFig)[4][4][4];

Figures getRandomFigure();
choosedFig shapes();

#endif