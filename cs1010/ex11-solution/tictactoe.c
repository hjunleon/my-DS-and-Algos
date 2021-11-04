#include <cs1010.h>
#include <stdbool.h>

bool has_won(char *ttt[3], char player) {
  // check row
  for (long row = 0; row < 3; row += 1) {
    if (ttt[row][0] == player && ttt[row][1] == player && ttt[row][2] == player) {
      return true;
    }
  }
  // check col
  for (long col = 0; col < 3; col += 1) {
    if (ttt[0][col] == player && ttt[1][col] == player && ttt[2][col] == player) {
      return true;
    }
  }
  // check diagonal
  if (ttt[0][0] == player && ttt[1][1] == player && ttt[2][2] == player) {
    return true;
  }
  if (ttt[0][2] == player && ttt[1][1] == player && ttt[2][0] == player) {
    return true;
  }
  return false;
}

int main()
{
  char *ttt[3];
  for (long i = 0; i < 3; i++) {
    ttt[i] = cs1010_read_word();
  }
  if (has_won(ttt, 'X')) {
    printf("X\n");
  } else if (has_won(ttt, 'O')) {
    printf("O\n");
  } else {
    printf("no winner\n");
  }
  for (long i = 0; i < 3; i++) {
    free(ttt[i]);
  }
}

