/**
 * CS1010 Semester 1 AY21/22
 * Exercise 3: Parity
 *
 * Read in a number and count the number of odd
 * and even digits it has.
 *
 * @file: parity.c
 * @author: XXX (Group YYY)
 */
#include "cs1010.h"

void print_parity(long n) 
{
  long count_even = 0;
  long count_odd = 0;

  while (n != 0) {
    if (((n % 10) % 2) == 0) {
      count_even += 1;
    } else {
      count_odd += 1;
    }
    n = n / 10;
  }
  cs1010_print_string("odd: ");
  cs1010_println_long(count_odd);
  cs1010_print_string("even: ");
  cs1010_println_long(count_even);
}

int main()
{
  long n = cs1010_read_long();
  print_parity(n);
}
