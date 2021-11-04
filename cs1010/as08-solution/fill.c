#include "cs1010.h"
#include <stdbool.h>

bool has_color(long **canvas, long x, long y, long r, long g, long b) {
  return (canvas[x][3*y] == r && 
    canvas[x][3*y+1] == g && 
    canvas[x][3*y+2] == b);
}

void set_color(long **canvas, long x, long y, long r, long g, long b) {
  canvas[x][3*y] = r;
  canvas[x][3*y+1] = g;
  canvas[x][3*y+2] = b;
}

void get_color(long **canvas, long x, long y, long *r, long *g, long *b) {
  *r = canvas[x][3*y];
  *g = canvas[x][3*y+1];
  *b = canvas[x][3*y+2];
}

void print_color(long **canvas, long x, long y) {
  cs1010_print_long(canvas[x][3*y]);
  cs1010_print_string(" ");
  cs1010_print_long(canvas[x][3*y+1]);
  cs1010_print_string(" ");
  cs1010_println_long(canvas[x][3*y+2]);
}

#define X 0
#define Y 1

void fill(long **canvas, long m, long n, long x, long y, 
    long curr_r, long curr_g, long curr_b, 
    long r, long g, long b) {
  long delta[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  for (long dir = 0; dir < 4; dir += 1) {
    long new_x = x + delta[dir][X];
    long new_y = y + delta[dir][Y];
    if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n 
        && has_color(canvas, new_x, new_y, curr_r, curr_g, curr_b)) {
      set_color(canvas, new_x, new_y, r, g, b);
      fill(canvas, m, n, new_x, new_y, curr_r, curr_g, curr_b, r, g, b);
    }
  }
}

void print(long **canvas, long m, long n) {
  cs1010_print_string("P3 ");
  cs1010_print_long(n);
  cs1010_print_string(" ");
  cs1010_print_long(m);
  cs1010_print_string(" ");
  cs1010_println_long(255);
  for (long i = 0; i < m; i += 1) {
    for (long j = 0; j < n; j += 1) {
      print_color(canvas, i, j);
    }
  }
}

int main() {
  long m, n;
  m = cs1010_read_long();
  n = cs1010_read_long();
  long **canvas = calloc((size_t)m, sizeof(long *));
  for (long i = 0; i < m; i += 1) {
    canvas[i] = cs1010_read_long_array((size_t)n * 3);
  }
  long q = cs1010_read_long();
  while (q > 0) {
    long i = cs1010_read_long();
    long j = cs1010_read_long();
    long r = cs1010_read_long();
    long g = cs1010_read_long();
    long b = cs1010_read_long();
    long curr_r;
    long curr_g;
    long curr_b;
    get_color(canvas, i, j, &curr_r, &curr_g, &curr_b);
    set_color(canvas, i, j, r, g, b);
    fill(canvas, m, n, i, j, curr_r, curr_g, curr_b, r, g, b);
    q -= 1;
  }
  print(canvas, m, n);
  for (long i = 0; i < m; i += 1) {
    free(canvas[i]); 
  }
  free(canvas);
}
