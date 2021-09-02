/**
 * CS1010 Semester 1 AY21/22
 * Exercise 2: GCD
 *
 * Read in two integers, print the total of the two integers, 
 * ignoring any negative integer.
 *
 * @file: gcd.c
 * @author: XXX (Group YYY)
 */
#include <stdbool.h>
#include "cs1010.h"

long gcd(long a, long b)
{
  if (b == a) {
    return a;
  } 
  if (a > b) {
    return gcd(a - b, b);
  }
  return gcd(b - a, a);
}

long euclidean(long a, long b)
{
  if (b == 0) {
      return a;
  } 
  return euclidean(b, a % b);
}

int main() 
{
  long a = cs1010_read_long();
  long b = cs1010_read_long();
  cs1010_println_long(gcd(a,b));
}
