#include "cs1010.h"
#include <math.h>
#include <stdbool.h>

bool is_prime(long n) {
  if (n == 0) {
    return true;
  }
  for (long i = 2; i <= sqrt(n); i += 1) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

bool is_triangle(long n) {
  n *= 2;
  double x = ceil(sqrt(n));
  long lx = (long)x;
  if (lx*(lx+1) == n) {
    return true;
  } 
  return false;
}

int main()
{
  long n = cs1010_read_long();
  double d = floor(sqrt(2.0*n));
  long x = (long)d;
  long first_triangular = x*(x+1)/2;
  for (long i = first_triangular; i >= 0 && x >= 0; i -= (x+1)) {
    x -= 1;
    if (n >= i && is_prime(n - i)) {
      printf("%ld %ld\n", n-i, i);
    }
  }
}
