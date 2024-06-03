#ifndef S21_CLI_OBJECTS_H
#define S21_CLI_OBJECTS_H

#include "../objects.h"
#include "cli_constants.h"

typedef struct {
  WINDOW *game_win;
  BG_Point2D_t game_win_size;

  BG_Point2D_t game_win_pos;

  WINDOW *stat_win;
  BG_Point2D_t stat_win_size;

  BG_Point2D_t stat_win_pos;

} GS_cli_t;

typedef enum {
  GS_ColorGray = 100,

  GS_ColorRed,
  GS_ColorOrange,
  GS_ColorYellow,
  GS_ColorPink,
  GS_ColorGreen,
  GS_ColorBlue,
  GS_ColorPurple,

} GS_colors_t;

#endif