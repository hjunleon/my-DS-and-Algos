#include "cs1010.h"

long look_and_say(long n) 
{
  long say = 0;
  long curr = n % 100000000;
  long factor = 1;
  while (curr != 0) {
    // count how many times the last digit occur
    long occurance_counter = 0;
    long last_digit = curr % 10;
    do {
      curr = curr / 10;
      occurance_counter += 1;
    } while (last_digit == curr % 10);
    say = say + (occurance_counter * 10 + last_digit) * factor;
    factor *= 100;
  }
  return say;
}

int main()
{
  long n = cs1010_read_long();
  long k = cs1010_read_long();
  for (long i = 1; i < k; i += 1) {
    n = look_and_say(n);
  }
  cs1010_println_long(n);
}
