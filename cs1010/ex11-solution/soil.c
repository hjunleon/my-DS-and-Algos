#include "cs1010.h"

void search(long *a[], long nrows, long ncols, long q) {
  long i = 0;
  long j = ncols - 1;
  while (i < nrows && j >= 0 && a[i][j] != q) {
    if (a[i][j] > q) {
      j -= 1;
    } else {
      i += 1;
    }
  }
  if (i == nrows || j == -1) {
    printf("not found\n");
    return;
  }
  if (a[i][j] == q) {
    printf("%ld %ld\n", i, j);
  } 
}
int main()
{
  size_t nrows = cs1010_read_size_t();
  size_t ncols = cs1010_read_size_t();
  long nqueries = cs1010_read_long();
  long **a = malloc(sizeof(long *)*nrows);
  for (size_t i = 0; i < nrows; i += 1) {
    a[i] = cs1010_read_long_array(ncols);
  }
  for (long i = 0; i < nqueries; i += 1) {
    long q = cs1010_read_long();
    search(a, (long)nrows, (long)ncols, q);
  }
  for (size_t i = 0; i < nrows; i += 1) {
    free(a[i]);
  }
  free(a);
}
