#include "cs1010.h"

long **read_matrix(size_t nrows, size_t ncols) {
  long **matrix = malloc(nrows * sizeof(long *));
  if (matrix == NULL) {
    cs1010_println_string("unable to allocate memory");
    return NULL;
  }
  for (size_t i = 0; i < nrows; i += 1) {
    matrix[i] = cs1010_read_long_array(ncols);
    if (matrix[i] == NULL) {
      cs1010_println_string("unable to allocate memory");
      for (size_t j = 0; j < i; j += 1) {
        free(matrix[j]);
      }
      free(matrix);
      return NULL;
    }
  }
  return matrix;
}

void print_matrix(size_t nrows, size_t ncols, long **matrix) {
  for (size_t i = 0; i < nrows; i += 1) {
    for (size_t j = 0; j < ncols - 1; j += 1) {
      cs1010_print_long(matrix[i][j]);
      cs1010_print_string(" ");
    }
    cs1010_println_long(matrix[i][ncols - 1]);
  }
}

int main()
{
  long **matrix;
  size_t nrows = cs1010_read_size_t();
  size_t ncols = cs1010_read_size_t();

  matrix = read_matrix(nrows, ncols);
  print_matrix(nrows, ncols, matrix);

  for (size_t j = 0; j < nrows; j += 1) {
    free(matrix[j]);
  }
  free(matrix);
}
