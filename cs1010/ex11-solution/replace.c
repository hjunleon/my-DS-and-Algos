#include "cs1010.h"
#include <stdbool.h>

/**
 * Return true if found a match. 
 * Update position i to the first occurance of search_for. 
 */
bool is_match(char *word, size_t *i, char *search_for) 
{
  size_t word_len = strlen(word);
  size_t search_len = strlen(search_for);
  size_t curr;
  size_t first_match;
  // find matching of first character.
  curr = *i;
  while (curr < word_len && word[curr] != search_for[0]) {
    curr += 1;
  }
  if (curr == word_len) {
    *i = word_len;
    return false;
  }
  *i = curr;
  first_match = curr;
  // check if the rest matches
  size_t w = *i;
  for (size_t j = 0; j < search_len; j += 1) {
    while (word[w] == ' ' && w < word_len) {
      w += 1;
    }
    if (w == word_len) {
      return false;
    }
    if (word[w] == search_for[0]) {
      first_match = w;
    }
    if (word[w] != search_for[j]) {
      *i = first_match;
      return false;
    }
    w += 1;
  }
  return true;
}

void substitute(char *word, size_t i, size_t search_len, char *replace_with) {
  size_t replace_len = strlen(replace_with);
  size_t j = 0;
  size_t w = j + i;
  while (j < replace_len) {
    while (word[w] == ' ') {
      w += 1;
    }
    word[w] = replace_with[j];
    j += 1;
    w += 1;
  }
  while (j < search_len) {
    while (word[w] == ' ') {
      w += 1;
    }
    word[w] = ' ';
    j += 1;
  }
}

void replace(char *word, char *search_for, char *replace_with) 
{
  size_t word_len = strlen(word);
  size_t search_len = strlen(search_for);
  for (size_t i = 0; i < word_len; i += 1) {
    if (is_match(word, &i, search_for)) {
      substitute(word, i, search_len, replace_with);
    }
  }
}

void print(char *word) {
  size_t word_len = strlen(word);
  for (size_t i = 0; i < word_len; i += 1) {
    if (word[i] != ' ') {
      putchar(word[i]);
    }
  }
  putchar('\n');
}

int main()
{
  char *word = cs1010_read_word();
  long times = cs1010_read_long();

  for (long i = 0; i < times; i += 1) {
    char *search_for = cs1010_read_word();
    char *replace_with = cs1010_read_word();
    replace(word, search_for, replace_with);
    free(search_for);
    free(replace_with);
  }
  print(word);
  free(word);
}
