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


//long determineBurgers1(long b, long pat, long c, long s, long pic){
 //   return 0;
//}

long numOfBurgers(long count, long ingredient){
    long res = 0;

    if (ingredient == 0){
        res = count / 3;
    } else if (ingredient == 1){
        res = count / 2;
    } else if (ingredient == 2){
        res = count;     
    } else if (ingredient == 3){
        res = count / 15;
    } else {
        res = count / 5;    
    }
    return res;

}

long determineBurgers(long *ingredients, long len){
    
    long maxSoFar = numOfBurgers(ingredients[0], 0);
    for (long i = 1; i < len; i += 1){
        //cs1010_println_long(ingredients[i]);
        long curMax = numOfBurgers(ingredients[i], i);
        if (curMax < maxSoFar){
            maxSoFar = curMax;    
        }
    }
    return maxSoFar;
}

int main() 
{
    long buns,patties,cheese, sesame, pickles;
    buns = cs1010_read_long();
    patties = cs1010_read_long();
    cheese = cs1010_read_long();
    sesame = cs1010_read_long();
    pickles = cs1010_read_long();
    long ingredients[5] = {buns,patties,cheese,sesame,pickles};
    long numBurgers = determineBurgers(ingredients, 5);//(buns, patties, cheese, sesame, pickles);
  
    cs1010_print_long(numBurgers);
    if (numBurgers == 1){
        cs1010_println_string(" burger");
    } else {
        cs1010_println_string(" burgers");    
    }
    return 0;
}
