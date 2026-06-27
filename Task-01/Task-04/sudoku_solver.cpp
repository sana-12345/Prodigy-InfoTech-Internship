#include <iostream>
using namespace std;

#define SIZE 9

// Check if a number can be placed safely
bool isSafe(int grid[SIZE][SIZE], int row, int col, int num) {
    for (int x = 0; x < SIZE; x++) {
        if (grid[row][x] == num || grid[x][col] == num)
            return false;
    }

    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num)
                return false;
        }
    }
    return true;
}

// Solve Sudoku using backtracking
bool solveSudoku(int grid[SIZE][SIZE]) {
    int row, col;
    bool isEmpty = false;

    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (grid[row][col] == 0) {
                isEmpty = true;
                goto FOUND;
            }
        }
    }

FOUND:
    if (!isEmpty)
        return true;

    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;

            if (solveSudoku(grid))
                return true;

            grid[row][col] = 0;
        }
    }
    return false;
}

// Print the Sudoku grid
void printGrid(int grid[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}

int main() {
    int grid[SIZE][SIZE] = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };

    cout << "Unsolved Sudoku:\n";
    printGrid(grid);

    if (solveSudoku(grid)) {
        cout << "\nSolved Sudoku:\n";
        printGrid(grid);
    } else {
        cout << "\nNo solution exists.";
    }

    cout << "\n\nPRODIGY INFOTECH" << endl;
    return 0;
}
