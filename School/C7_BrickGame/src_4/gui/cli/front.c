#include "front.h"

void draw_board(GameInfo_t *game, WINDOW *win) {
  for (int row = BLOCK_SIZE; row < HEIGHT_WF; row++) {
    for (int col = 0; col < WIDTH; col++) {
      if (game->field[row][col] == 0) {
        wbkgdset(win, COLOR_PAIR(1));
        mvwprintw(win, row + 1, 2 * col + 1, "%c", ' ');
        mvwprintw(win, row + 1, 2 * col + 2, "%c", ' ');
      } else if (game->field[row][col] == 1) {
        wbkgdset(win, COLOR_PAIR(2));
        mvwprintw(win, row + 1, 2 * col + 1, "%c", ' ');
        mvwprintw(win, row + 1, 2 * col + 2, "%c", ' ');
      } else if (game->field[row][col] == 2) {
        wbkgdset(win, COLOR_PAIR(3));
        mvwprintw(win, row + 1, 2 * col + 1, "%c", ' ');
        mvwprintw(win, row + 1, 2 * col + 2, "%c", ' ');
      }
    }
  }
}

void draw_next(GameInfo_t *game, WINDOW *nextfigure) {
  werase(nextfigure);
  wbkgd(nextfigure, COLOR_PAIR(5));
  for (int row = 0; row < BLOCK_SIZE; row++) {
    for (int col = 0; col < BLOCK_SIZE; col++) {
      if (game->next[row][col] == 0) {
        wbkgdset(nextfigure, COLOR_PAIR(1));
        mvwprintw(nextfigure, row + 1, 2 * col + 1, "%c", ' ');
        mvwprintw(nextfigure, row + 1, 2 * col + 2, "%c", ' ');
      } else if (game->next[row][col] == 1) {
        wbkgdset(nextfigure, COLOR_PAIR(2));
        mvwprintw(nextfigure, row + 1, 2 * col + 1, "%c", ' ');
        mvwprintw(nextfigure, row + 1, 2 * col + 2, "%c", ' ');
      }
    }
  }
  wrefresh(nextfigure);
}

void draw_addinfo(GameInfo_t *game, WINDOW *addinfo) {
  werase(addinfo);
  char score[10];
  char high[10];
  char speed[10];
  sprintf(score, "%d", game->score);
  sprintf(high, "%d", game->high_score);
  sprintf(speed, "%d", game->speed);
  wbkgd(addinfo, COLOR_PAIR(5));
  wattron(addinfo, COLOR_PAIR(5));
  mvwprintw(addinfo, 1, 1, "SCORE:");
  mvwprintw(addinfo, 2, 1, score);
  mvwprintw(addinfo, 4, 1, "RECORD:");
  mvwprintw(addinfo, 5, 1, high);
  mvwprintw(addinfo, 7, 1, "SPEED:");
  mvwprintw(addinfo, 8, 1, speed);
  wattroff(addinfo, COLOR_PAIR(5));
  wrefresh(addinfo);
}

void init_curses() {
  initscr();
  keypad(stdscr, TRUE);
  nodelay(stdscr, TRUE);
  raw();
  noecho();
  cbreak();
  curs_set(0);
  start_color();
  init_pair(1, COLOR_BLACK, COLOR_WHITE);
  init_pair(2, COLOR_RED, COLOR_GREEN);
  init_pair(3, COLOR_RED, COLOR_BLUE);
  init_pair(5, COLOR_BLACK, COLOR_WHITE);
}

WinStruct *init_windows() {
  WinStruct *window = (WinStruct *)malloc(sizeof(WinStruct));
  if (window == NULL) {
    return NULL;
  }
  window->win = newwin(26, 22, 5, 5);
  window->nextfigure = newwin(7, 12, 11, 30);
  window->addinfo = newwin(11, 12, 20, 30);
  return window;
}

void draw_frontend(GameInfo_t *game, WinStruct *window) {
  if (game->status == Start) {
    draw_board(game, window->win);
    mvwprintw(window->win, 12, 5, "%s", "WELCOME TO");
    mvwprintw(window->win, 13, 3, "%s", "SKIBIDI KIRPICHI");
    mvwprintw(window->win, 16, 4, "%s", "PRESS ANY KEY");
    mvwprintw(window->win, 17, 6, "%s", "TO START");
    wrefresh(window->win);
    int ch = getchar();
    (void)ch;
    nodelay(window->win, true);
    game->status = Down;
  }
  if (game->status != Pause && game->status != GameOver) {
    draw_board(game, window->win);
    draw_next(game, window->nextfigure);
    draw_addinfo(game, window->addinfo);
  } else if (game->status == Pause) {
    draw_pause(window);
  } else if (game->status == GameOver) {
    draw_gameover(window);
  }
  wrefresh(window->win);
  wrefresh(window->nextfigure);
  wrefresh(window->addinfo);
  napms(50);
}

void draw_pause(WinStruct *window) {
  wbkgdset(window->win, COLOR_PAIR(1));
  mvwprintw(window->win, 13, 8, "PAUSE");
  wrefresh(window->win);
  nodelay(stdscr, FALSE);
  getch();
  nodelay(stdscr, TRUE);
}

void draw_gameover(WinStruct *window) {
  wattron(window->win, COLOR_PAIR(5));
  mvwprintw(window->win, 13, 6, "GAME OVER");
  wattroff(window->win, COLOR_PAIR(5));
  wrefresh(window->win);
}