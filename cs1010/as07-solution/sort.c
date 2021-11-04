/**
 * CS1010 Semester 1 AY18/19
 * Assignment 7: Script
 *
 * TODO(by student): Brief description of the purpose 
 * of this program.
 *
 * @file: script.c
 * @author: XXX (Group XXX)
 */
#include "cs1010.h"

/**
 * taking an array of integer with increasing sequence then decresing sequence
 * sort the array by merging the 2 sorted sequences split by peak
 * by merging the 2 from smaller values
 * @param[in] l the array of integers
 * @param[out] ans the array storing sorted array
 * @param[in] n the length of array
 * @post l is sorted and stored in ans
 */
void merge(const long *l, long *ans, size_t n) {
	long i = 0;
  long j = (long)n-1;
  long k = 0;
	while (i <= j) {
		if (l[i] < l[j]) {
			ans[k] = l[i];
			i += 1;
		}
		else {
			ans[k] = l[j];
			j -= 1;
		}
		k += 1;
	}
}

int main()
{
	size_t n = cs1010_read_size_t();
	long *l = cs1010_read_long_array(n);
  if (l == NULL) {
    cs1010_print_string("unable to allocate");
    return 1;
  }
	long *ans = calloc(n, sizeof(long));
  if (ans == NULL) {
    free(l);
    cs1010_print_string("unable to allocate");
    return 1;
  }
	merge(l, ans, n);
  for (size_t i = 0; i < n; i += 1) {
    cs1010_print_long(ans[i]);
    cs1010_print_string(" ");
  }
	cs1010_println_string("");
	free(l);
	free(ans);
}
