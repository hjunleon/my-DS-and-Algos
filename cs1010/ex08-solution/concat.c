#include "cs1010.h"

int main()
{
  char *str1 = cs1010_read_word();
  char *str2 = cs1010_read_word();

  size_t newlen = strlen(str1) + strlen(str2);
  char *dest = malloc(strlen(str1) + strlen(str2) + 1);
  dest[0] = '\0';
  strncat(dest, str1, newlen);
  strncat(dest, str2, newlen);
  cs1010_println_string(dest);
  
  free(dest);
  free(str1);
  free(str2);
}
