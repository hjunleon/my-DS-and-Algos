/**
 * CS1010 Semester 1 AY20/21
 * Assignment 1: Digits
 *
 * Read in a positive integer from the standard input and print
 * the sum of the square of each digit in the integer to the standard output.
 *
 * @file: digits.c
 * @author: XXX (Group YYY)
 */

#include "cs1010.h"

/**
 * Sum the square of each digit in input.
 *
 * @param[in] input The integer whose digit square we are summing.
 * @return The sum of the square of each digit in the parameter input.
 */
long sum_of_digits(long input)
{
    if (input < 10) {
        return input;
    }
    long last_digit = input % 10;
    long rest = input / 10;
    return last_digit + sum_of_digits(rest);
}

int main()
{
    long input = cs1010_read_long();
    cs1010_println_long(sum_of_digits(input));
}
