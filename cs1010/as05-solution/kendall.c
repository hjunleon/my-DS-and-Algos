/**
 * CS1010 Semester 1 AY20/21
 * Assignment 3: Kendall
 *
 * Read in a sequence of numbers and find its kendall tau 
 * distance.
 *
 * @file: kendall.c
 * @author: XXX (Group YYY)
 */
#include "cs1010.h"

long count_inversion(size_t start, size_t len, const long rank[len])
{
  long count = 0;
  for (size_t j = start + 1; j < len; j += 1) {
    if (rank[start] > rank[j]) {
      count ++;
    }
  }
  return count;
}

double kendall_tau(size_t len, long rank[len])
{
  long count = 0;
  for (size_t i = 0; i < len - 1; i += 1) {
    count += count_inversion(i, len, rank);
  }

  return 2.0*count/(len*(len - 1));
}

int main()
{
  size_t len = cs1010_read_size_t();
  long* rank = cs1010_read_long_array(len);

  double distance = kendall_tau(len, rank);

  cs1010_println_double(distance);
  free(rank);
}
