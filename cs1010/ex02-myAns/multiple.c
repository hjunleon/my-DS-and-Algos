/**
 * CS1010 Semester 1 AY21/22
 * Exercise 2: Multiple
 *
 * Read in two integers and determine if one is a multiple of the other.
 *
 * @file: multiple.c
 * @author: XXX (Group YYY)
 */
#include "cs1010.h"
#include <stdbool.h>

int main() {
    long num1 = cs1010_read_long();
    long num2 = cs1010_read_long();
    bool res = (num1 == 0) || (num2 == 0) || (num1%num2 == 0)*(num1>num2) + (num2%num1 == 0)*(num2>num1);
    printf("%s", res ? "true" : "false");
    return 0;
}
