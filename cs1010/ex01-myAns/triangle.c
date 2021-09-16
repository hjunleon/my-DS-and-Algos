/**
 * CS1010 Semester 1 AY21/22
 * Exercise 1: Triangle
 *
 * Read in three integers as the side of a triangle, and print
 * the area (unless it is impossible to form a triangle).
 *
 * @file: triangle.c
 * @author: XXX (Group YYY)
 */

#include <math.h>
#include <stdbool.h>
#include "cs1010.h"

double get_s(double a, double b, double c){
    return (a + b + c) / 2;
}

double get_heron(double a, double b, double c){
    double s = get_s(a,b,c);
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

bool is_valid_triangle(long a, long b, long c){   //explain why double wont work, and long max is 2147483647
    
    return ((a+b) > c && (a + c) > b && (b + c) > a);
}

int main()
{
    long a = cs1010_read_long();
    long b = cs1010_read_long();
    long c = cs1010_read_long();
    //cs1010_println_long(a); cs1010_println_long(b); cs1010_println_long(c);
    if (is_valid_triangle(a,b,c) == false){
        cs1010_println_string("Impossible");
        return 0;
    }
    cs1010_println_string("Possible");
    cs1010_println_double(get_heron(a,b,c));
    return 0;
    
}
