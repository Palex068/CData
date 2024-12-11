#include "frontend.h"

/**
 * @brief Вход в программу
 * 
 */
int main(void) {
  /** 
  * @note Сочетание `srand(time(NULL))` устанавливает
  * в качестве базы генератора псевдослучайных чисел
  * текущее время,  используется для того, чтобы при
  * разных запусках генератора псевдослучайных чисел
  * была всякий раз разная база и, соответственно, 
  * разный ряд получаемых значений.
  * 
  */
  srand(time(NULL));
  updateCurrentState();
  updateCurrentFigure(true);
  updateNextFigure(true);
  initScore();
  initScreen();

  UserAction_t action = Start;
  WINDOW* field = createWindow(HEIGHT + 3, WIDTH * 2 + 4, 0, 15, true);
  WINDOW* next = createWindow(5, 5 * 2, 8, 2, false);

  while (true) {
    userInput(action, false);
    refreshScreen(field, next);
    action = isPress(getch());
    if (action == Terminate) break;
  }

  destroyWindow(field);
  destroyWindow(next);
  clearMatrix();
  return 0;
}

/**
 * @brief Выводим в консоль игровой такт
 * 
 * @param win Указатель на окно "стакана"
 * @param next Указатель на окно следующей фигуры
 */
void refreshScreen(WINDOW* win, WINDOW* next) {
  // Выводим информацию о состоянии игрового процесса
  drawInfo(updateCurrentState());
  // Выводим "стакан"
  drawField(win);
  // Выводим окно следующей фигуры
  drawNext(next);
}

/** @brief Инициализация библиотеки экрана средствами `<curses.h>`
 * 
 * @note `initscr()` инициализирует структуры данных пакета `curses`.
 * @note Процедура `cbreak()` устанавливает режим `CBREAK`
 * В режиме `CBREAK` вводимые символы сразу передаются программе.
 * @note curs_set(visibility); Курсор делается невидимым, нормальным или более
 * ярким, если значение visibility равно, соответственно, `0`, `1` или `2`
 * @note keypad(stdscr, true); Эта процедура устанавливает режим обработки
 * функциональных клавиш на клавиатуре терминала. Если этот режим установлен,
 * то при нажатии пользователем функциональной клавиши (например, стрелки
 * влево), процедура `wgetch` возвратит соответствующее этой клавише значение
 * (`KEY_LEFT`).
 * @note noecho(); Процедура управляет тем, отображаются ли на экране символы, вводимые по `getch()`
 * @note nodelay(stdscr, true); Don't wait until key pressing
 */
void initScreen() {
  // Инициализируем структуры данных пакета `curses`
  initscr();
  // В режиме `CBREAK` вводимые символы сразу передаются программе.
  cbreak();
  // Сделаем курсор невидимым
  curs_set(0);
  // Включим режим обработки функциональных клавиш
  keypad(stdscr, true);
  // Отключим отображение вводимых символов
  noecho();

  timeout(100);
  refresh();

  /* color initialization */
  use_default_colors();
  start_color();
  init_pair(1, COLOR_CYAN, -1);
  init_pair(2, COLOR_YELLOW, -1);
  init_pair(3, COLOR_WHITE, -1);
  init_pair(4, COLOR_BLUE, -1);
  init_pair(5, COLOR_MAGENTA, -1);
  init_pair(6, COLOR_GREEN, -1);
  init_pair(7, COLOR_RED, -1);

  init_pair(8, COLOR_BLACK, COLOR_RED);  // for blinking pause
  /**
   * @brief Процедура `endwin` восстанавливает начальные характеристики
   * драйвера управляющего терминала, помещает курсор в левый нижний 
   * угол экрана и переводит терминал в нормальный режим визуализации.
   */
  /**
   * @brief Функция `atexit` передает адрес вызываемой функции `func` 
   * при обычном завершении программы. Последовательные вызовы функции
   * `atexit` создают регистр функций, которые выполняются в порядке 
   * LIFO (последним поступил — первым обслужен). Переданные функции
   * `atexit` не могут принимать параметры. Для хранения регистра 
   * функций `atexit` и `_onexit` используют кучу. В связи с этим
   * количество функций, которое можно зарегистрировать, ограничивается
   * только памятью кучи.
   */
  atexit((void (*)(void))endwin);
}


/**
 * @brief Создание абсолютного пути до файла рекордов
 * 
 * @param buffer указатель на путь до файла рекордов
 * @return `char* buffer` указатель на путь до файла рекордов
 */
char* scorePath(char* buffer) {
  snprintf(buffer, BUFFER, "%s/db.txt", getenv("PWD"));
  return buffer;
}

/**
 * @brief Инициализация списка рекордов и запись рекорда при завершении программы.
 */
void initScore() {
  loadScore();
  atexit(saveScore);
}

/**
 * @brief Парсинг файла с рекордом
 */
void loadScore() {
  char buffer[BUFFER] = {0};
  char* path = scorePath(buffer);
  FILE* f;
  GameInfo_t* state = stateWrapper();
  if ((f = fopen(path, "r"))) {
    if (fscanf(f, "%d", &state->high_score) != 1) state->high_score = 0;
    fclose(f);
  } else {
    /* open fail for other reason than non existing file */
    if (errno != ENOENT)
      perror("Error: Can't open high score file in read mode!");
  }
}

/**
 * @brief Запись рекорда в файл
 */
void saveScore() {
  char buffer[BUFFER] = {0};
  char* path = scorePath(buffer);
  FILE* f;
  GameInfo_t state = updateCurrentState();
  if ((f = fopen(path, "w"))) {
    fprintf(f, "%d\n", state.high_score);
    fclose(f);
  } else {
    perror("Error: Can't open high score file in write mode!");
  }
}

/**
 * @brief Создание окна
 * 
 * @param H Высота окна
 * @param W Ширина окна
 * @param y Координата н
 * @param x Координата x
 * @param frame определяем необходимость рамки 
 * @return WINDOW* Возвращаем указатель на объект окна.
 */
WINDOW* createWindow(int H, int W, int y, int x, bool frame) {
  WINDOW* win = newwin(H, W, y, x);
  if (frame) box(win, 0, 0);
  return win;
}

/**
 * @brief Инициализация удаления окна средствами `<curses.h>`
 * Удаляет указанное окно, освободив всю память, связанную с ним;
 * Помещает пробелы во все позиции окна;
 * Выводит пустое окно на экран терминала.
 * @param win Передаем указатель на окно
 */
void destroyWindow(WINDOW* win) {
  /**
   * @brief `delwin(win)` Удаляет указанное окно, освободив всю память, связанную с ним.
   * В случае перекрытия окон сначала должны быть удалены окна, созданные
   * с помощью процедур `subwin` или `subpad`
   */
  delwin(win);

  /**
   * @brief Процедура `clear()` помещают пробелы во все позиции окна и дополнительно
   * вызывают процедуру `clearok`
   * `clear()` является макросом.
   */
  clear();

  /**
   * @brief Процедура refresh() (или процедуры `prefresh`, `pnoutrefresh`, `wnoutrefresh`
   * или `doupdate`) должны вызываться для реального вывода на экран, тогда как 
   * большинство остальных процедур только манипулируют структурами данных.
   * Процедура `wrefresh` копирует указанное окно на экран терминала, принимая во внимание
   * то, что на экран уже выведено, чтобы не выводить информацию повторно (это называется
   * оптимизацией вывода). Процедура `refresh` делает то же самое для стандартного окна 
   * `stdscr`. Если не установлен режим `leaveok`, физический курсор терминала помещается
   * на текущее место в окне. Процедура возвращает количество символов, выведенных на терминал.
   * `refresh` является макросом.
   */
  refresh();
}

/**
 * @brief Наполняем окно перед отображением в консоли
 * 
 * @param win передаем окно игрового "стакана"
 */
void drawField(WINDOW* win) {
  /**
   * @brief `box(win, vertch, horch);`
   * @note По краю окна `win` рисуется рамка. Аргументы `vertch` и `horch` - это символы,
   * с помощью которых рисуются вертикальные и горизонтальные линии. Если `vertch` и `horch`
   * равны `0`, то используются символы по умолчанию - `ACS_VLINE` и `ACS_HLINE` соответственно.
   */
  box(win, 0, 0);

  /**
   * @brief В дополнение к рамке из `<curses.h>` размещаем на экране символы из оригинального Тетриса
   * 
   */
  for (int y = 0; y <= HEIGHT; y++) {
    mvwaddch(win, y + 1, 1, '!');
    mvwaddch(win, y + 1, WIDTH * 2 + 2, '!');
  }

  for (int x = 0; x < WIDTH * 2; x++) {
    mvwaddch(win, HEIGHT + 1, x + 2, '=');
    if ((x + 1) % 2)
      mvwaddch(win, HEIGHT + 2, x + 2, '\\');
    else
      mvwaddch(win, HEIGHT + 2, x + 2, '/');
  }

  /**
   * @brief Перед заполнением экрана обновляем состояние игры
   */
  GameInfo_t state = updateCurrentState();
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      if (state.field[y][x]) {
        wattron(win, COLOR_PAIR(state.field[y][x]));
        mvwaddch(win, y + 1, x * 2 + 2, '[');
        mvwaddch(win, y + 1, x * 2 + 3, ']');
        wattroff(win, COLOR_PAIR(state.field[y][x]));
      } else {
        mvwaddch(win, y + 1, x * 2 + 2, ' ');
        mvwaddch(win, y + 1, x * 2 + 3, '.');
      }
    }
  }
  /**
   * @brief Отображаем полученное окно игры
   * 
   */
  wrefresh(win);
}

/**
 * @brief Переносим фигуру на окно игры
 * 
 * @param win указатель на окно
 */
void drawNext(WINDOW* win) {
  GameInfo_t state = updateCurrentState();
  for (int y = 0; y < MAX_BLOCKS - 1; y++) {
    for (int x = 0; x < MAX_BLOCKS; x++) {
      if (state.next[y][x]) {
        wattron(win, COLOR_PAIR(state.next[y][x]));
        mvwaddch(win, y + 1, x * 2 + 1, '[');
        mvwaddch(win, y + 1, x * 2 + 2, ']');
        wattroff(win, COLOR_PAIR(state.next[y][x]));
      } else {
        mvwaddch(win, y + 1, x * 2 + 1, ' ');
        mvwaddch(win, y + 1, x * 2 + 2, ' ');
      }
    }
  }
  wrefresh(win);
}

/**
 * @brief Отображаем показатели игрового процесса
 * 
 * @param info Передаем состояние игрового процесса
 */
void drawInfo(GameInfo_t info) {
  int y = 0;
  mvprintw(y + 1, 1, "Level:\t%d", info.level);
  mvprintw(y + 2, 1, "Score:\t%d", info.score);
  mvprintw(y + 3, 1, "High:\t%d", info.high_score);

  mvprintw(y + 7, 1, "Next:");

  mvprintw(y + 14, 1, "Left:\t left");
  mvprintw(y + 15, 1, "Right:\t right");
  mvprintw(y + 16, 1, "Down:\t down");
  mvprintw(y + 17, 1, "Drop:\t space");
  mvprintw(y + 18, 1, "Rotate: up");
  mvprintw(y + 20, 1, "Pause:\t p");
  mvprintw(y + 21, 1, "Quit: \t q");
}
