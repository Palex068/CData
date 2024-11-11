#include "fsm.h"

// This is a finite state machine realisation based on matrix of "actions".
/*
    Function sigact() takes an action function from fsm_table.
    Game state defines an index of line in matrix (where to get).
    User signal defines an index of column in matrix (what to get).

    Pros: 
        1) By instantly taking needed action, speed of processing is higher than switch-case realisation.
        2) Code is easy to read.
        3) Flexible (easy to add new state)
    Cons:
        1) More memory usage.
*/

typedef struct game_params
{
    game_stats_t *stats;
    frog_state *state;
    board_t *map;
    player_pos *frog_pos;
    bool *break_flag;
} params_t;

typedef void (*action)(params_t *prms);

void spawn(params_t *prms);
void moveup(params_t *prms);
void movedown(params_t *prms);
void moveright(params_t *prms);
void moveleft(params_t *prms);
void shifting(params_t *prms);
void reach(params_t *prms);
void collide(params_t *prms);
void gameover(params_t *prms);
void exitstate(params_t *prms);
void check(params_t *prms);

action fsm_table[8][7] = {
    {NULL, NULL, NULL, NULL, exitstate, spawn, NULL},
    {spawn, spawn, spawn, spawn, spawn, spawn, spawn},
    {moveup, movedown, moveright, moveleft, exitstate, check, check},
    {shifting, shifting, shifting, shifting, shifting, shifting, shifting},
    {reach, reach, reach, reach, reach, reach, reach},
    {collide, collide, collide, collide, collide, collide, collide},
    {gameover, gameover, gameover, gameover, gameover, gameover, gameover},
    {exitstate, exitstate, exitstate, exitstate, exitstate, exitstate, exitstate}
};

void sigact(signals sig, frog_state *state, game_stats_t *stats, board_t *map, player_pos *frog_pos)
{
    action act = NULL;
    params_t prms;
    prms.stats = stats;
    prms.state = state;
    prms.map = map;
    prms.frog_pos = frog_pos;

    if (*state != FILE_ERROR_STATE)
        act = fsm_table[*state][sig];

    if (act)
        act(&prms);
}

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

void shifting(params_t *prms)
{
    shift_map(prms->map);

    if (check_collide(prms->frog_pos, prms->map))
        *prms->state = COLLIDE;
    else
    {
        *prms->state = MOVING;
        print_board(prms->map, prms->frog_pos);
        print_stats(prms->stats);
    }
}

void check(params_t *prms)
{
    if (check_collide(prms->frog_pos, prms->map))
        *prms->state = COLLIDE;
    else if (check_finish_state(prms->frog_pos, prms->map))
        *prms->state = REACH;
    else
        *prms->state = SHIFTING;
}

void spawn(params_t *prms)
{
    if (prms->stats->level > LEVEL_CNT)
        *prms->state = GAMEOVER;
    else
    {
        if (!lvlproc(prms->map, prms->stats))
        {
            fill_finish(prms->map->finish);
            print_finished(prms->map);
            frogpos_init(prms->frog_pos);
            *prms->state = MOVING;
        }
        else
            *prms->state = FILE_ERROR_STATE;
    }
}

void moveup(params_t *prms)
{
    if (prms->frog_pos->y != 1)
    {
        CLEAR_BACKPOS(prms->frog_pos->y, prms->frog_pos->x);
        prms->frog_pos->y -= 2;
    }

    check(prms);
}

void movedown(params_t *prms)
{
    if (prms->frog_pos->y != BOARD_N)
    {
        CLEAR_BACKPOS(prms->frog_pos->y, prms->frog_pos->x);
        prms->frog_pos->y += 2;
    }

    check(prms);
}

void moveright(params_t *prms)
{
    if (prms->frog_pos->x != BOARD_M)
    {
        CLEAR_BACKPOS(prms->frog_pos->y, prms->frog_pos->x);
        prms->frog_pos->x++;
    }

    check(prms);
}

void moveleft(params_t *prms)
{
    if (prms->frog_pos->x != 1)
    {
        CLEAR_BACKPOS(prms->frog_pos->y, prms->frog_pos->x);
        prms->frog_pos->x--;
    }

    check(prms);
}

void reach(params_t *prms)
{
    prms->stats->score += 1;
    add_proggress(prms->map);
    if (check_level_compl(prms->map))
    {
        prms->stats->level++;
        prms->stats->speed++;
        *prms->state = SPAWN;
    }
    else
    {
        frogpos_init(prms->frog_pos);
        print_finished(prms->map);
        *prms->state = MOVING;
    }
}

void collide(params_t *prms)
{
    if (prms->stats->lives)
    {
        prms->stats->lives--;
        frogpos_init(prms->frog_pos);
        *prms->state = MOVING;
    }
    else
        *prms->state = GAMEOVER;
}

void gameover(params_t *prms)
{
    print_banner(prms->stats);
}

void exitstate(params_t *prms)
{
    *prms->state = EXIT_STATE;
}