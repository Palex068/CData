# Specification for the game library from the BrickGame game collection

This task is the first in the BrickGame series. There will be four projects, each with its own game and technology. But in addition to developing new projects, you will also need to support old games and add support for new games to old projects. This time the interface will be console, next time - desktop, and so on. In order to support old and new games, it is necessary to determine in advance how the API of interfaces and libraries will be organized, so that in the future you don't have to rewrite already completed projects.

The game field is a matrix of ten by twenty dimension. Each element of the matrix corresponds to a "pixel" of the game field and can be in one of two states: empty or filled. In addition to the game field, each game has additional information that is displayed in the sidebar to the right of the game field. Provide stubs for additional information that is not used during the game.

Each game library must have a function that accepts user input. The console has eight physical buttons: start game, pause, end game, action, and four arrows.

The `userInput` function takes as input the user `action` and an additional parameter `hold`, which is responsible for pressing the button.

The `updateCurrentState` function is intended to get data for rendering in the interface. It returns a structure containing information about the current state of the game. For example, for Tetris, the expiration of the timer causes the piece to move down one row. This function should be called from the interface at some intervals to keep the interface up to date.

```c
typedef enum {
    Start,
    Pause,
    Terminate,
    Left,
    Right,
    Up,
    Down,
    Action
} UserAction_t;

typedef struct {
    int **field;
    int **next;
    int score;
    int high_score;
    int level;
    int speed;
    int pause;
} GameInfo_t;

void userInput(UserAction_t action, bool hold);

GameInfo_t updateCurrentState();
```
