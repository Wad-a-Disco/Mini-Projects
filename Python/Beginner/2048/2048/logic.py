# logic.py

import random

def start_game():
    # Initialize the 4x4 grid with two random 2's
    mat = [[0] * 4 for _ in range(4)]  # Declaring the variable mat as a 4x4 grid with all elements initialized to 0
    add_new_2(mat)
    add_new_2(mat)
    return mat

def add_new_2(mat):
    # Add a new 2 to a random empty cell in the grid
    r, c = random.choice([(i, j) for i in range(4) for j in range(4) if mat[i][j] == 0])  # Declaring variables r and c to store the row and column of the new 2
    mat[r][c] = 2

def compress(mat):
    # Compress the grid by shifting numbers to the left and merging identical ones
    new_mat = [[0] * 4 for _ in range(4)]  # Declaring the variable new_mat as a new 4x4 grid with all elements initialized to 0
    for i in range(4):  # FOR LOOP: Loop through each row of the matrix
        pos = 0
        for j in range(4):  # FOR LOOP: Loop through each element in the current row
            if mat[i][j] != 0:
                if new_mat[i][pos] == 0:
                    new_mat[i][pos] = mat[i][j]
                elif new_mat[i][pos] == mat[i][j]:
                    new_mat[i][pos] *= 2
                    pos += 1
                else:
                    pos += 1
                    new_mat[i][pos] = mat[i][j]
    return new_mat

def reverse(mat):
    # Reverse the grid
    new_mat = []  # Declaring the variable new_mat as an empty list
    for i in range(4):  # FOR LOOP: Loop through each row of the matrix
        new_mat.append([mat[i][3-j] for j in range(4)])  # FOR LOOP: Reversing the elements of the current row
    return new_mat

def transpose(mat):
    # Transpose the grid (rows become columns and vice versa)
    new_mat = [[mat[j][i] for j in range(4)] for i in range(4)]  # FOR LOOP: Transposing the rows and columns of the matrix
    return new_mat

def move_left(grid):
    # Move the grid to the left and merge cells
    new_grid = compress(grid)  # Declaring the variable new_grid as the compressed grid (moved left and merged cells)
    return new_grid, new_grid != grid

def move_right(grid):
    # Move the grid to the right and merge cells
    new_grid = reverse(grid)  # Declaring the variable new_grid as the reversed grid
    new_grid, changed = move_left(new_grid)  # Declaring the variable changed to store the result of move_left() function
    new_grid = reverse(new_grid)  # Reversing the grid back to its original form
    return new_grid, changed

def move_up(grid):
    # Move the grid up and merge cells
    new_grid = transpose(grid)  # Declaring the variable new_grid as the transposed grid (rows become columns)
    new_grid, changed = move_left(new_grid)  # Declaring the variable changed to store the result of move_left() function
    new_grid = transpose(new_grid)  # Transposing the grid back to its original form
    return new_grid, changed

def move_down(grid):
    # Move the grid down and merge cells
    new_grid = transpose(grid)  # Declaring the variable new_grid as the transposed grid (rows become columns)
    new_grid, changed = move_right(new_grid)  # Declaring the variable changed to store the result of move_right() function
    new_grid = transpose(new_grid)  # Transposing the grid back to its original form
    return new_grid, changed

def get_current_state(mat):
    # Check if the player has won, lost, or the game is still in progress
    for i in range(4):  # FOR LOOP: Loop through each row of the matrix
        for j in range(4):  # FOR LOOP: Loop through each element in the current row
            if mat[i][j] == 2048:
                return 'WON'  # If any cell contains 2048, the player has won

    for i in range(4):  # FOR LOOP: Loop through each row of the matrix
        for j in range(4):  # FOR LOOP: Loop through each element in the current row
            if mat[i][j] == 0:
                return 'GAME NOT OVER'  # If any cell is empty, the game is not over

    for i in range(3):  # FOR LOOP: Loop through each row of the matrix except the last one
        for j in range(3):  # FOR LOOP: Loop through each element in the current row except the last one
            if mat[i][j] == mat[i+1][j] or mat[i][j] == mat[i][j+1]:
                return 'GAME NOT OVER'  # If any adjacent cells have the same value, the game is not over

    for j in range(3):  # FOR LOOP: Loop through each column of the matrix except the last one
        if mat[3][j] == mat[3][j+1]:
            return 'GAME NOT OVER'  # If any cells in the last row have the same value, the game is not over

    for i in range(3):  # FOR LOOP: Loop through each row of the matrix except the last one
        if mat[i][3] == mat[i+1][3]:
            return 'GAME NOT OVER'  # If any cells in the last column have the same value, the game is not over

    return 'LOST'  # If none of the above conditions are met, the player has lost
