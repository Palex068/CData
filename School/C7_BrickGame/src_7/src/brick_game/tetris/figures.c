#include "figures.h"

Figures getRandomFigure() {
  Figures figure = {
      .piece = rand() % MAX_PIECES,
      .rotation = STRAIGHT,
      .x = 3,
      .y = 1,
  };

  return figure;
}

choosedFig shapes() {
  static char shapes[MAX_PIECES][MAX_ROTATION][MAX_BLOCKS][MAX_BLOCKS] = {
      {
          /* stick +*/
          {{0, 1}, {0, 1}, {0, 1}, {0, 1}},
          {{0}, {0}, {1, 1, 1, 1}},
          {{0, 0, 1}, {0, 0, 1}, {0, 0, 1}, {0, 0, 1}},
          {{0}, {1, 1, 1, 1}},
      },
      {
          /* square */
          {{0}, {1, 1}, {1, 1}, {0}},
          {{0}, {1, 1}, {1, 1}, {0}},
          {{0}, {1, 1}, {1, 1}, {0}},
          {{0}, {1, 1}, {1, 1}, {0}},
      },
      {
          /* L +*/
          {{0}, {0, 1, 1}, {0, 1}, {0, 1}},
          {{0}, {1}, {1, 1, 1}, {0}},
          {{0}, {0, 1}, {0, 1}, {1, 1}},
          {{0}, {0}, {1, 1, 1}, {0, 0, 1}},
      },
      {
          /* J +*/
          {{0}, {1, 1}, {0, 1}, {0, 1}},
          {{0}, {0}, {1, 1, 1}, {1}},
          {{0}, {0, 1}, {0, 1}, {0, 1, 1}},
          {{0}, {0, 0, 1}, {1, 1, 1}, {0}},
      },
      {
          /* T */
          {{0}, {0, 1}, {1, 1, 1}, {0}},
          {{0}, {0, 1}, {1, 1}, {0, 1}},
          {{0}, {0}, {1, 1, 1}, {0, 1}},
          {{0}, {0, 1}, {0, 1, 1}, {0, 1}},
      },
      {
          /* S +*/
          {{0}, {0, 1}, {1, 1}, {1, 0}},
          {{0}, {0}, {1, 1}, {0, 1, 1}},
          {{0}, {0, 0, 1}, {0, 1, 1}, {0, 1}},
          {{0}, {1, 1}, {0, 1, 1}, {0}},
      },
      {
          /* Z */
          {{0}, {1}, {1, 1}, {0, 1}},
          {{0}, {0}, {0, 1, 1}, {1, 1}},
          {{0}, {0, 1}, {0, 1, 1}, {0, 0, 1}},
          {{0}, {0, 1, 1}, {1, 1}, {0}},
      },
  };
  return shapes;
}