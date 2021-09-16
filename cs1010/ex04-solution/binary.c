/**
 * CS1010 Semester 1 AY20/21
 * Exercise 2: Binary
 *
 * Reads in a number containing only digits 0 and 1, interpret 
 * it as a binary number, and output the corresponding decimal
 * number.
 *
 * @file: binary.c
 * @author: XXX (Group YYY)
 */
#include "cs1010.h"

// iterative
long binary_to_decimal(long binary) {
  long power = 1;
  long value = 0;
  do {
    long digit = binary % 10;
    if (digit == 1) {
      value += power;
    }
    power *= 2;
    binary /= 10;
  } while (binary != 0);
  return value;
}

// recursive
long binary_to_decimal2(long binary) {
  if (binary < 10) {
    return binary;
  } 
  return (binary % 10) + 2*binary_to_decimal2(binary / 10);
}


int main()
{
  long binary = cs1010_read_long();
  cs1010_println_long(binary_to_decimal2(binary));
}

