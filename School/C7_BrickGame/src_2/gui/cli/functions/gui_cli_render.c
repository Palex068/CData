#include <errno.h>
#include <string.h>

#include "common/game_info_t.h"
#include "gui_cli.h"

void gui_cli_render(game_windows_t *windows, game_info_t *game_info) {
  if (!windows) return;

  int term_x = 0, term_y = 0;
  term_size(&term_y, &term_x);

  if (term_y >= windows->main_win.data.min_hight &&
      term_x >= windows->main_win.data.min_width) {
    destroy_supp_win(windows);
    box(windows->main_win.win, 0, 0);
    box(windows->stat_win.win, 0, 0);
    wnoutrefresh(windows->main_win.win);
    wnoutrefresh(windows->stat_win.win);

    render_field(&windows->game_win, game_info->field, field_height,
                 field_width, 1);
    add_sup_win(windows,
                (win_data_t){.hight = 4,
                             .min_hight = 4,
                             .width = windows->stat_win.data.min_width - 2,
                             .min_width = windows->stat_win.data.min_width - 2,
                             .start_x = 1,
                             .start_y = 1,
                             .label = "HISCORE"});
    render_score(&windows->stats_winds[windows->count_stat_win - 1],
                 game_info->high_score);

    add_sup_win(windows,
                (win_data_t){.hight = 4,
                             .min_hight = 4,
                             .width = windows->stat_win.data.min_width - 2,
                             .min_width = windows->stat_win.data.min_width - 2,
                             .start_x = 1,
                             .start_y = 5,
                             .label = "SCORE"});
    render_score(&windows->stats_winds[windows->count_stat_win - 1],
                 game_info->score);

    add_sup_win(windows,
                (win_data_t){.hight = 4,
                             .min_hight = 4,
                             .width = windows->stat_win.data.min_width - 2,
                             .min_width = windows->stat_win.data.min_width - 2,
                             .start_x = 1,
                             .start_y = 9,
                             .label = "LEVEL"});
    render_score(&windows->stats_winds[windows->count_stat_win - 1],
                 game_info->level);

    add_sup_win(windows,
                (win_data_t){.hight = 5,
                             .min_hight = 4,
                             .width = windows->stat_win.data.min_width - 2,
                             .min_width = windows->stat_win.data.min_width - 2,
                             .start_x = 1,
                             .start_y = 13,
                             .label = "NEXT"});
    render_field(&windows->stats_winds[windows->count_stat_win - 1],
                 game_info->next, brick_height, brick_width, 8);
  } else {
    small_win_banner(term_y, term_x);
  }

  doupdate();
}

int render_field(win_t *window, int **field, int higth, int width, int offset) {
  if (!window || !field) return EFAULT;

  init_pair(1, 0, COLOR_RED);
  init_pair(2, 0, COLOR_GREEN);
  init_pair(3, 0, COLOR_YELLOW);
  init_pair(4, 0, COLOR_BLUE);
  init_pair(5, 0, COLOR_MAGENTA);
  init_pair(6, 0, COLOR_CYAN);
  init_pair(7, 0, COLOR_WHITE);

  // render
  for (int i = 0; i < higth; i++) {
    for (int j = 0; j < width; j++)
      if (field[i][j]) {
        wattrset(window->win, COLOR_PAIR(field[i][j]));
        mvwaddstr(window->win, 1 + i, offset + 2 * j, "  ");
        wattrset(window->win, 0);
      } else
        mvwaddstr(window->win, 1 + i, offset + 2 * j, "  ");
  }

  box(window->win, 0, 0);
  if (window->data.label) mvwaddstr(window->win, 1, 1, window->data.label);

  // flag_to_update
  wnoutrefresh(window->win);
  return 0;
}

int render_score(win_t *window, int value) {
  if (!window) return EFAULT;

  char buffer[128] = {0};
  sprintf(buffer, "%d", value);

  mvwaddstr(window->win, window->data.hight - 2,
            window->data.width - strlen(buffer) - 1, buffer);

  box(window->win, 0, 0);
  if (window->data.label) mvwaddstr(window->win, 1, 1, window->data.label);

  // flag_to_update
  wnoutrefresh(window->win);
  return 0;
}
