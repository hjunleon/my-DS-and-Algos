#include "cs1010.h"

int main()
{
  long mcneal = cs1010_read_long();
  long nixon = cs1010_read_long();

  long total = mcneal + nixon;

  cs1010_print_double(mcneal*100.0/total);
  cs1010_print_string(" ");
  cs1010_println_double(nixon*100.0/total);
}
