#ifndef GUI_CLI_H
#define GUI_CLI_H

#include "common/game_info_t.h"
#include "common/runtime_t.h"
#include "windows.h"

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

enum brick_setting { brick_height = 4, brick_width = 4 };

void gui_cli_render(game_windows_t *windows, game_info_t *game_info);
int render_score(win_t *window, int value);
int render_field(win_t *window, int **field, int higth, int width, int offset);

void gui_cli_resize();
int term_size(int *y, int *x);
void *gui_cli_loop(runtime_t *);

extern game_info_t update_current_state();

#endif