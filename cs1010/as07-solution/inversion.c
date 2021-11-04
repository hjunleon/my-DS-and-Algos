/**
 * CS1010 Semester 1 AY18/19
 * Assignment 7: Inversion
 *
 * TODO(by student): Brief description of the purpose 
 * of this program.
 *
 * @file: inversion.c
 * @author: XXX (Group XXX)
 */

#include "cs1010.h"

/**
 * taking an array of integer with increasing sequence then decresing sequence
 * sort the array by merging the 2 sorted sequences split by peak
 * by merging the 2 from smaller values, and at the same time calculate inversion pair counts
 * @param[in] l the array of integers
 * @param[in] n the length of array
 * @return return the inversions in array l
 */
long count_inversion(long *l, size_t n) {
	//total number of inversions is stored in sum
	long i = 0;
  long j = (long)n-1;
  long sum = 0;
	while (i <= j) {
		if (l[i] < l[j]) {
			i += 1;
		}
		else {
			sum += j - i;
			j -= 1;
		}
	}
	return sum;
}

int main()
{
	size_t n = cs1010_read_size_t();
	long *l = cs1010_read_long_array(n);
  if (l == NULL) {
    cs1010_print_string("unable to allocate");
    return 1;
  }
	long result = count_inversion(l, n);
	cs1010_println_long(result);
	free(l);
}
