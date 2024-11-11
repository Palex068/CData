#include "frogger.h"

int main(void)
{
    WIN_INIT(50);
    setlocale(LC_ALL, "");
    print_overlay();
    game_loop();
    endwin();

    return SUCCESS;
}

void game_loop()
{
    board_t map;
    game_stats_t stats;
    player_pos frog;

    bool break_flag = TRUE;
    int signal = 0;
    frog_state state = START;

    stats_init(&stats);

    while (break_flag)
    {   
        if (state == GAMEOVER || state == EXIT_STATE || state == FILE_ERROR_STATE)
            break_flag = FALSE;

        sigact(get_signal(signal), &state, &stats, &map, &frog);

        if (state == MOVING || state == START)
            signal = GET_USER_INPUT;
    }

    if (state == FILE_ERROR_STATE)
    {
        print_levelerror();
        nodelay(stdscr, FALSE);
        getch();
    }
}