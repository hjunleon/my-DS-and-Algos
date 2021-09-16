/**
 * CS1010 Semester 1 AY21/22
 * Exercise 3: Nine
 *
 * Read in a number and print the position of the least 
 * significant 9 (if any).
 *
 * @file: nine.c
 * @author: XXX (Group YYY)
 */
#include <stdbool.h>
#include "cs1010.h"

long find_nine(long n) {
  long count = 1;
  while (n != 0) {
    if ((n % 10) == 9) {
      return count;
    }
    n /= 10;
    count += 1;
  }
  return 0;
}

int main()
{
  long n = cs1010_read_long();
  long pos = find_nine(n);
  cs1010_println_long(pos);
}
