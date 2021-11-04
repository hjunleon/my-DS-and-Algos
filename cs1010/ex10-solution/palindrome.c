/**
 * CS1010 Semester 1 AY18/19
 * Practical Exam 2: Palindrome
 *
 * TODO(by student): Brief description of the purpose
 * of this program.
 *
 * @file: palindrome.c
 * @author: XXX (Group XXX)
 */

#include "cs1010.h"
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

bool is_palindrome(char *s, long start, long end) {
  while (start < end) {
    if (!isalpha(s[start])) {
      start += 1;
    } else if (!isalpha(s[end])) {
      end -= 1;
    } else if (tolower(s[start]) != tolower(s[end])) {
      return false;
    } else {
      start += 1;
      end -= 1;
    }
  }
  return true;
}

int main() {
  char *s = cs1010_read_line();
  if (s == NULL) {
    cs1010_println_string("memory allocation error");
    return 1;
  }

  if (is_palindrome(s, 0, (long)strlen(s)-1)) {
    cs1010_println_string("yes");
  } else {
    cs1010_println_string("no");
  }

  free(s);
}
