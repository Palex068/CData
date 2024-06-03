#include "frontend.h"

void printfig(WINDOW *wind, int **F, int y, int x) {
  for (int i = 0; i < FIGURE_SIZE; i++)
    for (int j = 0; j < FIGURE_SIZE; j++)
      if (F[i][j]) putblock(wind, y + i, x + j);
  wrefresh(wind);
}

void putblock(WINDOW *wind, int y, int x) {
  init_pair(7, 7, 7);
  wattron(wind, COLOR_PAIR(7));
  mvwprintw(wind, y + 1, x * 2 + 1, "  ");
  wattroff(wind, COLOR_PAIR(7));
}

void unprintfig(WINDOW *wind, int y, int x) {
  for (int i = 0; i < FIGURE_SIZE; i++)
    for (int j = 0; j < FIGURE_SIZE; j++) delblock(wind, y + i, x + j);
  wrefresh(wind);
}

void delblock(WINDOW *wind, int y, int x) {
  mvwprintw(wind, y + 1, x * 2 + 1, "  ");
}

void draw_field(WINDOW *wind, int **field) {
  for (int i = 0; i < FIELD_H; i++)
    for (int j = 0; j < FIELD_W; j++) {
      delblock(wind, i, j);
      if (field[i][j]) putblock(wind, i, j);
    }
  wrefresh(wind);
}
