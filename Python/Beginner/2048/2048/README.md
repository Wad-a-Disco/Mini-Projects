# 2048 Game

2048 is a popular single-player sliding block puzzle game. The objective of the game is to slide numbered tiles on a grid to combine them and create a tile with the number 2048. The game ends when the player reaches the 2048 tile or when there are no possible moves left.

## How to Play

1. The game starts with an empty 4x4 grid containing two randomly placed tiles with the number 2. The player can use the following commands to move the tiles:
   - 'W' or 'w' : Move Up
   - 'S' or 's' : Move Down
   - 'A' or 'a' : Move Left
   - 'D' or 'd' : Move Right

2. When the player presses a command, the tiles move in that direction, and if any two identical numbers are adjacent, they merge to create a new tile with the sum of their values. After each move, a new tile with the number 2 is randomly placed in an empty cell.

3. The player's goal is to reach the 2048 tile by merging tiles. If the player successfully creates a tile with the number 2048, they win the game. However, if there are no empty cells left to place a new tile with the number 2, the game is over, and the player loses.

## Getting Started

1. Clone the repository to your local machine:

git clone https://github.com/your-username/2048-game.git

2. Change into the project directory:

cd 2048-game

3. Run the game:

python 2048.py

4. Use the 'W', 'A', 'S', or 'D' keys to move the tiles in the corresponding directions. Continue playing until you win or lose the game.

## Files and Project Structure

- `2048.py`: Contains the main driver code for the game. This is the file to run to start playing the game.
- `logic.py`: Contains all the logic and functions required for the game. The main game logic, such as moving tiles, merging cells, checking for a win or loss, etc., is implemented in this file.

## Requirements

- Python 3.x

## Screenshots

_Add some screenshots of the game in action (optional)_

## Contributing

Contributions are welcome! If you find any bugs or have suggestions for improvements, please open an issue or submit a pull request.

## License

This project is licensed under the [MIT License](LICENSE).

## Acknowledgments

- The game logic and rules are based on the original 2048 game created by Gabriele Cirulli. (https://github.com/gabrielecirulli/2048)
