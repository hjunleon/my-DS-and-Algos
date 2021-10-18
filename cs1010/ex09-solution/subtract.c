#include "cs1010.h"

#define NCOLS 3
#define NROWS 3

void subtract(long m[][NCOLS], long n[][NCOLS], long result[][NCOLS]) {
  for (long i = 0; i < NROWS; i += 1) {
    for (long j = 0; j < NCOLS; j += 1) {
      result[i][j] = m[i][j] - n[i][j];
    }
  }
}

int main()
{
  long m[NROWS][NCOLS];
  long n[NROWS][NCOLS];
  long result[NROWS][NCOLS];

  for (long i = 0; i < NROWS; i += 1) {
    for (long j = 0; j < NCOLS; j += 1) {
      m[i][j] = cs1010_read_long();
    }
  }
  for (long i = 0; i < NROWS; i += 1) {
    for (long j = 0; j < NCOLS; j += 1) {
      n[i][j] = cs1010_read_long();
    }
  }
  subtract(m, n, result);

  for (long i = 0; i < NROWS; i += 1) {
    for (long j = 0; j < NCOLS - 1; j += 1) {
      cs1010_print_long(result[i][j]);
      cs1010_print_string(" ");
    }
    cs1010_println_long(result[i][NCOLS - 1]);
  }
}
