#include "cs1010.h"

long dot_product(long v1[4], long v2[4]) {
  long result = 0;
  for (long i = 0; i < 4; i += 1) {
    result += (v1[i] * v2[i]);
  }
  return result;
}

int main() 
{
  long v1[4];
  for (long i = 0; i < 4; i += 1) {
    v1[i] = cs1010_read_long();
  }

  long v2[4];
  for (long i = 0; i < 4; i += 1) {
    v2[i] = cs1010_read_long();
  }

  cs1010_println_long(dot_product(v1, v2));
}
