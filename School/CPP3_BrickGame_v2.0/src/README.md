# BrickGame

This program is BrickGame, where you can play Tetris and Snake.

## How to Run

1. First, execute:
   ```bash
   make all
   ```

2. Then, you can start the game using one of the following commands:

   - For Tetris in CLI:
     ```bash
     ./BrickGame tetris cli
     ```

   - For Tetris in Desktop:
     ```bash
     ./BrickGame tetris desktop
     ```

   - For Snake in CLI:
     ```bash
     ./BrickGame snake cli
     ```

   - For Snake in Desktop:
     ```bash
     ./BrickGame snake desktop
     ```

## Controls

- **Arrow keys**: Move
- **P**: Pause
- **S**: Start
- **ESC**: Terminate game
- **SPACE**: Rotate tetromino / Increase snake speed (if held)
- **Down arrow**: Increase speed of tetromino (if held)

## Finite State Machine (FSM) Description

### Snake Game States
- **Start** 
  - Transition to **Move**

- **Move**
  - Transition to **Pause**
  - Transition to **GameWon**
  - Transition to **GameLost**

- **Pause**
  - Transition to **Move**

- **GameLost**
  - Transition to **Start**

- **GameWon**
  - Transition to **Start**

### Tetris Game States
- **Start**
  - Transition to **Move**

- **Move**
  - Transition to **Pause**
  - Transition to **Attaching**
  - Transition to **GameLost**

- **Attaching**
  - Transition to **Move**

- **Pause**
  - Transition to **Move**

- **GameLost**
  - Transition to **Start**