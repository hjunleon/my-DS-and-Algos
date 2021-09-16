#include <math.h>
#include "cs1010.h"

void find_unit_vector(const long v[3], double unit[3]) {
  double distance = sqrt((v[1] * v[1]) + (v[2] * v[2]) + (v[0] * v[0]));

  for (long i = 0; i < 3; i += 1) {
    unit[i] = v[i] / distance;
  }
}

int main()
{
  long vector[3];
  double unit[3];

  for (long i = 0; i < 3; i += 1) {
    vector[i] = cs1010_read_long();
  }

  find_unit_vector(vector, unit);

  for (long i = 0; i < 3; i += 1) {
    cs1010_println_double(unit[i]);
  }
}
