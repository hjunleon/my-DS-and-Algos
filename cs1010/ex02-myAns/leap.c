/**
 * CS1010 Semester 1 AY21/22
 * Exercise 2: Leap
 *
 * Read in a year and determine if it is a leap year. 
 *
 * @file: leap.c
 * @author: XXX (Group YYY)
 */
#include <stdbool.h>
#include "cs1010.h"

bool is_leap_year(long year){
   if (year % 100 == 0){
        if (year % 400 == 0){
            return true;    
        }    
   } else if (year % 4 == 0) {
        return true;
   }

    

   return false;
}

int main() 
{
    long y = cs1010_read_long();
    cs1010_print_long(y);
    if (is_leap_year(y)){
      cs1010_println_string(" is a leap year");
    } else {
        cs1010_println_string(" is not a leap year");
    }
    return 0;
}
