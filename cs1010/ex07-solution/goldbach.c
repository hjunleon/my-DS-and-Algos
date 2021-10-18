/**
 * CS1010 Semester 1 AY18/19
 * Practical Exam 1: Goldbach Conjecture
 *
 * Read in a positive integer n from the standard input,
 * and computes the number of ways we can write n as the
 * sum of two prime numbers.
 *
 * @file: goldbach.c
 * @author: XXX (Group YYY)
 */
#include "cs1010.h"
#include <math.h>
#include <stdbool.h>

/**
 * Checks if a given number n is prime.
 *
 * @param[in] n The number to check.
 * @return true if n is a prime, false otherwise.
 */
bool is_prime(long n)
{
  for (int i = 2; i <= sqrt(n); i += 1) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

/**
 * Count the number of prime pairs that sum to n. 
 *
 * @param[in] n The number to sum to.
 * @return The number of pairs of prime number that
 *         sum to n.
 */
long count_prime_pairs(long n)
{
  long count = 0;
  for (int i = 2; i <= n/2; i += 1) {
    if (is_prime(i) && is_prime(n-i)) {
      count += 1;
    }
  }
  return count;
}

int main()
{
  long n = cs1010_read_long();
  cs1010_println_long(count_prime_pairs(n));
}
