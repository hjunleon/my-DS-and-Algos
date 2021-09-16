/**
 * CS1010 Semester 1 AY21/22
 * Exercise 2: GCD
 *
 * Read in two integers, print their GCD.
 *
 * @file: gcd.c
 * @author: XXX (Group YYY)
 */
#include <stdbool.h>
#include "cs1010.h"

long GCD(long a, long b){
    if (a == b){
        return a;    
    }
    long res;
    if (a > b){
        res = GCD(a-b,b);
    } else {
        res = GCD(b-a, a);
    }
    return res;        
}


int main() 
{
    long x = cs1010_read_long();
    long y = cs1010_read_long();
    cs1010_println_long(GCD(x,y));
    return 0;
}
