#include "cs1010.h"
#include <string.h>

int main()
{
  char *str = cs1010_read_line();
  cs1010_println_long((long)strlen(str));
  free(str);
}
