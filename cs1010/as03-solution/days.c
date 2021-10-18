/**
 * Read in a month and a day and prints the number of days since the beginning of the year.
 * @file: days.c
 * @author: XXX (Group YYY)
 */
#include "cs1010.h"

long days_since(long month, long day)
{
  long days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  long days_since = 0;
  for (long i = 0; i < month - 1; i += 1) {
    days_since += days_in_month[i];
  }
  return days_since + day;
}

int main() 
{
  long month = cs1010_read_long();
  long day = cs1010_read_long();
  cs1010_println_long(days_since(month, day));
}
