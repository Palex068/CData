#include "../../../includes/brick_game/v1/gui/cli.h"

void CLI_createCli(GS_cli_t *cli) {
  CLI_initCurses();

  {
    cli->game_win_size.x = BG_BOARD_COLUMNS_COUNT * CLI_VIEW_CHAR_SIZE_X +
                           (CLI_WIN_BORDER_SIZE_X * 2);
    cli->game_win_size.y = BG_BOARD_ROWS_COUNT * CLI_VIEW_CHAR_SIZE_Y +
                           (CLI_WIN_BORDER_SIZE_Y * 2);

    cli->stat_win_size.x =
        CLI_GAME_INFO_WIN_COLUMN_COUNT * CLI_VIEW_CHAR_SIZE_X +
        (CLI_WIN_BORDER_SIZE_X * 2);
    cli->stat_win_size.y = CLI_GAME_INFO_WIN_ROWS_COUNT * CLI_VIEW_CHAR_SIZE_Y +
                           (CLI_WIN_BORDER_SIZE_Y * 2);

    cli->game_win_pos.x = 1;
    cli->game_win_pos.y = 1;

    cli->stat_win_pos.x = cli->game_win_pos.x + cli->game_win_size.x;
    cli->stat_win_pos.y = cli->game_win_pos.y;
  }

  CLI_createWindowWithBoard(&cli->game_win, cli->game_win_size,
                            cli->game_win_pos);
  CLI_createWindowWithBoard(&cli->stat_win, cli->stat_win_size,
                            cli->stat_win_pos);

  CLI_sliInfoKeeper(&cli);
}

void CLI_initCurses(void) {
  {  // инициализация ncurses
    setlocale(LC_ALL, "");

    initscr();

    cbreak();
    noecho();
    nodelay(stdscr, true);
    keypad(stdscr, true);

    curs_set(0);

    if (has_colors()) {
      start_color();
      {
        init_color(GS_ColorGray, 600, 600, 600);
        init_color(GS_ColorRed, 976, 0, 0);
        init_color(GS_ColorOrange, 976, 644, 0);
        init_color(GS_ColorYellow, 976, 976, 0);
        init_color(GS_ColorPink, 976, 750, 792);
        init_color(GS_ColorGreen, 0, 976, 0);
        init_color(GS_ColorBlue, 117, 562, 976);
        init_color(GS_ColorPurple, 578, 0, 824);
      }

      init_pair(1, GS_ColorRed, GS_ColorRed);
      init_pair(2, GS_ColorPink, GS_ColorPink);
      init_pair(3, GS_ColorBlue, GS_ColorBlue);
      init_pair(4, GS_ColorOrange, GS_ColorOrange);
      init_pair(5, GS_ColorYellow, GS_ColorYellow);
      init_pair(6, GS_ColorGreen, GS_ColorGreen);
      init_pair(7, GS_ColorPurple, GS_ColorPurple);
      init_pair(8, GS_ColorGray, 0);

      init_pair(50, GS_ColorRed, 0);
      init_pair(51, GS_ColorOrange, 0);
      init_pair(52, GS_ColorYellow, 0);
      init_pair(53, GS_ColorPink, 0);
      init_pair(54, GS_ColorGreen, 0);
      init_pair(55, GS_ColorBlue, 0);
      init_pair(56, GS_ColorPurple, 0);
      init_pair(57, COLOR_WHITE, 0);
    }

    clear();
    refresh();
  }
}

void CLI_removeCli(GS_cli_t *cli) {
  delwin(cli->game_win);
  delwin(cli->stat_win);

  memset(cli, 0, sizeof(*cli));

  endwin();
}

BG_UserInput_t CLI_getUserInput(void) {
  BG_UserInput_t return_user_input = {};

  GS_cli_t *cli = NULL;
  CLI_sliInfoKeeper(&cli);

  if (cli) {
    switch (getch()) {  // wgetch?
      case 10:
        return_user_input.action = BG_Start;
        return_user_input.hold = true;
        break;
      case 27:  // ESCAPE
        return_user_input.action = BG_Terminate;
        return_user_input.hold = true;
        break;
      case ' ':  // SPACE
        return_user_input.action = BG_Action;
        return_user_input.hold = true;
        break;
      case KEY_UP:
        return_user_input.action = BG_Up;
        return_user_input.hold = true;
        break;
      case KEY_DOWN:
        return_user_input.action = BG_Down;
        return_user_input.hold = true;
        break;
      case KEY_LEFT:
        return_user_input.action = BG_Left;
        return_user_input.hold = true;
        break;
      case KEY_RIGHT:
        return_user_input.action = BG_Right;
        return_user_input.hold = true;
        break;
      case 'p':
      case 'P':
        return_user_input.action = BG_Pause;
        return_user_input.hold = true;
        break;
      default:
        return_user_input.hold = false;
        break;
    }
  }

  return return_user_input;
}

void CLI_printCurrentState(BG_GameInfo_t game_info) {
  GS_cli_t *cli = NULL;
  CLI_sliInfoKeeper(&cli);

  if (cli) {
    if (game_info.level == -1) {
      CLI_print_start_preview();

    } else if (game_info.level == -2) {
      CLI_print_end_preview();
    } else if (game_info.pause) {
      CLI_print_pause_preview();
    } else {
      werase(cli->game_win);
      werase(cli->stat_win);

      for (BG_POINT2D_TYPE i = 0; i < BG_BOARD_ROWS_COUNT; i++) {
        wmove(cli->game_win, cli->game_win_pos.y + i, CLI_WIN_BORDER_SIZE_X);
        for (BG_POINT2D_TYPE j = 0; j < BG_BOARD_COLUMNS_COUNT; j++) {
          if (game_info.field[i][j]) {
            CLI_printBoardSymbol(cli->game_win,
                                 CLI_Full | COLOR_PAIR(game_info.field[i][j]));
          } else {
            CLI_printBoardSymbol(cli->game_win, CLI_Empty | COLOR_PAIR(8));
          }
        }
      }

      CLI_statWinPrint(cli, &game_info);

      wborder(cli->game_win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');

      wrefresh(cli->game_win);
    }
  }
}

void CLI_statWinPrint(GS_cli_t *cli, BG_GameInfo_t *game_info) {
  if (cli && game_info) {
    // tetromino print
    for (BG_POINT2D_TYPE i = 0; i < BG_TETROMINO_SIZE; i++) {
      wmove(cli->stat_win, cli->stat_win_pos.y + i,
            (cli->stat_win_size.x / 2 - (BG_TETROMINO_SIZE / 2)) +
                CLI_WIN_BORDER_SIZE_X - 3);
      for (BG_POINT2D_TYPE j = 0; j < BG_TETROMINO_SIZE; j++) {
        if (game_info->next[i][j]) {
          CLI_printBoardSymbol(cli->stat_win,
                               CLI_Full | COLOR_PAIR(game_info->next[i][j]));
        } else {
          CLI_printBoardSymbol(cli->stat_win, ' ');
        }
      }
    }

    wmove(cli->stat_win, cli->stat_win_pos.y + 4, 0);
    CLI_print_full_line(cli->stat_win, cli->stat_win_size.x, ACS_HLINE);

    wprintw(cli->stat_win, "%*s\n%*d\n", (int)cli->stat_win_size.x / 2 + 4,
            "HighScore", (int)cli->stat_win_size.x / 2 + 1,
            game_info->high_score);
    CLI_print_full_line(cli->stat_win, cli->stat_win_size.x, '-');

    wprintw(cli->stat_win, "%*s\n%*d\n", (int)cli->stat_win_size.x / 2 + 2,
            "Score", (int)cli->stat_win_size.x / 2 + 1, game_info->score);
    CLI_print_full_line(cli->stat_win, cli->stat_win_size.x, '-');

    wprintw(cli->stat_win, "%*s\n%*d\n", (int)cli->stat_win_size.x / 2 + 2,
            "Level", (int)cli->stat_win_size.x / 2 + 1, game_info->level);
    CLI_print_full_line(cli->stat_win, cli->stat_win_size.x, '-');

    wprintw(cli->stat_win, "%*s\n%*d\n", (int)cli->stat_win_size.x / 2 + 2,
            "Speed", (int)cli->stat_win_size.x / 2 + 1, game_info->speed);
    CLI_print_full_line(cli->stat_win, cli->stat_win_size.x, ACS_HLINE);

    wborder(cli->stat_win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');

    printNickname(cli);

    wrefresh(cli->stat_win);
  }
}

void printNickname(GS_cli_t *cli) {
  wmove(cli->stat_win, getcury(cli->stat_win),
        getcurx(cli->stat_win) + (int)cli->stat_win_size.x / 2 - 4);

  waddch(cli->stat_win, 'L' | COLOR_PAIR(50));
  waddch(cli->stat_win, 'u' | COLOR_PAIR(51));
  waddch(cli->stat_win, 'd' | COLOR_PAIR(52));
  waddch(cli->stat_win, 'i' | COLOR_PAIR(53));
  waddch(cli->stat_win, 'v' | COLOR_PAIR(54));
  waddch(cli->stat_win, 'i' | COLOR_PAIR(55));
  waddch(cli->stat_win, 'n' | COLOR_PAIR(56));
  waddch(cli->stat_win, 'P' | COLOR_PAIR(57));
}
