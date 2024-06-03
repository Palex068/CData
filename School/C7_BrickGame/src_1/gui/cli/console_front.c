#include "console_front.h"

void render(GameInfo_t info) {
  WINDOW *game_window = newwin(FIELD_H + 2, 3 * FIELD_W + 2, 0, 0);
  refresh();
  box(game_window, 0, 0);

  for (int i = 0; i < FIELD_H; i++) {
    for (int j = 0; j < FIELD_W; j++) {
      if (info.field[i][j] == 1) {
        mvwprintw(game_window, i + 1, 3 * j + 1, "[ ]");
      } else {
        mvwprintw(game_window, i + 1, 3 * j + 1, "   ");
      }
    }
  }

  wrefresh(game_window);

  if (info.pause != None) {
    WINDOW *text_window = newwin(3, 7, 9, 13);
    refresh();
    box(text_window, 0, 0);
    if (info.pause == GameStart) {
      mvwprintw(text_window, 1, 1, "START");
    } else {
      mvwprintw(text_window, 1, 1, "PAUSE");
    }
    wrefresh(text_window);
    delwin(text_window);
  }

  WINDOW *params_window =
      newwin(FIELD_H + 2, 3 * FIELD_W + 2, 0, 3 * FIELD_W + 4);
  refresh();
  box(params_window, 0, 0);

  char score[10];
  sprintf(score, "%d", info.score);
  mvwprintw(params_window, 2, 5, "SCORE: ");
  mvwprintw(params_window, 2, 12, score);

  char high_score[10];
  sprintf(high_score, "%d", info.high_score);
  mvwprintw(params_window, 4, 5, "MAX SCORE: ");
  mvwprintw(params_window, 4, 16, high_score);

  char level[10];
  sprintf(level, "%d", info.level);
  mvwprintw(params_window, 6, 5, "LEVEL: ");
  mvwprintw(params_window, 6, 12, level);

  mvwprintw(params_window, 12, 5, "NEXT");
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (info.next[i][j] == 1) {
        mvwprintw(params_window, 12 + 4 - i, 5 + 7 + 3 * j, "[ ]");
      }
    }
  }

  wrefresh(params_window);

  for (int i = 0; i < FIELD_H; i++) {
    free(info.field[i]);
  }
  free(info.field);

  for (int i = 0; i < 4; i++) {
    free(info.next[i]);
  }
  free(info.next);

  delwin(game_window);
  delwin(params_window);
}

void terminate_game() {
  endwin();
  exit(0);
}


