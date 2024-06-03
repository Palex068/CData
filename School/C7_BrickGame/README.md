# BrickGame Tetris
Summary: In this project, you need to implement the Tetris game in the C programming language using a structural approach.

# Contents

- [BrickGameTetris](#brickgame-tetris)
  - [Contents](#contents)
  - [Introduction](#introduction)
- [Chapter I](#chapter-i)
  - [General Information](#general-information)
    - [BrickGame](#brickgame)
    - [History](#history)
    - [Finite-state machines](#fine-states-machines)
    - [Frogger](#frogger)
    - [Tetris](#tetris)
- [Chapter II](#chapter-ii)
  - [Project Requirments](#project-requirements)
    - [Part 1. Main task](#part-1-main-task)
    - [Part 2. Bonus. Scoring and game record](#part-2-bonus-scoring-and-game-record)
    - [Part 3. Bonus. Level mechanics](#part-3-bonus-level-mechanics)

## Introduction

The project must consist of two parts for implementing the Tetris game: a library that implements the game's logic, which can be connected to various GUIs in the future, and a terminal interface. The logic of the library must be implemented using finite-state machines, one of the possible descriptions of which will be given below.

## Chapter I <div id="chapter-i"></div>
# General information
### BrickGame

BrickGame is a popular handheld console from the 90s with several ~~thousands~~ of built-in games developed in China. Originally, it was a copy of Tetris, developed in the USSR and released by Nintendo as part of the GameBoy platform, but also included many other games that were added over time. The console had a small screen with a 10x20 size playing field, which was a matrix of "pixels". There was a scoreboard to the right of the field with a digital display of the current game status, records and other additional information. The most popular games on BrickGame were Tetris, Tanks, Racing, Frogger, and Snake.

![BrickGameConsole](misc/images/brickgame-console.jpg)

### History

Tetris was created on an Electronica-60 computer by Alexey Pajitnov on June 6, 1984. The game was a puzzle based on the use of "tetraminoes" - shaped pieces consisting of four squares. The first commercial version of the game was released in America in 1987. In the following years, Tetris was ported to many different devices, including cell phones, calculators, and PDAs.

The most popular version of Tetris is the one for the Game Boy and NES consoles. But there are various versions of the game apart from it. For example, there's a version with three-dimensional pieces or a dueling version where two players get the same pieces and try to beat each other on points.

### Finite-state machines

A finite-state machine (FSM) in the theory of algorithms is a mathematical abstraction, a model of a discrete device that has one entry, one exit and at each moment of time is in one state out of a set of possible states.

During operation, the input of the FSM sequentially receives entry actions, and at the output the FSM generates exit signals. Transition from one internal state to another can occur not only from external action, but also spontaneously.

FSM can be used to describe algorithms for solving certain problems, as well as for modeling almost any process. A few examples:

- Artificial intelligence logic for games;
- Syntactic and lexical analysis;
- Complex application network protocols;
- Streaming data  

Below are examples of using FSM to formalize the game logic of a few games from BrickGame.

### Frogger

![Frogger](misc/images/frogger-game.png)

Frogger is one of the later games released on the Brickgame consoles. The game is a playing field on which the logs move, and by jumping over them, the player needs to direct the frog from one side to the other. If the player hits the water or the frog moves outside the playing field, the frog dies. The game ends when the player brings the frog to the other side or the last frog dies.

In order to formalize the logic of this game, the following variant of a finite-state machine can be introduced:

![Frogger's finite-state machine](misc/images/frogger.jpg)

This FSM has the following states:

- Start is the state in which the game waits for the player to press the ready to play button.
- Spawn is the state in which the next frog is created.
- Moving is the main game state with user input processing - moving the frog along the lane left/right or jumping forward/backward.
- Shifting is the state that occurs after the timer expires, which shifts all objects on the lanes to the right, along with the frog.
- Collision is a state that occurs if the frog hits the water after jumping, or if the frog is outside the playing field after shifting logs.
- Reached the other side is the state that occurs when a frog reaches the  other side.
- Game over is the state that occurs after reaching the other side of the river or the last frog dies.

You can find an example of implementing a frogger using FSM in the `code-samples` folder.

### Tetris

![Tetris](misc/images/tetris-game.png)

Tetris is probably one of the most popular games for the Brickgame console. It's not rare for the console itself to be referred to as Tetris. The goal of the game is to score points for building lines from the blocks generated by the game. The next block generated by the game starts moving down the playing field until it reaches the lower boundary or collides with another block. The user can rotate the pieces and move them horizontally, trying to make rows. Once filled, the row is destroyed, the player gets points, and the blocks above the filled row go down. The game ends when the next piece stops in the topmost row.

In order to formalize the logic of this game, the following variant of a finite-state machine can be introduced:

![Tetris’s finite-state machine](misc/images/tetris.png)

This FSM has the following states:

- Start is the state in which the game waits for the player to press the ready to play button.
- Spawn is the state the game enters when you create another block and choose the next block to spawn.
- Moving is the main game state with user input processing - rotating blocks/moving blocks horizontally.
- Shifting is the state the game enters after the timer expires. It moves the current block down one level.
- Attaching is the state the game enters after the current block "touches" the already fallen blocks or the ground. If filled rows are created, it is destroyed and the rest of the blocks are shifted down. If a block is stopped in the topmost row, the game enters the "game over" state.
- Game over is a game over.

## Chapter II <div id="chapter-ii"></div>
## Project Requirements

### Part 1. Main task

You need to implement the BrickGame v1.0 aka Tetris program:

- The program must be developed in C language of C11 standard using gcc compiler.
- The program must consist of two parts: a library implementing the logic of the tetris game, and a terminal interface using the `ncurses` library.
- A finite-state machine must be used to formalize the logic of the game.
- The library must have a function that accepts user input and a function that outputs a matrix that describes the current state of the playing field whenever it is changed.
- The program library code must be located in the `src/brick_game/tetris` folder.
- The program interface code must be located in the `src/gui/cli` folder
- The program must be built using a Makefile with the standard set of targets for GNU-programs: all, install, uninstall, clean, dvi, dist, test, gcov_report. Installation directory can be arbitrary
- The program must be developed in accordance with the principles of structured programming.
- Stick to Google Style when writing code.
- Prepare full coverage of the library with unit tests, using the `check` library (tests must run on Darwin/Ubuntu OS). The coverage of the library with game logic with tests must be at least 80 percent.
- The following mechanics must be in the game:
  - Rotation of pieces;
  - Moving pieces horizontally;
  - Acceleration of the piece's fall (when the button is pressed, the figure moves all the way down);
  - Display of the next piece;
  - Destruction of filled raws;
  - End of the game when the top border of the playing field is reached;
  - All sorts of pieces shown in the picture below must be included in the game.
- Add support for all the buttons provided on the physical console for control:
  - Start game,
  - Pause,
  - End game,
  - Left arrow - movement of the piece to the left,
  - Right arrow - movement of the piece to the right,
  - Down arrow - piece falls,
  - Up arrow is not used in this game,
  - Action (piece rotation).
- The playing field must match the dimensions of the console's playing field - ten "pixels" wide and twenty "pixels" high.
- After reaching the lower boundary of the field or contacting another figure, the figure must stop. After that, the next piece, shown in the preview, is generated.
- The library interface must correspond to the description found in materials/library-specification.md.
- The UI must support rendering of the playing field and additional information.
- Prepare a diagram in any format describing the used FSM (its states and all possible transitions).

Pieces used:

![Pieces](misc/images/tetris-pieces.png)

### Part 2. Bonus. Scoring and game record

Add the following mechanics to the game:

- scoring;
- storing maximum points.

This information must be passed and displayed by the user interface in the sidebar. The maximum number of points must be stored in a file or embedded DBMS and saved between program runs.

The maximum number of points must be changed during the game if the user exceeds the current maximum score.

Points will be accrued as follows:

- 1 row is 100 points;
- 2 rows is 300 points;
- 3 rows is 700 points;
- 4 rows is 1500 points;

### Part 3. Bonus. Level mechanics

Add level mechanics to the game. Each time a player gains 600 points, the level increases by 1. Increasing the level boosts the speed at which the pieces move. The maximum number of levels is 10.

💡 [Press here](https://forms.yandex.ru/cloud/65d4a02673cee73bdc52da80/)**, to give us feedback on this project**. It's anonymous and will help our team make your learning process better.
