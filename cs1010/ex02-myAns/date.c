/**
 * CS1010 Semester 1 AY21/22
 * Exercise 2: Date
 *
 * Read in three dates and check if the dates are in
 * increasing order.
 *
 * @file: date.c
 * @author: XXX (Group YYY)
 */

#include <stdbool.h>
#include "cs1010.h"

bool is_after(long *date1, long *date2){
    return ((date2[0] > date1[0]) || (date2[0] == date1[0] && date2[1] > date1[1]));    
}


int main() 
{
    long* date1 = cs1010_read_long_array(2);
    long* date2 = cs1010_read_long_array(2);
    long* date3 = cs1010_read_long_array(2);
    //printf("%d %d", date1[0],date1[1]);
    bool result = is_after(date1, date2) && is_after(date2,date3);
    if (result){
        cs1010_println_string("yes");
    } else {
        cs1010_println_string("no");     
    }
    return 0;


}
