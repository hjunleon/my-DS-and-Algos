/**
 * CS1010 Semester 1 AY20/21
 * Practical Exam 1: Reverse
 *
 * @file: reverse.c
 * @author: XXX (Group YYY)
 */
#include "cs1010.h"

long num_of_digits(long n)
{
    if (n < 10) {
        return 1;
    }
    return 1 + num_of_digits(n/10);
}

long ten_to_the_power_of(long k)
{
    if (k == 0) {
        return 1;
    }
    return 10 * ten_to_the_power_of(k - 1);
}

long reverse(long n, long nd)
{
    if (nd == 1) {
        return n;
    }
    return (n % 10) * ten_to_the_power_of(nd - 1) + reverse(n / 10, nd - 1);

}

int main()
{
  long n = cs1010_read_long();
  long nd = num_of_digits(n);
  long r = reverse(n, nd);
  cs1010_println_long(r*r);
}
