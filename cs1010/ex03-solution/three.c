/**
 * CS1010 Semester 1 AY21/22
 * Exercise 2: Three
 *
 * Read in two numbers and prints all multiple of threes
 * between them (inclusive).
 *
 * @file: three.c
 * @author: XXX (Group YYY)
 */
#include "cs1010.h"

void print_threes(long from, long to)
{
  for (long i = from; i <= to; i += 1) {
    if (i % 3 == 0) {
      cs1010_println_long(i);
    }
  }
}

int main()
{
  long from = cs1010_read_long();
  long to = cs1010_read_long();
  print_threes(from, to);
}
