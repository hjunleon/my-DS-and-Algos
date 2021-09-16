#include "cs1010.h"

void count_digits(long n, long digits[10]) {
  if (n == 0) {
    digits[0] = 1;
    return;
  }
  while (n != 0) {
    long last_digit = n % 10;
    n = n / 10;
    digits[last_digit] += 1; 
  }
}

int main()
{
  long count[10] = {0};

  long n = cs1010_read_long();
  count_digits(n, count);

  for (long i = 0; i < 10; i += 1) {
    if (count[i] != 0) {
      cs1010_print_long(i);
      cs1010_print_string(": ");
      cs1010_println_long(count[i]);
    }
  }
}
