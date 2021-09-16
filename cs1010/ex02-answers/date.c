/**
 * CS1010 Semester 1 AY21/22
 * Exercise 2: Between
 *
 * Read in two integers, print the total of the two integers, 
 * ignoring any negative integer.
 *
 * @file: between.c
 * @author: XXX (Group YYY)
 */

#include <stdbool.h>
#include "cs1010.h"

bool before(long month1, long day1, long month2, long day2) 
{
  return (month1 < month2) || ((month1 == month2) && (day1 < day2));
}

bool between(long month1, long day1, long month2, long day2, long month3, long day3) 
{
  return before(month2, day2, month3, day3) && before(month1, day1, month2, day2); 
}

int main() 
{
  long month1 = cs1010_read_long();
  long day1 = cs1010_read_long();
  long month2 = cs1010_read_long();
  long day2 = cs1010_read_long();
  long month3 = cs1010_read_long();
  long day3 = cs1010_read_long();

  if (between(month1, day1, month2, day2, month3, day3)) {
    cs1010_println_string("yes");
  } else {
    cs1010_println_string("no");
  }
}
