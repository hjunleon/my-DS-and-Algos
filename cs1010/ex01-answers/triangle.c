/**
 * CS1010 Semester 1 AY21/22
 * Exercise 1: Triangle
 *
 * Read in three integers as the side of a triangle, and print
 * the area (unless it is impossible to form a triangle).
 *
 * @file: triangle.c
 * @author: XXX (Group YYY)
 */

#include <math.h>
#include <stdbool.h>
#include "cs1010.h"

bool is_possible_triangle(long a, long b, long c) 
{
  return (a + b > c) && (b + c > a) && (a + c > b);
}

double area_of_triangle(long a, long b, long c) 
{
  double s = 0.5 * (a + b + c);
  return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main()
{
  long a = cs1010_read_long();
  long b = cs1010_read_long();
  long c = cs1010_read_long();

  if (is_possible_triangle(a, b, c)) {
    cs1010_println_string("Possible");
    cs1010_println_double(area_of_triangle(a, b, c));
  } else {
    cs1010_println_string("Impossible");
  }
}
