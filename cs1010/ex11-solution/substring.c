#include "cs1010.h"

void print(char* word)
{
  size_t len = strlen(word);
  for (size_t i = 0; i < len; i += 1) {
    if (word[i] != ' ') {
      putchar(word[i]);
    }
  }
  putchar('\n');
}

// remove k from word[curr]..word[end-1]
void combine(char* word, size_t k, size_t curr, size_t end)
{
  if (k == 0) {
    print(word);
    return;
  }
  if (end - curr == k) {
    char *temp = malloc(end);
    for (size_t i = curr; i < end; i += 1) {
      temp[i] = word[i];
      word[i] = ' ';
    }
    print(word);
    for (size_t i = curr; i < end; i += 1) {
      word[i] = temp[i];
    }
    free(temp);
    return;
  }
  if (curr != end) {
    // include curr and exclude k from the rest
    combine(word, k, curr+1, end);
    // exclude curr and k-1 from the rest
    char temp = word[curr];
    word[curr] = ' ';
    combine(word, k-1, curr+1, end);
    word[curr] = temp;
  }
}

int main()
{
  char *word = cs1010_read_word();
  size_t k = cs1010_read_size_t();
  size_t end = strlen(word);
  combine(word, end-k, 0, end);
  free(word);
}
