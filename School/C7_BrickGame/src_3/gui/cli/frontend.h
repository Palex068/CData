#ifndef FRONTEND_H
#define FRONTEND_H

#include "../../brick_game/tetris/backend.h"

#define NF_X 1
#define NF_Y 0
#define MAINWIN_W 22
#define MAINWIN_H 22
#define MAINWIN_X 15
#define MAINWIN_Y 0
#define AUXWIN_W 17
#define AUXWIN_H 22
#define SCORE_LINE 5
#define HIGH_SCORE_LINE 7
#define SPEED_LINE 9
#define PAUSE_LINE 11

#define WIN_INIT()         \
  {                        \
    initscr();             \
    cbreak();              \
    noecho();              \
    curs_set(0);           \
    keypad(stdscr, TRUE);  \
    nodelay(stdscr, 1);    \
    start_color();         \
    setlocale(LC_ALL, ""); \
  }
#define WIN_DEINIT()  \
  {                   \
    wclear(main_win); \
    wclear(aux_win);  \
    wclear(stdscr);   \
    endwin();         \
  }
#define PRINT_START()                                      \
  {                                                        \
    mvwprintw(aux_win, PAUSE_LINE, 1, "Tap Enter");        \
    mvwprintw(aux_win, PAUSE_LINE + 1, 1, "for started!"); \
    wrefresh(aux_win);                                     \
  }
#define PRINT_PAUSE()                             \
  {                                               \
    mvwprintw(aux_win, PAUSE_LINE, 1, "  Pause"); \
    wrefresh(aux_win);                            \
  }
#define UNPRINT_PAUSE()                                     \
  {                                                         \
    mvwprintw(aux_win, PAUSE_LINE, 1, "           ");       \
    mvwprintw(aux_win, PAUSE_LINE + 1, 1, "             "); \
    wrefresh(aux_win);                                      \
  }
#define TABLE_INFO()                                                   \
  {                                                                    \
    mvwprintw(aux_win, SCORE_LINE, 1, "Score: %d", gameInfo_t->score); \
    mvwprintw(aux_win, HIGH_SCORE_LINE, 1, "H_score: %d",              \
              gameInfo_t->high_score);                                 \
    mvwprintw(aux_win, SPEED_LINE, 1, "Speed: %d", gameInfo_t->speed); \
    wrefresh(aux_win);                                                 \
  }

void printfig(WINDOW *wind, int **F, int y, int x);
void putblock(WINDOW *wind, int y, int x);
void unprintfig(WINDOW *wind, int y, int x);
void delblock(WINDOW *wind, int y, int x);
void draw_field(WINDOW *wind, int **field);

#endif  // FRONTEND_H