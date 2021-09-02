/**
 * CS1010 Semester 1 AY21/22
 * Exercise 1: Odd
 *
 * Read in an integer and print the next larger odd number.
 *
 * @file: odd.c
 * @author: XXX (Group YYY)
 */

#include "cs1010.h"
#include <stdlib.h>

long next_odd(long n) {
  // without branching
	// return n + 1 + labs(n % 2);
  if (n % 2 == 0) {
    return n + 1;
  } 
  return n + 2;
}

int main()
{
  long n = cs1010_read_long();
  cs1010_println_long(next_odd(n));
}
