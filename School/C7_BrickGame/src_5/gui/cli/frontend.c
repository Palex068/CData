#include "frontend.h"

void drawStartMessage() {
  MVPRINTW(HEIGHT / 2, (WIDTH - INTRO_MESSAGE_LEN) / 2 + 6, INTRO_MESSAGE);
}

void drawBorders() {
  GameInfo_t stats = updateCurrentState();
  printBorders(0, HEIGHT + 1, 0, HEIGHT + 1);
  printBorders(0, HEIGHT + 1, HEIGHT + 2, HEIGHT + HUD_WIDTH + 3);
  printBorders(1, 8, HEIGHT + 3, HEIGHT + HUD_WIDTH + 2);

  MVPRINTW(2, HEIGHT + 4, " NEXT");
  MVPRINTW(10, HEIGHT + 4, "HIGH SCORE:");
  MVPRINTW(11, HEIGHT + 4, "%d", stats.high_score);
  MVPRINTW(13, HEIGHT + 4, "SCORE:");
  MVPRINTW(14, HEIGHT + 4, "%d", stats.score);
  MVPRINTW(17, HEIGHT + 4, "LEVEL %d", stats.level);
  MVPRINTW(-1, 1, "You are playing tetris by ananar27");
}

void printBorders(int top_y, int bottom_y, int left_x, int right_x) {
  MVADDCH(top_y, left_x, ACS_ULCORNER);

  int i = left_x + 1;

  for (; i < right_x; i++) MVADDCH(top_y, i, ACS_HLINE);
  MVADDCH(top_y, i, ACS_URCORNER);

  for (int i = top_y + 1; i < bottom_y; i++) {
    MVADDCH(i, left_x, ACS_VLINE);
    MVADDCH(i, right_x, ACS_VLINE);
  }

  MVADDCH(bottom_y, left_x, ACS_LLCORNER);
  i = left_x + 1;
  for (; i < right_x; i++) MVADDCH(bottom_y, i, ACS_HLINE);
  MVADDCH(bottom_y, i, ACS_LRCORNER);
}

void updateField() {
  short c = CURRENT_COLOR;

  init_pair(1, COLOR_CYAN, COLOR_BLACK);
  init_pair(2, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(3, COLOR_RED, COLOR_BLACK);
  init_pair(4, COLOR_GREEN, COLOR_BLACK);

  GameInfo_t stats = updateCurrentState();
  if (stats.started && !stats.stop) {
    clear();
    drawBorders();
    for (int i = 0; i < HEIGHT; i++) {
      for (int j = 0; j < WIDTH; j++) {
        if (stats.field[i][j] == 1) {
          MVADDCH(i + 1, j * 2 + 1, ' ' | A_REVERSE | COLOR_PAIR(c));
          MVADDCH(i + 1, j * 2 + 2, ' ' | A_REVERSE | COLOR_PAIR(c));
        } else {
          MVADDCH(i + 1, j * 2 + 1, ' ');
          MVADDCH(i + 1, j * 2 + 2, ' ');
        }
      }
    }
    DrawNext(c);
    refresh();

  } else if (stats.started == 0) {
    CURSINIT();
    drawStartMessage();
    start_color();
    COLOR_PAIR(c);
  } else {
    redrawField();
  }
}

void DrawNext(short c) {
  GameInfo_t stats = updateCurrentState();
  int start_y = 4;
  int start_x = HEIGHT + 4;
  for (int i = 0; i < CELLS; i++) {
    for (int j = 0; j < CELLS + 1; j++) {
      MVADDCH(i + start_y, j * 2 + start_x, ' ');
      MVADDCH(i + start_y, j * 2 + start_x + 1, ' ');
    }
  }
  for (int i = 0; i < CELLS; i++) {
    MVADDCH(stats.next[i].loc.row + start_y + 1,
            stats.next[i].loc.col * 2 + 1 + start_x,
            ' ' | A_REVERSE | COLOR_PAIR(c));
    MVADDCH(stats.next[i].loc.row + start_y + 1,
            stats.next[i].loc.col * 2 + 2 + start_x,
            ' ' | A_REVERSE | COLOR_PAIR(c));
  }
}

void redrawField() {
  GameInfo_t stats = updateCurrentState();
  clear();
  MVPRINTW(HEIGHT / 2 - 3, (WIDTH - (int)strlen(FINAL_MESSAGE_1)) / 2 + 5,
           FINAL_MESSAGE_1);
  MVPRINTW(HEIGHT / 2 - 2, (WIDTH - (int)strlen(FINAL_MESSAGE_2)) / 2 + 5,
           FINAL_MESSAGE_2, stats.score);
  MVPRINTW(HEIGHT / 2 - 1, (WIDTH - (int)strlen(FINAL_MESSAGE_3)) / 2 + 5,
           FINAL_MESSAGE_3, stats.high_score);
  MVPRINTW(HEIGHT / 2, (WIDTH - (int)strlen(FINAL_MESSAGE_4)) / 2 + 5,
           FINAL_MESSAGE_4);
}
