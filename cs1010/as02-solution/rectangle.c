/**
 * CS1010 Semester 1 AY20/21
 * Exercise 3: Rectangle
 *
 * Reads in two integer numbers corresponding to the width and the 
 * height of a rectangle.   Draw the rectangle with character "*" 
 * to the standard output.
 *
 * @file: rectangle.c
 * @author: XXX (Group YYY)
 */
#include "cs1010.h"

#define TOP_LEFT "╔"
#define TOP_RIGHT "╗"
#define BOTTOM_RIGHT "╝"
#define BOTTOM_LEFT "╚"
#define HORIZONTAL "═"
#define VERTICAL "║"

void draw_top_line(long width)
{
  cs1010_print_string(TOP_LEFT);
  for (int j = 0; j < width - 2; j += 1) {
    cs1010_print_string(HORIZONTAL);
  }
  cs1010_println_string(TOP_RIGHT);
}

void draw_bottom_line(long width)
{
  cs1010_print_string(BOTTOM_LEFT);
  for (int j = 0; j < width - 2; j += 1) {
    cs1010_print_string(HORIZONTAL);
  }
  cs1010_println_string(BOTTOM_RIGHT);
}

void draw_rectangle(long width, long height)
{
  draw_top_line(width);
  for (int i = 0; i < height - 2; i += 1) {
    cs1010_print_string(VERTICAL);
    for (int j = 0; j < width - 2; j += 1) {
      cs1010_print_string(" ");
    }
    cs1010_println_string(VERTICAL);
  }
  draw_bottom_line(width);
}

int main()
{
  long width = cs1010_read_long();
  long height = cs1010_read_long();
  draw_rectangle(width, height);
}

