#include "fsm.h"

// This is a finite state machine realisation based on switch-case statement.
/* 
    Function sigact() describes state switching logic. 
    States are checked in order specified in function sigact().
    It enters a state-case which it corresponds to, where begins another switch-case statement.
    Inner switch-case statement is looking for a signal given by get_signal().
    After finding it makes some action and switches state to the next one.

    Pros: 
        1) Less memory usage.
    Cons: 
        1) A lot of codelines.
*/

signals get_signal(int user_input)
{
    signals rc = NOSIG;

    if (user_input == KEY_UP)
        rc = MOVE_UP;
    else if (user_input == KEY_DOWN)
        rc = MOVE_DOWN;
    else if (user_input == KEY_LEFT)
        rc = MOVE_LEFT;
    else if (user_input == KEY_RIGHT)
        rc = MOVE_RIGHT;
    else if (user_input == ESCAPE)
        rc = ESCAPE_BTN;
    else if (user_input == ENTER_KEY)
        rc = ENTER_BTN;

    return rc;
}

void moveup(player_pos *frog_pos)
{
    if (frog_pos->y != 1)
    {
        CLEAR_BACKPOS(frog_pos->y, frog_pos->x);
        frog_pos->y -= 2;
    }
}

void movedown(player_pos *frog_pos)
{
    if (frog_pos->y != BOARD_N)
    {
        CLEAR_BACKPOS(frog_pos->y, frog_pos->x);
        frog_pos->y += 2;
    }
}

void moveright(player_pos *frog_pos)
{
    if (frog_pos->x != BOARD_M)
    {
        CLEAR_BACKPOS(frog_pos->y, frog_pos->x);
        frog_pos->x++;
    }
}

void moveleft(player_pos *frog_pos)
{
    if (frog_pos->x != 1)
    {
        CLEAR_BACKPOS(frog_pos->y, frog_pos->x);
        frog_pos->x--;
    }
}

void on_start_state(signals sig, frog_state *state)
{
    switch (sig)
    {
        case ENTER_BTN:
            *state = SPAWN;
            break;
        case ESCAPE_BTN:
            *state = EXIT_STATE;
            break;
        default:
            *state = START;
            break;
    }
}

void on_spawn_state(frog_state *state, game_stats_t *stats, board_t *map, player_pos *frog_pos)
{
    if (stats->level > LEVEL_CNT)
        *state = GAMEOVER;
    else
        if (!lvlproc(map, stats))
        {
            fill_finish(map->finish);
            print_finished(map);
            frogpos_init(frog_pos);
            *state = MOVING;
        }
        else
            *state = FILE_ERROR_STATE;
}

void on_moving_state(signals sig, frog_state *state, board_t *map, player_pos *frog_pos)
{
    switch (sig)
    {
        case MOVE_UP:
            moveup(frog_pos);
            break;
        case MOVE_DOWN:
            movedown(frog_pos);
            break;
        case MOVE_RIGHT:
            moveright(frog_pos);
            break;
        case MOVE_LEFT:
            moveleft(frog_pos);
            break;
        case ESCAPE_BTN:
            *state = EXIT_STATE;
            break;
        default:
            break;
    }
    
    if (*state != EXIT_STATE)
    {
        if (check_collide(frog_pos, map))
            *state = COLLIDE;
        else if (check_finish_state(frog_pos, map))
            *state = REACH;
        else
            *state = SHIFTING;
    }
}

void on_shifting_state(frog_state *state, game_stats_t *stats, board_t *map, player_pos *frog_pos)
{
    shift_map(map);

    if (check_collide(frog_pos, map))
        *state = COLLIDE;
    else
    {
        *state = MOVING;
        print_board(map, frog_pos);
        print_stats(stats);
    }
}

void on_reach_state(frog_state *state, game_stats_t *stats, board_t *map, player_pos *frog_pos)
{
    stats->score += 1;
    add_proggress(map);

    if (check_level_compl(map))
    {
        stats->level++;
        stats->speed++;
        *state = SPAWN;
    }
    else
    {
        frogpos_init(frog_pos);
        print_finished(map);
        *state = MOVING;
    }
}

void on_collide_state(frog_state *state, game_stats_t *stats, player_pos *frog_pos)
{
    if (stats->lives)
    {
        stats->lives--;
        frogpos_init(frog_pos);
        *state = MOVING;
    }
    else
        *state = GAMEOVER;
}

void sigact(signals sig, frog_state *state, game_stats_t *stats, board_t *map, player_pos *frog_pos)
{
    switch (*state)
    {
        case START:
            on_start_state(sig, state);
            break;
        case SPAWN:
            on_spawn_state(state, stats, map, frog_pos);
            break;
        case MOVING:
            on_moving_state(sig, state, map, frog_pos);
            break;
        case SHIFTING:
            on_shifting_state(state, stats, map, frog_pos);
            break;
        case REACH:
            on_reach_state(state, stats, map, frog_pos);
            break;
        case COLLIDE:
            on_collide_state(state, stats, frog_pos);
            break;
        case GAMEOVER:
            print_banner(stats);
            break;
        default:
            break;
    }
}