#include "cs1010.h"
#include <stdbool.h>
#include <stdlib.h>

void swap(char ***a, char ***b) {
  char **temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

/**
 * Checks if i is connected to j in the given social network.
 * @param[in] network The social network
 * @param[in] i A user
 * @param[in] j Another user
 * @return true if i and j are connected in network, false otherwise.
 */
bool has_contact(char **network, size_t i, size_t j) {
  if (i >= j) {
    return network[i][j] == '1';
  }
  return network[j][i] == '1';
}

/**
 * Checks if i and j has a common contact
 * @param[in] n The number of users
 * @param[in] degree_one The 1-hop friendship information
 * @param[in] i A user
 * @param[in] j Another user 
 * @return k if i and j has a common contact k, -1 otherwise.
 */
long find_common_contact(size_t n, char **degree_one, size_t i, size_t j) {
  for (size_t m = 0; m < n; m += 1) {
    if ((has_contact(degree_one, i, m) && has_contact(degree_one, m, j))) {
      return (long)m;
    }
  }
  return -1;
}

int main()
{
  size_t n = cs1010_read_size_t();
  char **degree_one = cs1010_read_word_array(n);
  if (degree_one == NULL) {
    cs1010_println_string("unable to allocate memory");
    return 1;
  }

  size_t j = cs1010_read_size_t();
  size_t k = cs1010_read_size_t();
  if (has_contact(degree_one, j, k)) {
      cs1010_println_string("direct contact");
  } else {
      long m = find_common_contact(n, degree_one, j, k);
      if (m != -1) {
          cs1010_print_string("contact through ");
          cs1010_println_long(m);
      } else {
          cs1010_println_string("no contact");
      }
  }

  for (size_t i = 0; i < n; i ++) {
    free(degree_one[i]);
  }
  free(degree_one);
}
