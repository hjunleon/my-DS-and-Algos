/**
 * CS1010 Semester 1 AY21/22
 * Exercise 1: Sum
 *
 * Read in two integers, print the total of the two integers, 
 * ignoring any negative integer.
 *
 * @file: sum.c
 * @author: XXX (Group YYY)
 */

#include "cs1010.h"

int main()
{
    long num1 = cs1010_read_long();
    long num2 = cs1010_read_long();
    long curVal = 0;
    if (num1 > 0){
        curVal += num1;    
    }
    if (num2 > 0){
        curVal += num2;    
    }
    cs1010_println_long(curVal);
    return 0;
}

