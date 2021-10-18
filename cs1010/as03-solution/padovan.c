#include "cs1010.h"
int main()
{
  long p[151];
  long n = cs1010_read_long();
  p[0] = 1;
  p[1] = 0;
  p[2] = 0;
  for (long i = 3; i <= n; i += 1) {
    p[i] = p[i-2] + p[i-3];
  }
  for (long i = n; i >= 0; i -= 1) {
    cs1010_println_long(p[i]);
  }
}
