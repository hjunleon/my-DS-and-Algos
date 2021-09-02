/**
 * CS1010 Semester 1 AY21/22
 * Exercise 1: Sum
 *
 * Read in two integers, print the total of the two integers, 
 * ignoring any negative integer.
 *
 * @file: sum.c
 * @author: Jaryl Ngoh Ye Shank (Group D04)
 */

#include "cs1010.h"
#include <immintrin.h>
#include <stdint.h>
int main()
{
    __m128i input_vector = _mm_set_epi64x(cs1010_read_long(),cs1010_read_long());
    __m128i mask_vector = _mm_set_epi64x((long)(input_vector[1]>0),(long)(input_vector[0]>0));
    //Unfortunately, the intrinsic _mm_mullo_epi64 requires avx512 support which this machine does not have, so this is as far as we go
    //While we can use _mm_mul_epu32 which was the sse2 way of dealing with multiplying 64 bit ints, out inputs will be casted to 32 bit which will fail test cases
    //__m128i ans_vector = _mm_mullo_epi64(input_vector,mask_vector);
    long ans_vector[2] = {mask_vector[1]*input_vector[1],mask_vector[0]*input_vector[0]};
    cs1010_println_long(ans_vector[1]+ans_vector[0]);
    return 0;
}