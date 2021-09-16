/**
 * CS1010 Semester 1 AY21/22
 * Exercise 3: HDB
 *
 * Read in the width and height of an HDB block in #s and
 * draw it.
 *
 * @file: hdb.c
 * @author: XXX (Group YYY)
 */
#include "cs1010.h"

void draw_hdb(long w, long h) 
{
  for (int i = 0; i < h; i += 1) {
    for (int j = 0; j < w; j += 1) {
      cs1010_print_string("#");
    }
    cs1010_println_string("");
  }
}

int main()
{
  long w = cs1010_read_long();
  long h = cs1010_read_long();

  draw_hdb(w, h);
}
