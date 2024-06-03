#include "tetris.h"

GameInfo_t *create_game() {
  srand(time(NULL));
  GameInfo_t *game = (GameInfo_t *)malloc(sizeof(GameInfo_t));
  game->field = (int **)calloc(HEIGHT_WF, sizeof(int *));
  for (int i = 0; i < HEIGHT_WF; i++) {
    game->field[i] = (int *)calloc(WIDTH, sizeof(int));
  }
  game->next = (int **)calloc(BLOCK_SIZE, sizeof(int *));
  for (int i = 0; i < BLOCK_SIZE; i++) {
    game->next[i] = (int(*))calloc(BLOCK_SIZE, sizeof(int));
  }
  game->block_row = 0;
  game->block_col = 2;
  choose_figure(game);
  game->score = 0;
  load_record(game);
  game->speed = 1;
  game->status = Start;
  place_block(game);
  return game;
}
void load_record(GameInfo_t *game) {
  FILE *file = fopen("record.txt", "r");
  if (file != NULL) {
    int number;
    if (fscanf(file, "%d", &number) == 1) {
      game->high_score = number;
    }
    fclose(file);
  }
}

void write_record(GameInfo_t *game) {
  FILE *file = fopen("record.txt", "w");
  if (file != NULL) {
    fprintf(file, "%d", game->high_score);
  }
  fclose(file);
}

void free_gameinfo(GameInfo_t *game) {
  if (game) {
    if (game->field) {
      for (int row = 0; row < HEIGHT_WF; row++) {
        if (game->field[row]) {
          free(game->field[row]);
        }
      }
      free(game->field);
    }
    if (game->next) {
      for (int row = 0; row < BLOCK_SIZE; row++) {
        if (game->next[row]) {
          free(game->next[row]);
        }
      }
      free(game->next);
    }
    free(game);
  }
}

void choose_figure(GameInfo_t *game) {
  int figures[7][BLOCK_SIZE][BLOCK_SIZE] = {
      {{0, 0, 0, 0, 0},
       {0, 1, 0, 0, 0},
       {0, 1, 1, 1, 0},
       {0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0}},
      {{0, 0, 0, 0, 0},
       {0, 0, 0, 1, 0},
       {0, 1, 1, 1, 0},
       {0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0}},
      {{0, 0, 0, 0, 0},
       {0, 0, 1, 0, 0},
       {0, 1, 1, 1, 0},
       {0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0}},
      {{0, 0, 0, 0, 0},
       {0, 0, 1, 1, 0},
       {0, 0, 1, 1, 0},
       {0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0}},
      {{0, 0, 0, 0, 0},
       {0, 0, 1, 1, 0},
       {0, 1, 1, 0, 0},
       {0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0}},
      {{0, 0, 0, 0, 0},
       {0, 1, 1, 0, 0},
       {0, 0, 1, 1, 0},
       {0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0}},
      {{0, 0, 1, 0, 0},
       {0, 0, 1, 0, 0},
       {0, 0, 1, 0, 0},
       {0, 0, 1, 0, 0},
       {0, 0, 0, 0, 0}},
  };
  int fl = 0;
  int prov[BLOCK_SIZE][BLOCK_SIZE] = {{0, 0, 0, 0, 0},
                                      {0, 0, 0, 0, 0},
                                      {0, 0, 0, 0, 0},
                                      {0, 0, 0, 0, 0},
                                      {0, 0, 0, 0, 0}};
  for (int i = 0; i < BLOCK_SIZE; i++) {
    for (int j = 0; j < BLOCK_SIZE; j++) {
      if (game->next[i][j] != prov[i][j]) {
        fl = 1;
        break;
      }
    }
  }
  int id1 = rand() % 7;
  int id2 = rand() % 7;
  if (fl == 0) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
      for (int j = 0; j < BLOCK_SIZE; j++) {
        game->block[i][j] = figures[id1][i][j];
      }
    }
  } else {
    for (int i = 0; i < BLOCK_SIZE; i++) {
      for (int j = 0; j < BLOCK_SIZE; j++) {
        game->block[i][j] = game->next[i][j];
      }
    }
  }
  for (int i = 0; i < BLOCK_SIZE; i++) {
    for (int j = 0; j < BLOCK_SIZE; j++) {
      game->next[i][j] = figures[id2][i][j];
    }
  }
}

void place_block(GameInfo_t *game) {
  for (int i = 0; i < BLOCK_SIZE; i++) {
    for (int j = 0; j < BLOCK_SIZE; j++) {
      if (game->block[i][j] == 1) {
        game->field[game->block_row + i][game->block_col + j] = 1;
      }
    }
  }
}

void clear_block(GameInfo_t *game) {
  for (int i = 0; i < BLOCK_SIZE; i++) {
    for (int j = 0; j < BLOCK_SIZE; j++) {
      if (game->block[i][j] == 1) {
        game->field[game->block_row + i][game->block_col + j] = 0;
      }
    }
  }
}

void move_down(GameInfo_t *game) {
  for (int i = 0; i < BLOCK_SIZE; i++) {
    for (int j = 0; j < BLOCK_SIZE; j++) {
      if (game->block[i][j] == 1) {
        int new_row = game->block_row + i + 1;
        int new_col = game->block_col + j;
        if (new_row > HEIGHT_WF - 1 || game->field[new_row][new_col] == 2) {
          game->status = Sig;
          return;
        }
      }
    }
  }
  clear_block(game);
  game->block_row++;
  place_block(game);
}

void move_left(GameInfo_t *game) {
  for (int i = 0; i < HEIGHT_WF; i++) {
    if (game->field[i][0] == 1) {
      return;
    }
  }
  for (int i = 0; i < BLOCK_SIZE; i++) {
    for (int j = 0; j < BLOCK_SIZE; j++) {
      if (game->block[i][j] == 1) {
        if (game->field[game->block_row + i][game->block_col + j - 1] == 2) {
          return;
        }
      }
    }
  }
  clear_block(game);
  game->block_col--;
  place_block(game);
}

void move_right(GameInfo_t *game) {
  for (int i = 0; i < HEIGHT_WF; i++) {
    if (game->field[i][WIDTH - 1] == 1) {
      return;
    }
  }
  for (int i = 0; i < BLOCK_SIZE; i++) {
    for (int j = 0; j < BLOCK_SIZE; j++) {
      if (game->block[i][j] == 1) {
        if (game->field[game->block_row + i][game->block_col + j + 1] == 2) {
          return;
        }
      }
    }
  }
  clear_block(game);
  game->block_col++;
  place_block(game);
}

void rotate_figure(GameInfo_t *game) {
  int temp[BLOCK_SIZE][BLOCK_SIZE];
  for (int i = 0; i < BLOCK_SIZE; i++) {
    for (int j = 0; j < BLOCK_SIZE; j++) {
      temp[i][j] = game->block[i][j];
    }
  }
  if (allow_rotation(game, temp) == 0 && check_square(game)) {
    clear_block(game);
    for (int i = 0; i < BLOCK_SIZE; i++) {
      for (int j = 0; j < BLOCK_SIZE; j++) {
        game->block[i][j] = temp[BLOCK_SIZE - j - 1][i];
      }
    }
    place_block(game);
  }
}

int check_square(GameInfo_t *game) {
  if (game->block[1][2] && game->block[2][2] && game->block[1][3] &&
      game->block[2][3])
    return 0;
  return 1;
}

void freeze_block(GameInfo_t *game) {
  for (int i = 0; i < HEIGHT_WF; i++) {
    for (int j = 0; j < WIDTH; j++) {
      if (game->field[i][j] == 1) {
        game->field[i][j] = 2;
      }
    }
  }
}

void find_fulls(GameInfo_t *game, int *num) {
  for (int i = HEIGHT_WF - 1; i >= 0; i--) {
    int count = 0;
    for (int j = 0; j < WIDTH; j++) {
      if (game->field[i][j] != 0) {
        count++;
      }
    }
    if (count == WIDTH) {
      (*num) += 1;
      clear_lines(game, i);
      find_fulls(game, num);
    }
  }
}

void update_score(GameInfo_t *game, int count) {
  int step = 100;
  if (count == 1) {
    game->score += step * count;
  } else if (count == 2) {
    game->score += step * 3;
  } else if (count == 3) {
    game->score += step * 7;
  } else if (count >= 4) {
    game->score += step * 15;
  }
  if (game->score > game->high_score) {
    game->high_score = game->score;
  }
}

void update_speed(GameInfo_t *game, int **speed) {
  int curr_speed = game->speed;
  int new_speed = game->score / 600 + 1;
  if (new_speed > 10) new_speed = 10;
  if (new_speed > curr_speed) {
    **speed = **speed - (new_speed - curr_speed) * 30;
    game->speed = new_speed;
  }
}

void clear_lines(GameInfo_t *game, int row_index) {
  for (int i = row_index; i > 0; i--) {
    for (int j = 0; j < WIDTH; j++) {
      game->field[i][j] = game->field[i - 1][j];
    }
  }
  for (int j = 0; j < WIDTH; j++) {
    game->field[0][j] = 0;
  }
}

void check_finish(GameInfo_t *game) {
  for (int i = 0; i <= 5; i++) {
    for (int j = 0; j < WIDTH; j++) {
      if (game->field[i][j] == 2) {
        game->status = GameOver;
      }
    }
  }
}

int allow_rotation(GameInfo_t *game, int temp[BLOCK_SIZE][BLOCK_SIZE]) {
  int dummy[BLOCK_SIZE][BLOCK_SIZE];
  int flag = 0;
  for (int i = 0; i < BLOCK_SIZE; i++) {
    for (int j = 0; j < BLOCK_SIZE; j++) {
      dummy[i][j] = temp[BLOCK_SIZE - j - 1][i];
    }
  }
  int left_idx = update_blockcol_left(dummy);
  int right_idx = update_blockcol_right(dummy);
  if (game->block_col + right_idx > 7 || game->block_col - left_idx < -2)
    flag = 1;
  for (int i = 0; i < BLOCK_SIZE; i++) {
    for (int j = 0; j < BLOCK_SIZE; j++) {
      if (dummy[i][j] == 1) {
        if (game->field[game->block_row + i][game->block_col + j] == 2 ||
            game->block_row + j + 1 > HEIGHT_WF) {
          flag = 1;
        }
      }
    }
  }
  return flag;
}

int update_blockcol_left(int dummy[BLOCK_SIZE][BLOCK_SIZE]) {
  int pos = 2;
  int temp = 6;
  for (int i = 0; i < BLOCK_SIZE; i++) {
    for (int j = 0; j < BLOCK_SIZE; j++) {
      if (dummy[i][j] == 1 && j < pos && j < temp) {
        temp = j;
      }
    }
  }
  if (temp == 6) return 0;
  return pos - temp;
}

int update_blockcol_right(int dummy[BLOCK_SIZE][BLOCK_SIZE]) {
  int pos = 2;
  int temp = -1;
  for (int i = 0; i < BLOCK_SIZE; i++) {
    for (int j = 0; j < BLOCK_SIZE; j++) {
      if (dummy[i][j] == 1 && j > pos && j > temp) {
        temp = j;
      }
    }
  }
  if (temp == -1) return 0;
  return temp - pos;
}

GameInfo_t updateCurrentState(GameInfo_t *game, int *move_interval) {
  int count = 0;
  freeze_block(game);
  find_fulls(game, &count);
  if (count > 0) {
    update_score(game, count);
    update_speed(game, &move_interval);
  }
  check_finish(game);
  if (game->status != GameOver) {
    game->block_row = 0;
    game->block_col = 2;
    choose_figure(game);
    place_block(game);
    game->status = Down;
  }
  return *game;
}

void userInput(GameInfo_t *game, int hold) {
  switch (hold) {
    case KEY_UP:
      game->status = Rotation;
      rotate_figure(game);
      break;
    case KEY_DOWN:
      game->status = Down;
      move_down(game);
      break;
    case KEY_LEFT:
      game->status = Left;
      move_left(game);
      break;
    case KEY_RIGHT:
      game->status = Right;
      move_right(game);
      break;
    case 'q':
      game->status = Terminate;
      break;
    case ' ':
      if (game->status == Pause) {
        game->status = Sig;
      } else if (game->status != GameOver)
        game->status = Pause;
      break;
    default:
      if (game->status != GameOver && game->status != Start)
        game->status = Down;
      break;
  }
}