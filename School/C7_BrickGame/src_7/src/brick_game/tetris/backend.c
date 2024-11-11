#include "backend.h"

/** @brief Предназначена для получения данных для отрисовки в интерфейсе.
 * Например, для тетриса истечение таймера приводит к смещению фигуры вниз на
 * один ряд. Эта функция должна вызываться из интерфейса с некоторой
 * периодичностью для поддержания интерфейса в актуальном состоянии.
 * @return Возвращает структуру, содержащую информацию о текущем состоянии игры.
 */
GameInfo_t updateCurrentState() {
  GameInfo_t *state = stateWrapper();
  return *state;
}

/** @brief Инициирует начальные значения и выделяет память.
 *  @note Информация о текущем состоянии игры `GameInfo_t`
 *  может быть представлена внутри библиотеки игры статическим объектом.
 */
GameInfo_t *stateWrapper() {
  static GameInfo_t state[] = {0};
  if (state->field == NULL) {
    state->field = mallocMatrix(WIDTH, HEIGHT);
    state->next = mallocMatrix(MAX_BLOCKS, MAX_BLOCKS);
    state->score = 0;
    state->high_score = 600;
    state->level = 1;
    state->speed = 1000;
    state->pause = 0;
  }
  return state;
}

/** @brief Возвращает показатели текущей фигуры (также генерирует
 * новую фигуру и добавляет её координаты на поле матрицы) */
Figures *updateCurrentFigure(bool flag) {
  static Figures figure[] = {0};
  if (flag) {
    *figure = getRandomFigure();
    addFigure();
  }
  return figure;
}

/** @brief Возвращает показатели следующей фигуры (также генерирует
 * новую фигуру и добавляет её координаты на поле матрицы) */
Figures *updateNextFigure(bool flag) {
  static Figures next[] = {0};
  if (flag) {
    *next = getRandomFigure();
    addNext();
  }
  return next;
}

/** @brief Принимает на вход пользовательское действие `action` и
 * дополнительный параметр `hold`, который отвечает за зажатие клавиши.
 */
void userInput(UserAction_t action, bool hold) {
  if (hold) return;

  GameInfo_t *state = stateWrapper();
  state->speed -= 100;
  if (state->speed <= 0) moveDown(true);

  chtype ch = 0;
  switch (action) {
    case Start:
      mvprintw(5, 5, "Press ENTER to start!");
      mvprintw(6, 10, "q to quit!");
      while (ch != '\n' && ch != 'q') ch = getch();
      if (ch == 'q') exit(EXIT_SUCCESS);
      clear();
      refresh();
      break;
    case Pause:
      attron(A_BLINK);
      attron(COLOR_PAIR(8));
      mvprintw(5, 1, "PAUSE");
      attroff(COLOR_PAIR(8));
      attroff(A_BLINK);
      while (ch != 'p' && ch != 'q') ch = getch();
      if (ch == 'q') exit(EXIT_SUCCESS);
      clear();
      refresh();
      break;
    case Terminate:
      return;
    case Left:
      moveLeft();
      break;
    case Up:
      rotate();
      break;
    case Right:
      moveRight();
      break;
    case Down:
      moveDown(false);
      break;
    case Action:
      while (!moveDown(false)) continue;
      break;
    default:
      break;
  }
}

/** @brief Парсер клавишь */
UserAction_t isPress(int key) {
  UserAction_t action = -1;
  switch (key) {
    case 'p':
      action = Pause;
      break;
    case 'q':
      action = Terminate;
      break;
    case KEY_LEFT:
      action = Left;
      break;
    case KEY_RIGHT:
      action = Right;
      break;
    case KEY_UP:
      action = Up;
      break;
    case KEY_DOWN:
      action = Down;
      break;
    case ' ':
      action = Action;
      break;
    default:
      break;
  }

  return action;
}

/** @brief Добавление текущей фигуры на поле матрицы */
void addFigure() {
  GameInfo_t state = updateCurrentState();

  Figures *figure = updateCurrentFigure(false);
  choosedFig shape = shapes();
  for (int x = 0; x < MAX_BLOCKS; x++) {
    for (int y = 0; y < MAX_BLOCKS; y++) {
      if (shape[figure->piece][figure->rotation][x][y]) {
        state.field[figure->y + y][figure->x + x] = figure->piece + 1;
      }
    }
  }
}

/** @brief Добавление следующей фигуры на поле матрицы */
void addNext() {
  GameInfo_t state = updateCurrentState();
  Figures *next = updateNextFigure(false);
  choosedFig shape = shapes();
  for (int x = 0; x < MAX_BLOCKS; x++) {
    for (int y = 0; y < MAX_BLOCKS; y++) {
      if (shape[next->piece][next->rotation][x][y]) {
        state.next[y][x] = next->piece + 1;
      }
    }
  }
}

/** @brief Удаление текущей фигуры с поля матрицы */
void delFigure() {
  GameInfo_t state = updateCurrentState();
  Figures *figure = updateCurrentFigure(false);
  choosedFig shape = shapes();
  for (int x = 0; x < MAX_BLOCKS; x++) {
    for (int y = 0; y < MAX_BLOCKS; y++) {
      if (shape[figure->piece][figure->rotation][x][y]) {
        state.field[figure->y + y][figure->x + x] = 0;
      }
    }
  }
}

/** @brief Удаление следующей фигуры с поле матрицы */
void delNext() {
  GameInfo_t state = updateCurrentState();
  Figures *next = updateNextFigure(false);
  choosedFig shape = shapes();
  for (int x = 0; x < MAX_BLOCKS; x++) {
    for (int y = 0; y < MAX_BLOCKS; y++) {
      if (shape[next->piece][next->rotation][x][y]) {
        state.next[y][x] = 0;
      }
    }
  }
}

int moveDown(bool timeout) {
  int message = OK;
  delFigure();
  Figures *figure = updateCurrentFigure(false);
  figure->y++;
  if (isCollision()) {
    message = IS_FALL;
    figure->y--;
    addFigure();
    lineElimination();
    takeNextFigure();
  } else {
    addFigure();
  }

  GameInfo_t *state = stateWrapper();
  if (timeout) state->speed = 1300 * pow(0.8, state->level);

  return message;
}

void moveLeft() {
  delFigure();
  Figures *figure = updateCurrentFigure(false);
  figure->x--;
  if (isCollision()) figure->x++;
  addFigure();
}

void moveRight() {
  delFigure();
  Figures *figure = updateCurrentFigure(false);
  figure->x++;
  if (isCollision()) figure->x--;
  addFigure();
}

void rotate() {
  delFigure();
  Figures *figure = updateCurrentFigure(false);
  int tmp_x = figure->x;
  figure->rotation = (figure->rotation + 1) % MAX_BLOCKS;

  if (isCollision() == R_BOUNCE)
    while (isCollision() == R_BOUNCE) figure->x--;  // bounce from right wall
  if (isCollision() == L_BOUNCE)
    while (isCollision() == L_BOUNCE) figure->x++;  // bounce from left wall
  if (isCollision() == COLLIDE) {
    figure->rotation = (figure->rotation - 1) % MAX_BLOCKS;
    figure->x = tmp_x;
  }
  addFigure();
}

/** @brief Проверяет на столкновение с поверхностью и другими фигурами */
int isCollision() {
  GameInfo_t state = updateCurrentState();
  Figures *figure = updateCurrentFigure(false);
  choosedFig shape = shapes();
  for (int x = 0; x < MAX_BLOCKS; x++) {
    for (int y = 0; y < MAX_BLOCKS; y++) {
      if (shape[figure->piece][figure->rotation][x][y]) {
        if (figure->y + y >= HEIGHT ||
            state.field[figure->y + y][figure->x + x])
          return COLLIDE;
        // TODO: отпрыжка от фигур по абсолютным координатам
        if (figure->x + x >= WIDTH) return R_BOUNCE;
        if (figure->x + x < 0) return L_BOUNCE;
      }
    }
  }
  return OK;
}

/** @brief Удаляет строки, подсчитывает очки */
void lineElimination() {
  GameInfo_t *state = stateWrapper();

  int lines = 0;
  for (int row = 0; row < HEIGHT; row++) {
    int col;
    for (col = 0; col < WIDTH && state->field[row][col]; col++)
      ;

    if (col < WIDTH) continue;

    for (int h = row; h > 2; h--) {
      for (int k = 0; k < WIDTH; k++) {
        state->field[h][k] = state->field[h - 1][k];
      }
    }
    lines++;
  }
  const int linesPrice[MAX_BLOCKS + 1] = {0, 100, 300, 700, 1500};
  state->score += linesPrice[lines];

  if (state->level < 10) state->level = 1 + state->score / 600;
  // if (state->score > state->high_score)
  //     state->high_score = state->score;
}

/** @brief Старт новой игры в случае заполнения поля */
void promptNewGame() {
  if (isCollision()) {
    clear();
    GameInfo_t *info = stateWrapper();

    int x = 10;
    mvprintw(3, x + 1, "GAME OVER!");
    mvprintw(4, x, "You score: %d\n", info->score);
    if (info->score >= info->high_score) mvprintw(5, x, "New record!");

    mvprintw(7, x - 3, "Start new game? (y/n)");

    if (info->high_score < info->score) info->high_score = info->score;

    info->score = 0;
    info->level = 1;
    chtype ch = 0;
    while ((ch = getch()) != 'y') {
      if (ch == 'n') exit(EXIT_SUCCESS);
    }

    for (int i = 0; i < WIDTH; i++)
      for (int j = 0; j < HEIGHT; j++) info->field[j][i] = 0;

    clear();
  }
}

/** @brief Записывает координаты текущей фигуры на поле матрицы,
 * перемещает следующую фигуру на поле матрицы в исходной положение и
 * генериует новую следующую фигуру.
 */
void takeNextFigure() {
  delNext();
  Figures *next = updateNextFigure(false);
  Figures *figure = updateCurrentFigure(false);
  *figure = *next;

  promptNewGame();

  addFigure();
  updateNextFigure(true);
}

/** @brief Выделение памяти под матрицу состояния поля с фигурами */
int **mallocMatrix(int W, int H) {
  int error = OK;
  int **matrix = calloc(H, sizeof(int *));
  if (matrix != NULL) {
    int *val_arr = calloc(H * W, sizeof(int));
    if (val_arr != NULL) {
      for (int i = 0; i < H; i++) {
        matrix[i] = val_arr + W * i;
      }
    } else {
      error++;
    }
  } else {
    error++;
  }

  if (error) {
    printf("ERROR: Can't allocate memory!\n");
    exit(EXIT_FAILURE);
  }

  return matrix;
}

void clearMatrix() {
  GameInfo_t state = updateCurrentState();
  if (state.field != NULL) {
    if (state.field[MATRIX_PTR] != NULL) free(state.field[MATRIX_PTR]);
    free(state.field);
  }
  if (state.next != NULL) {
    if (state.next[MATRIX_PTR] != NULL) free(state.next[MATRIX_PTR]);
    free(state.next);
  }
}