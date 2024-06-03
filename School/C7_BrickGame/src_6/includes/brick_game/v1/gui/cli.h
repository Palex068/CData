#ifndef S21_CLI_H
#define S21_CLI_H

#include <locale.h>
#include <ncurses.h>
#include <string.h>

#include "../constants.h"
#include "../interfaces.h"
#include "cli_constants.h"
#include "cli_objects.h"

void CLI_createCli(GS_cli_t *cli);
void CLI_initCurses(void);

void CLI_removeCli(GS_cli_t *cli);

void CLI_createWindowWithBoard(WINDOW **window, BG_Point2D_t window_size,
                               BG_Point2D_t window_pos);

BG_UserInput_t CLI_getUserInput(void);

void CLI_printCurrentState(BG_GameInfo_t game_info);
void CLI_statWinPrint(GS_cli_t *cli, BG_GameInfo_t *game_info);

void CLI_sliInfoKeeper(GS_cli_t **cli);

void CLI_print_full_line(WINDOW *win, size_t count, chtype symbol);

void CLI_printBoardSymbol(WINDOW *win, chtype symbol);

void CLI_print_start_preview();
void CLI_print_end_preview();
void CLI_print_pause_preview();

void printNickname(GS_cli_t *cli);

#endif