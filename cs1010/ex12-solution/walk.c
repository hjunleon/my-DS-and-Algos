#include "cs1010.h"
#include <string.h>

long ne(long **solve, size_t m, size_t n) {
  for (size_t i = 0; i <= m; i += 1) {
    solve[i][0] = 1;
  }
  for (size_t i = 0; i <= n; i += 1) {
    solve[0][i] = 1;
  }
  for (size_t i = 1; i <= m; i += 1) {
    for (size_t j = 1; j <= n; j += 1) {
      solve[i][j] = solve[i-1][j] + solve[i][j-1];
    }
  }
  return solve[m][n];
}

int main() {
  size_t m, n;
  m = cs1010_read_size_t();
  n = cs1010_read_size_t();
  long **solve = calloc(m+1, sizeof(long *));
  if (solve == NULL) {
    cs1010_println_string("cannot allocate memory");
    return 1;
  }
  for (size_t i = 0; i <= m; i += 1) {
    solve[i] = calloc(n+1, sizeof(long));
    if (solve[i] == NULL) {
      cs1010_println_string("cannot allocate memory");
      for (size_t j = 0; j < i; j += 1) {
        free(solve[j]);
      }
      free(solve);
      return 1;
    }
  }
  cs1010_println_long(ne(solve, m, n));
}
