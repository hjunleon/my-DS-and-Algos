/**
 * CS1010 Semester 1 AY20/21
 * Practical Exam 1: Factors
 *
 * @file: factors.c
 * @author: XXX (Group YYY)
 */
#include "cs1010.h"
#include <math.h>
#include <stdbool.h>

bool is_prime(long n) 
{
  for (long i = 2; i <= sqrt(n); i += 1) {
      if (n % i == 0) {
          return false;
      }
  }
  return true;
}

void print_prime_factors(long n) 
{
    long curr = n;
    for (long factor = 2; factor <= sqrt(n) && curr != 1; factor += 1) {
        if (is_prime(factor)) {
            long counter = 0;
            while (curr % factor == 0) {
                curr = curr / factor;
                counter += 1;
            }
            if (counter != 0) {
                cs1010_print_long(factor);
                cs1010_print_string(" ");
                cs1010_println_long(counter);
            }
        }
    }
    if (curr != 1 && is_prime(curr)) {
       cs1010_print_long(curr);
       cs1010_println_string(" 1");
    }
}

int main()
{
    long n = cs1010_read_long();
    print_prime_factors(n);
}
