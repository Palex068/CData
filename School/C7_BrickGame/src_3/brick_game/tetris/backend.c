#include "backend.h"

GameInfo_t* getInstance_GameInfo_t() {
  static GameInfo_t game_info = {0};
  return &game_info;
}

UserAction_t* getInstance_UserAction_t() {
  static UserAction_t user_action_t = Start;
  return &user_action_t;
}

matrix* getInstance_cur_fig() {
  static matrix cur_fig = {0};
  return &cur_fig;
}

int* getInstance_hold() {
  static int hold = 1;
  return &hold;
}

int* getInstance_ch() {
  static int ch;
  return &ch;
}

int* getInstance_x() {
  static int x = 3;
  return &x;
}

int* getInstance_y() {
  static int y = -1;
  return &y;
}

void init_gameinfo_t() {
  GameInfo_t* gameInfo_t = getInstance_GameInfo_t();
  create_field_next(gameInfo_t);
  gameInfo_t->high_score = 0;
  const char* filename = "brick_game/tetris/high_score.txt";
  FILE* fp = fopen(filename, "r");
  if (fp) {
    char buffer[256] = {'\0'};
    fgets(buffer, 256, fp);
    sscanf(buffer, "%d", &gameInfo_t->high_score);
  }
  fclose(fp);
  gameInfo_t->level = 1;
  gameInfo_t->score = 0;
  gameInfo_t->speed = 1;
  gameInfo_t->pause = 0;
}

void create_field_next(GameInfo_t* gameInfo_t) {
  gameInfo_t->field = calloc(FIELD_H, sizeof(int*));
  for (int i = 0; i < FIELD_H; i++) {
    gameInfo_t->field[i] = calloc(FIELD_W, sizeof(int**));
  }
  gameInfo_t->next = calloc(FIGURE_SIZE, sizeof(int*));
  for (int i = 0; i < FIGURE_SIZE; i++) {
    gameInfo_t->next[i] = calloc(FIGURE_SIZE, sizeof(int**));
  }
}

void delete_field_next(GameInfo_t* gameInfo_t) {
  for (int i = 0; i < FIELD_H; i++) {
    free(gameInfo_t->field[i]);
  }
  free(gameInfo_t->field);

  for (int i = 0; i < FIGURE_SIZE; i++) {
    free(gameInfo_t->next[i]);
  }
  free(gameInfo_t->next);
}

int testline(const int line[FIELD_W]) {
  for (int i = 0; i < FIELD_W; i++)
    if (!line[i]) return 0;
  return 1;
}

void delline(int** field, int line) {
  for (int i = 0; i < FIELD_W; i++)
    for (int j = line; j > 0; j--) field[j][i] = field[j - 1][i];
}

void fill_test(int** field, int* score) {
  int count = 0;
  for (int i = 0; i < FIELD_H; i++) {
    if (testline(field[i])) {
      delline(field, i);
      count++;
    }
  }
  switch (count) {
    case 1:
      *score += 100;
      break;
    case 2:
      *score += 300;
      break;
    case 3:
      *score += 700;
      break;
    case 4:
      *score += 1500;
      break;
    default:
      break;
  }
}

void save_high_score(int high_score) {
  char buffer[256] = {'\0'};
  sprintf(buffer, "%d", high_score);
  const char* filename = "brick_game/tetris/high_score.txt";
  FILE* fp = fopen(filename, "w");
  if (fp) fputs(buffer, fp);
  fclose(fp);
}

void rotate_fig(int** field, int** F, int* x, int* y, int dir) {
  int** tempf;
  tempf = calloc(FIGURE_SIZE, sizeof(int*));
  for (int i = 0; i < FIGURE_SIZE; i++) {
    tempf[i] = calloc(FIGURE_SIZE, sizeof(int**));
  }
  for (int i = 0; i < FIGURE_SIZE; i++) {
    for (int j = 0; j < FIGURE_SIZE; j++) {
      tempf[i][j] = F[i][j];
    }
  }
  delfig(field, F, *y, *x);
  rotateaux(tempf, dir);
  if (freeplace(field, tempf, *y, *x)) {
    rotateaux(F, dir);
    putfig(field, F, *y, *x);
  }
  putfig(field, F, *y, *x);

  for (int i = 0; i < FIGURE_SIZE; i++) {
    free(tempf[i]);
  }
  free(tempf);
}

void rotateaux(int** F, int dir) {
  int tempf[FIGURE_SIZE][FIGURE_SIZE];
  for (int i = 0; i < FIGURE_SIZE; i++)
    for (int j = 0; j < FIGURE_SIZE; j++) tempf[i][j] = F[i][j];

  for (int i = 0; i < FIGURE_SIZE; i++)
    for (int j = 0; j < FIGURE_SIZE; j++)
      F[i][j] =
          (dir ? tempf[FIGURE_SIZE - j - 1][i] : tempf[j][FIGURE_SIZE - i - 1]);
}

int freeplace(int** field, int** F, int y, int x) {
  for (int i = 0; i < FIGURE_SIZE; i++)
    for (int j = 0; j < FIGURE_SIZE; j++) {
      if (y + i < FIELD_H) {
        if ((F[i][j]) && (field[y + i][x + j])) return 0;
      }
      if ((F[i][j]) &&
          ((y + i >= FIELD_H) || (x + j >= FIELD_W) || (x + j < 0)))
        return 0;
    }
  return 1;
}

int move_fig(int** field, int** F, int* x, int* y, int dir) {
  int nx = *x, ny = *y;
  switch (dir) {
    case M_L:
      nx--;
      break;
    case M_R:
      nx++;
      break;
    case M_D:
      ny++;
      break;
    default:
      break;
  }
  delfig(field, F, *y, *x);
  if (freeplace(field, F, ny, nx)) {
    putfig(field, F, ny, nx);
    *x = nx;
    *y = ny;
    return 1;
  }
  putfig(field, F, *y, *x);
  return 0;
}

void putfig(int** field, int** F, int y, int x) {
  for (int i = 0; i < FIGURE_SIZE; i++)
    for (int j = 0; j < FIGURE_SIZE; j++)
      if (F[i][j]) field[y + i][x + j] = 7;
}

void delfig(int** field, int** F, int y, int x) {
  for (int i = 0; i < FIGURE_SIZE; i++)
    for (int j = 0; j < FIGURE_SIZE; j++)
      if (F[i][j]) field[y + i][x + j] = 0;
}

void init_matrix() {
  matrix* matr = getInstance_cur_fig();
  matr->cur_fig = calloc(FIGURE_SIZE, sizeof(int*));
  for (int i = 0; i < FIGURE_SIZE; i++) {
    matr->cur_fig[i] = calloc(FIGURE_SIZE, sizeof(int**));
  }
}

void uninit_matrix(matrix* matr) {
  for (int i = 0; i < FIGURE_SIZE; i++) {
    free(matr->cur_fig[i]);
  }
  free(matr->cur_fig);
}

void copy_data_1(int** to, int from[FIGURE_SIZE][FIGURE_SIZE]) {
  for (int i = 0; i < FIGURE_SIZE; i++) {
    for (int j = 0; j < FIGURE_SIZE; j++) {
      to[i][j] = 0;
      to[i][j] = from[i][j];
    }
  }
}

void copy_data_2(int** to, int** from) {
  for (int i = 0; i < FIGURE_SIZE; i++) {
    for (int j = 0; j < FIGURE_SIZE; j++) {
      to[i][j] = 0;
      to[i][j] = from[i][j];
    }
  }
}

void check_the_end() {
  UserAction_t* action = getInstance_UserAction_t();
  GameInfo_t* gameInfo_t = getInstance_GameInfo_t();
  int* y = getInstance_y();
  if (*y <= -1 || gameInfo_t->level > 10) *action = Terminate;
}

void set_high_score() {
  GameInfo_t* gameInfo_t = getInstance_GameInfo_t();
  if (gameInfo_t->score > gameInfo_t->high_score) {
    gameInfo_t->high_score = gameInfo_t->score;
    save_high_score(gameInfo_t->high_score);
  }
}

void set_speed(double* delay) {
  GameInfo_t* gameInfo_t = getInstance_GameInfo_t();
  if (gameInfo_t->score >= (600 / gameInfo_t->level)) {
    gameInfo_t->level = gameInfo_t->score / 600 + 1;
    gameInfo_t->speed = gameInfo_t->level;
    *delay = SPEED_FRACTION - (0.1 * gameInfo_t->speed);
  }
}

void go_to(UserAction_t* action, int* hold, int pause) {
  if (*action != Terminate && pause) {
    *action = Down;
    *hold = 0;
  }
}

void userInput(UserAction_t action, bool hold) {
  GameInfo_t* gameInfo_t = getInstance_GameInfo_t();
  matrix* matr = getInstance_cur_fig();
  int* x = getInstance_x();
  int* y = getInstance_y();
  int* ch = getInstance_ch();
  if (hold) {
    switch (action) {
      case Terminate:
        break;
      case Up:
        break;
      case Left:
        move_fig(gameInfo_t->field, matr->cur_fig, x, y, M_L);
        break;
      case Right:
        move_fig(gameInfo_t->field, matr->cur_fig, x, y, M_R);
        break;
      case Down:
        move_fig(gameInfo_t->field, matr->cur_fig, x, y, M_D);
        break;
      case Action:
        if (*y >= 0) rotate_fig(gameInfo_t->field, matr->cur_fig, x, y, R_R);
        break;
      case Start:
        break;
      case Pause:
        break;
      default:
        break;
    }
  }
  if (action == Start) {
    if (*ch == '\n') {
      gameInfo_t->pause = 1;
    }
  }
  if (action == Pause) {
    if (*ch == 'p' || *ch == 'P') {
      gameInfo_t->pause = 1;
    }
  }
}

GameInfo_t updateCurrentState() {
  GameInfo_t* gameInfo_t = getInstance_GameInfo_t();
  int* hold = getInstance_hold();
  UserAction_t* action = getInstance_UserAction_t();
  int* ch = getInstance_ch();
  if (!(*hold)) {
    switch (*ch) {
      case 'Q':
      case 'q':
        *action = Terminate;
        *hold = 1;
        break;
      case KEY_UP:
        *action = Up;
        *hold = 1;
        break;
      case KEY_LEFT:
        *action = Left;
        *hold = 1;
        break;
      case KEY_RIGHT:
        *action = Right;
        *hold = 1;
        break;
      case KEY_DOWN:
        *action = Down;
        *hold = 1;
        break;
      case ' ':
        *action = Action;
        *hold = 1;
        break;
      case 'P':
      case 'p':
        *action = Pause;
        gameInfo_t->pause = 0;
        *ch = 0;
        *hold = 1;
        break;
      default:
        break;
    }
  }
  return *gameInfo_t;
}
