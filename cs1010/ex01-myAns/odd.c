/**
 * CS1010 Semester 1 AY21/22
 * Exercise 1: Odd
 *
 * Read in an integer and print the next larger odd number.
 *
 * @file: odd.c
 * @author: XXX (Group YYY)
 */

#include "cs1010.h"
#include <stdlib.h>



int main()
{
    long input = cs1010_read_long();
    long lookupArr[2] = {1,2};
    //cs1010_println_long((unsigned long)(input) % 2);
    cs1010_println_long(input + lookupArr[(unsigned long)(input) % 2]);
    return 0;
}
