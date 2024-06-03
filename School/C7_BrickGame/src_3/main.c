#include "gui/cli/frontend.h"

int main() {
  WIN_INIT();
  BACK_INIT();
  GameInfo_t *gameInfo_t = getInstance_GameInfo_t();
  UserAction_t *action = getInstance_UserAction_t();
  figure I = {0};
  figure O = {0};
  figure J = {0};
  figure L = {0};
  figure S = {0};
  figure Z = {0};
  figure T = {0};
  int *hold = getInstance_hold();
  int *ch = getInstance_ch();
  FIGURE_INIT();
  figure figs[] = {I, O, J, L, S, Z, T};
  figure cf = figs[rand() % (FIG_NUM)];
  matrix *matr = getInstance_cur_fig();
  init_matrix();
  copy_data_1(matr->cur_fig, cf.fig);
  init_gameinfo_t();
  figure temp = figs[rand() % (FIG_NUM)];
  copy_data_1(gameInfo_t->next, temp.fig);
  int *x = getInstance_x();
  int *y = getInstance_y();
  double delay = SPEED_FRACTION - 0.1;
  WINDOW *main_win = newwin(MAINWIN_H, MAINWIN_W, MAINWIN_Y, MAINWIN_X);
  box(main_win, 0, 0);
  WINDOW *aux_win =
      newwin(AUXWIN_H, AUXWIN_W, MAINWIN_Y, MAINWIN_X + MAINWIN_W);
  box(aux_win, 0, 0);
  nodelay(main_win, 1);
  keypad(main_win, TRUE);
  printfig(aux_win, gameInfo_t->next, NF_Y, NF_X);
  TABLE_INFO();
  while (*action != Terminate) {
    clock_t start = clock();
    clock_t finish = start + (delay * CLOCKS_PER_SEC);
    while (clock() < finish) {
      *gameInfo_t = updateCurrentState();
      userInput(*action, *hold);
      go_to(action, hold, gameInfo_t->pause);
      if (*action == Start) {
        PRINT_START();
      } else if (!gameInfo_t->pause) {
        PRINT_PAUSE();
      } else
        UNPRINT_PAUSE();
      nodelay(main_win, gameInfo_t->pause);
      *ch = wgetch(main_win);
      draw_field(main_win, gameInfo_t->field);
    }
    draw_field(main_win, gameInfo_t->field);

    if (!move_fig(gameInfo_t->field, matr->cur_fig, x, y, M_D)) {
      check_the_end();
      *x = 3;
      *y = -1;
      copy_data_2(matr->cur_fig, gameInfo_t->next);
      unprintfig(aux_win, NF_Y, NF_X);
      figure temp = figs[rand() % (FIG_NUM)];
      copy_data_1(gameInfo_t->next, temp.fig);
      printfig(aux_win, gameInfo_t->next, NF_Y, NF_X);
      fill_test(gameInfo_t->field, &(gameInfo_t->score));
      mvwprintw(aux_win, SCORE_LINE, 1, "Score: %d", gameInfo_t->score);
      set_high_score();
      mvwprintw(aux_win, HIGH_SCORE_LINE, 1, "H_score: %d",
                gameInfo_t->high_score);
      set_speed(&delay);
      mvwprintw(aux_win, SPEED_LINE, 1, "SPEED: %d", gameInfo_t->speed);
      wrefresh(aux_win);
    }
  }
  delete_field_next(gameInfo_t);
  uninit_matrix(matr);
  WIN_DEINIT();
  return 0;
}
