#include "cs1010.h"
#include <stdbool.h>
#include <unistd.h>

#define EMPTY '.'

void print_row(char *row) {
    for (int i = 0; i < 9; i += 1) {
        putchar(row[i]);
        if (i == 2 || i == 5) {
            cs1010_print_string("│");
        }
    }
    putchar('\n');
}

void print_sudoku(char *puzzle[9]) {
    cs1010_clear_screen();
    for (int i = 0; i < 9; i += 1) {
        print_row(puzzle[i]);
        if (i == 2 || i == 5) {
            cs1010_println_string("───┼───┼───");
        }
    }
    if (isatty(fileno(stdout))) {
        usleep(10*1000);
    }
}

bool is_valid_block(char *puzzle[9], int offset_row, int offset_col) {
    bool has_digit[9] = {false};
    for (int i = offset_row; i <= offset_row + 2; i += 1) {
        for (int j = offset_col; j <= offset_col + 2; j += 1) {
            if (puzzle[i][j] != EMPTY) {
                int digit = puzzle[i][j] - '1';
                if (has_digit[digit]) {
                    return false;
                }
                has_digit[digit] = true;
            }
        }
    }
    return true;
}

bool is_valid_row(char *puzzle[9], int row) {
    bool has_digit[9] = {false};
    for (int i = 0; i < 9; i += 1) {
        if (puzzle[row][i] != EMPTY) {
            int digit = puzzle[row][i] - '1';
            if (has_digit[digit]) {
                return false;
            }
            has_digit[digit] = true;
        }
    }
    return true;
}

bool is_valid_col(char *puzzle[9], int col) {
    bool has_digit[9] = {false};
    for (int i = 0; i < 9; i += 1) {
        if (puzzle[i][col] != EMPTY) {
            int digit = puzzle[i][col] - '1';
            if (has_digit[digit]) {
                return false;
            }
            has_digit[digit] = true;
        }
    }
    return true;
}

bool is_valid(char *puzzle[9]) {
    // every 3x3 block has no duplicate
    for (int offset_row = 0; offset_row < 9; offset_row += 3) {
        for (int offset_col = 0; offset_col < 9; offset_col += 3) {
            if (!is_valid_block(puzzle, offset_row, offset_col)) {
                return false;
            }
        }
    }
    // every row has no duplicate
    for (int i = 0; i < 9; i += 1) {
        if (!is_valid_row(puzzle, i)) {
            return false;
        }
    }

    // every row has no duplicate
    for (int i = 0; i < 9; i += 1) {
        if (!is_valid_col(puzzle, i)) {
            return false;
        }
    }
    return true;
}

bool solve_sudoku(char *puzzle[9], int row, int col) {
    print_sudoku(puzzle);
    if (row > 8 || col > 8) {
        if (is_valid(puzzle)) {
            return true;
        }
    }
    if (puzzle[row][col] == EMPTY) {
        for (char test = '1'; test <= '9'; test += 1) {
            puzzle[row][col] = test;
            int next_col = (col + 1) % 9;
            int next_row = row;
            if (col == 8) {
                next_row = row + 1;
            }
            if (is_valid(puzzle) && solve_sudoku(puzzle, next_row, next_col)) {
                return true;
            }
        }
        puzzle[row][col] = EMPTY;
    } else {
        int next_col = (col + 1) % 9;
        int next_row = row;
        if (col == 8) {
            next_row = row + 1;
        }
        return solve_sudoku(puzzle, next_row, next_col);
    }
    return false;
}

int main()
{
    char *puzzle[9];
    for (int i = 0; i < 9; i += 1) {
        puzzle[i] = cs1010_read_word();
    }

    bool result = solve_sudoku(puzzle, 0, 0);

    if (!result) {
        cs1010_println_string("no solution");
    } else {
        print_sudoku(puzzle);
    }

    for (long i = 0; i < 9; i += 1) {
        free(puzzle[i]);
    }
}
