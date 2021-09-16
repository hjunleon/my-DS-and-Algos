/**
 * CS1010 Semester 1 AY21/22
 * Exercise 3: Factor
 *
 * Read in a number and count how many factors
 * does it have.
 *
 * @file: factor.c
 * @author: XXX (Group YYY)
 */
#include "cs1010.h"

long count_factors(long n) {
  long count = 0;
  for (long i = 2; i < n; i += 1) {
    if (n % i == 0) {
      count += 1;
    }
  }
  return count;
}

int main()
{
  long n = cs1010_read_long();
  long count = count_factors(n);
  cs1010_println_long(count);
}
