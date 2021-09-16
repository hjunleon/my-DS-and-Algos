/**
 * CS1010 Semester 1 AY20/21
 * Practical Exam 1: Twilight
 *
 * @file: twilight.c
 * @author: XXX (Group YYY)
 */
#include "cs1010.h"
#include <stdbool.h>

bool falls_between(long hr, long min, long start_hr, long start_min, long end_hr, long end_min)
{
    long this_time = hr * 60 + min;
    long start_time = start_hr * 60 + start_min;
    long end_time = end_hr * 60 + end_min;

    return (this_time >= start_time && this_time <= end_time);
}

void print_twilight_category(long hr, long min) 
{
    if (falls_between(hr, min, 5, 41, 6, 5) || falls_between(hr, min, 19, 42, 20, 25)) {
        cs1010_println_string("astronomical");
        return;
    }
    if (falls_between(hr, min, 6, 6, 6, 29) || falls_between(hr, min, 19, 18, 19, 41)) {
        cs1010_println_string("nautical");
        return;
    }
    if (falls_between(hr, min, 6, 30, 6, 50) || falls_between(hr, min, 18, 57, 19, 17)) {
        cs1010_println_string("civil");
        return;
    }
    cs1010_println_string("not twilight");
}

int main()
{
    long hr = cs1010_read_long();
    long min = cs1010_read_long();
    print_twilight_category(hr, min);
}
