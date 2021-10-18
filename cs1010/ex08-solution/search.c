#include "cs1010.h"
#include <string.h>

int main()
{
  char *haystack = cs1010_read_word();
  char *needle = cs1010_read_word();

  char *result = strstr(haystack, needle);

  if (result == NULL) {
    cs1010_println_string("not found"); 
  } else {
    cs1010_println_long(result - haystack);
  }

  free(needle);
  free(haystack);
}
