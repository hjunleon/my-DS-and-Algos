/**
 * CS1010 Semester 1 AY21/22
 * Exercise 1: Sum
 *
 * Read in two integers, print the total of the two integers, 
 * ignoring any negative integer.
 *
 * @file: sum.c
 * @author: XXX (Group YYY)
 */

#include "cs1010.h"

int main()
{
  long a = cs1010_read_long();
  long b = cs1010_read_long();

  if (a < 0 && b >= 0) {
    cs1010_println_long(b);
  } else if (b < 0 && a >= 0) {
    cs1010_println_long(a);
  } else if (b < 0 && a < 0) {
    cs1010_println_long(0);
  } else {
    cs1010_println_long(a + b);
  }
}
