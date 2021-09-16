/**
 * CS1010 Semester 1 AY20/21
 * Practical Exam 1: Error
 *
 * @file: error.c
 * @author: XXX (Group YYY)
 */
#include "cs1010.h"

double error_if_ignore_last_k_digit(long n, long k)
{
  long power = 1;
  for (int i = 0; i < k; i += 1) {
    power *= 10;
  }
  return (n % power) * 100.0/n;
}

int main()
{
  long k = cs1010_read_long();
  long n = cs1010_read_long();
  double error = error_if_ignore_last_k_digit(n, k);
  cs1010_println_double(error);
}

