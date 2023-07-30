# 2048.py

import logic

def print_grid(mat):
    print("+-------------------------+")
    for row in mat:
        print("|", end="")
        for val in row:
            if val == 0:
                print("      ", end="")  # Empty cell
            else:
                print(f"{val: ^5}", end="")  # Center-align the value in a cell
        print("|")
    print("+-------------------------+")

def main():
    mat = logic.start_game()  # Declaring the variable mat and initializing the 4x4 grid

    while True:  # WHILE LOOP: Main game loop, runs until the game is won or lost
        print("Commands are as follows:")
        print("'W' or 'w' : Move Up")
        print("'S' or 's' : Move Down")
        print("'A' or 'a' : Move Left")
        print("'D' or 'd' : Move Right")
        print_grid(mat)

        user_input = input("Press the command: ").strip().lower()  # Declaring the variable user_input to store the user's command

        if user_input in ['w', 'a', 's', 'd']:  # IF statement: Check if the user's input is valid
            if user_input == 'w':  # IF statement: Move Up
                mat, changed = logic.move_up(mat)  # Declaring the variables mat and changed to store the result of move_up() function
            elif user_input == 'a':  # IF statement: Move Left
                mat, changed = logic.move_left(mat)  # Declaring the variables mat and changed to store the result of move_left() function
            elif user_input == 's':  # IF statement: Move Down
                mat, changed = logic.move_down(mat)  # Declaring the variables mat and changed to store the result of move_down() function
            elif user_input == 'd':  # IF statement: Move Right
                mat, changed = logic.move_right(mat)  # Declaring the variables mat and changed to store the result of move_right() function

            if changed:  # IF statement: Check if any cells were merged or moved
                logic.add_new_2(mat)  # Adding a new 2 to the grid if any cell was merged
                state = logic.get_current_state(mat)  # Checking the current state of the game (win/lose/ongoing)
                if state == 'WON':  # IF statement: Check if the player has won
                    print_grid(mat)
                    print("Congratulations! You won!")
                    break
                elif state == 'LOST':  # IF statement: Check if the player has lost
                    print_grid(mat)
                    print("Game Over. You lost!")
                    break
        else:
            print("Invalid input. Please enter 'W', 'A', 'S', or 'D'.")

if __name__ == "__main__":
    main()

