/**
 * CS1010 Semester 1 AY18/19
 * Assignment 4: Mastermind
 *
 * @file: mastermind.c
 * @author: XXX (Group YYY)
 */
#include "cs1010.h"
#include <stdbool.h>

#define PUZZLE_SIZE 4

bool check(const long guess[], const long answer[])
{
  long marked[PUZZLE_SIZE];
  for (long i = 0; i < PUZZLE_SIZE; i += 1) {
    marked[i] = answer[i];
  }
  long same_color_same_pos = 0;
  long same_color_diff_pos = 0;
  for (long i = 0; i < PUZZLE_SIZE; i += 1) {
    if (guess[i] == marked[i]) {
      same_color_same_pos += 1;
      marked[i] = 0;
    } 
  }

  for (long i = 0; i < PUZZLE_SIZE; i += 1) {
    bool found = false;
    for (long j = 0; j < PUZZLE_SIZE && !found; j += 1) {
      if (guess[i] != answer[i] && guess[i] == marked[j]) {
        same_color_diff_pos += 1;
        found = true;
        marked[j] = ' ';
      }
    }
  }

  cs1010_print_long(same_color_same_pos);
  cs1010_print_string(" ");
  cs1010_println_long(same_color_diff_pos);

  if (same_color_same_pos == PUZZLE_SIZE) {
    return true;
  }
  return false;
}

int main()
{
  long answer[PUZZLE_SIZE];
  for (long i = 0; i < PUZZLE_SIZE; i += 1) {
    answer[i] = cs1010_read_long();
  }
  
  bool correct;
  do {
    long guess[PUZZLE_SIZE];
    for (long i = 0; i < PUZZLE_SIZE; i += 1) {
      guess[i] = cs1010_read_long();
    }
    correct = check(guess, answer);
  } while (!correct);
}
