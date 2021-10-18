#include "cs1010.h"
#include <math.h>
#include <assert.h>

#define BLACK 0
#define WHITE 255

unsigned char** allocate_canvas(size_t nrows, size_t ncols) {
  unsigned char **canvas = malloc(nrows * sizeof(unsigned char *));
  if (canvas == NULL) {
    cs1010_println_string("unable to allocate memory");
    return NULL;
  }
  for (size_t i = 0; i < nrows; i += 1) {
    canvas[i] = malloc(ncols * sizeof(unsigned char));
    if (canvas[i] == NULL) {
      cs1010_println_string("unable to allocate memory");
      for (size_t j = 0; j < i; j += 1) {
        free(canvas[j]);
      }
      return NULL;
    }
  }
  return canvas;
}

void free_canvas(size_t nrows, unsigned char **canvas) {
  for (size_t j = 0; j < nrows; j += 1) {
    free(canvas[j]);
  }
  free(canvas);
}


void init_canvas(size_t nrows, size_t ncols, unsigned char **canvas) {
  for (size_t i = 0; i < nrows; i += 1) {
    for (size_t j = 0; j < ncols; j += 1) {
      canvas[i][j] = BLACK;
    }
  }
}

void draw_line(long x1, long y1, long x2, long y2, unsigned char **canvas) {
  canvas[y1][x1] = WHITE;
  double y = y1;
  double slope = 1.0 * (y2 - y1) / (x2 - x1);
  // printf("%lf\n", slope);
  for (long x = x1 + 1; x <= x2; x += 1) {
    y += slope; 
    double roundy = round(y);
    // printf("%p %zu %lf %lf\n", canvas, x, y, roundy);
    canvas[(long)roundy][x] = WHITE;
  }
}

void print_canvas(size_t nrows, size_t ncols, unsigned char **canvas) {
  cs1010_println_string("P2");
  cs1010_print_size_t(ncols);
  cs1010_print_string(" ");
  cs1010_println_size_t(nrows);
  cs1010_println_long(255);
  for (size_t i = 0; i < nrows; i += 1) {
    for (size_t j = 0; j < ncols - 1; j += 1) {
      cs1010_print_long(canvas[i][j]);
      cs1010_print_string(" ");
    }
    cs1010_println_long(canvas[i][ncols - 1]);
  }
}

int main()
{
  size_t ncols = cs1010_read_size_t();
  size_t nrows = cs1010_read_size_t();

  unsigned char **canvas;

  canvas = allocate_canvas(nrows, ncols);
  if (canvas == NULL) {
    cs1010_println_string("unable to allocate memory");
    return 1;
  }

  init_canvas(nrows, ncols, canvas);

  long x1 = cs1010_read_long();
  long y1 = cs1010_read_long();
  long x2 = cs1010_read_long();
  long y2 = cs1010_read_long();

  draw_line(x1, y1, x2, y2, canvas);
  print_canvas(nrows, ncols, canvas);

  free_canvas(nrows, canvas);
}
