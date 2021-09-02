/**
 * CS1010 Semester 1 AY21/22
 * Exercise 1: Burger
 *
 * Read in the amount of ingredients available and
 * print the number of burgers that can be prepared
 * with the ingredients.
 *
 * @file: burger.c
 * @author: XXX (Group YYY)
 */

#include "cs1010.h"

long count_burgers(long buns, long patties, long cheese, long sesame_seeds, long pickles) {
  const long buns_per_burger = 3;
  const long patties_per_burger = 2;
  const long cheese_per_burger = 1;
  const long sesame_seeds_per_burger = 15;
  const long pickles_per_burger = 5;

  long num_burgers = buns / buns_per_burger;
  if (num_burgers > patties / patties_per_burger) {
    num_burgers = patties / patties_per_burger;
  }
  if (num_burgers > cheese / cheese_per_burger) {
    num_burgers = cheese / cheese_per_burger;
  }
  if (num_burgers > sesame_seeds / sesame_seeds_per_burger) {
    num_burgers = sesame_seeds / sesame_seeds_per_burger;
  }
  if (num_burgers > pickles / pickles_per_burger) {
    return pickles / pickles_per_burger;
  }
  return num_burgers;
}

int main() 
{
  long buns = cs1010_read_long();
  long patties = cs1010_read_long();
  long cheese = cs1010_read_long();
  long sesame = cs1010_read_long();
  long pickles = cs1010_read_long();

  long num_burgers = count_burgers(buns, patties, cheese, sesame, pickles);

  cs1010_print_long(num_burgers);
  if (num_burgers == 1) {
    cs1010_println_string(" burger");
  } else {
    cs1010_println_string(" burgers");
  }
}
