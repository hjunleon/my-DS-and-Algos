/**
 * CS1010 Semester 1 AY21/22
 * Exercise 2: Multiple
 *
 * Read in two integers and determine if one is a multiple of the other.
 *
 * @file: multiple.c
 * @author: XXX (Group YYY)
 */
#include "cs1010.h"

int main() {
  long f = cs1010_read_long();
  long s = cs1010_read_long();
  if (s == 0 || f == 0 || f % s == 0 || s % f == 0) {
    cs1010_println_string("true");
  } else {
    cs1010_println_string("false");
  }
  return 0;
}
