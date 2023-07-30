# Word Guessing Game

[![Python Version](https://img.shields.io/badge/python-3.6%20%7C%203.7%20%7C%203.8%20%7C%203.9-blue)](https://www.python.org/downloads/)

## Description

Word Guessing Game is a simple Python console-based game where the user attempts to guess a randomly chosen word. The game provides the user with a limited number of turns to guess the correct word, making it an entertaining and challenging experience.

## Installation

1. Ensure you have Python 3.6 or later installed on your system. If not, you can download it from [Python's official website](https://www.python.org/downloads/).

2. Clone this repository to your local machine or download the ZIP file and extract it.

3. Navigate to the project directory in your terminal or command prompt.

4. Run the game using the following command:

   ```bash
   python word_guessing_game.py

## How to Play
1. When you run the game, it will prompt you to enter your name. Type your name and press Enter.

2. The game will choose a random word from the list, and you will see underscores (_) representing the letters of the word to be guessed.

3. Guess one character at a time. If the character you guessed is present in the word, it will be revealed in its correct position.

4. Keep guessing characters until you complete the entire word or run out of turns.

5. You have a maximum of 12 turns to guess the word correctly.

6. If you correctly guess all the letters before running out of turns, you win the game.

7. If you run out of turns without guessing the word, you lose the game.

## Example Output
What is your name? John
Good Luck! John
Guess the characters
_ _ _ _ _ _ _
guess a character: e
_ _ _ _ e _ _
guess a character: s
_ _ _ _ e s _
guess a character: t
_ _ _ _ e s t
guess a character: r
Wrong
You have 11 more turns
...

## Contributing
Contributions are welcome! If you have any suggestions, bug fixes, or improvements, please feel free to submit a pull request. For major changes, please open an issue first to discuss the proposed changes.

## License
This project is licensed under the MIT License.