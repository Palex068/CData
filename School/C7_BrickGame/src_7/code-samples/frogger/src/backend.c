#include "frog_backend.h"

int lvlproc(board_t *map, game_stats_t *stats)
{
    timeout(INITIAL_TIMEOUT - stats->speed * 15);

    char levelname[LEVELNAME_MAX + 1] = { 0 };

    sprintf(levelname, LEVEL_DIR"%d.txt", stats->level);
    
    FILE *level = fopen(levelname, "r");
    
    int rc = SUCCESS;

    if (level)
    {
        for (int i = 0; i < ROWS_MAP && !rc; i++)
        {
            if (fgets(map->ways[i], COLS_MAP + 2, level) == NULL)
                rc = ERROR;
            else
                map->ways[i][strcspn(map->ways[i], "\n")] = '\0';
        }
        fclose(level);
    }
    else
        rc = ERROR;

    return rc;
}

void add_proggress(board_t *map)
{
    int position = 0;

    for (; map->finish[position] == '0'; position++) ;

    for (int progress_cnt = BOARD_M / 5; progress_cnt > 0; progress_cnt--)
        map->finish[position++] = '0'; 
}

bool check_finish_state(player_pos *frog, board_t *map)
{
    bool rc = FALSE;

    if (frog->y == 1)
        rc = TRUE;

    return rc;
}

bool check_level_compl(board_t *map)
{
    bool rc = TRUE;
    for (int i = 0; i < BOARD_M && rc; i++)
        if (map->finish[i] != '0')
            rc = FALSE;

    return rc;
}

bool check_collide(player_pos *frog, board_t *map)
{
    bool rc = FALSE;

    if (frog->y > MAP_PADDING && frog->y < ROWS_MAP + MAP_PADDING + 1 && \
        map->ways[frog->y - MAP_PADDING - 1][frog->x - 1] == ']')
        rc = TRUE;

    return rc;
}

void frogpos_init(player_pos *frog)
{
    frog->x = FROGSTART_X;
    frog->y = FROGSTART_Y;
}

void fill_finish(char *finish_line)
{
    for (int i = 0; i < BOARD_M; i++)
        finish_line[i] = ' ';

    finish_line[BOARD_M] = '\0';
}

void stats_init(game_stats_t *stats)
{
    stats->level = 1;
    stats->score = 0;
    stats->speed = 1;
    stats->lives = 9;
    stats->won = FALSE;
}

void shift_map(board_t *map)
{
    for (int i = 1; i < ROWS_MAP; i += 2)
    {
        memmove(&map->ways[i][1], &map->ways[i][0], COLS_MAP * sizeof(char));
        map->ways[i][0] = map->ways[i][COLS_MAP];
    }
}
