#include "cs1010.h"
#include <stdbool.h>
#include <stdlib.h>

#define FRIEND '1'
#define STRANGER '0'

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
bool is_friend(char **network, size_t i, size_t j) {
  if (i >= j) {
    return network[i][j] == FRIEND;
  }
  return network[j][i] == FRIEND;
}

/**
 * Checks if i and j is connected via degree-(h+1)
 * @param[in] n        The number of users
 * @param[in] degree_1 The 1-hop friendship information
 * @param[in] degree_h The h-hop friendship information
 * @param[in] i        A user
 * @param[in] j        Another user 
 * @return '1' if i and j has a (h+1)-hop connection, '0' otherwise.
 */
char is_degree_h_plus_1_friend(size_t n,  char **degree_1, 
                                char **degree_h, size_t i, size_t j) {
  if (is_friend(degree_h, i, j)) {
    return '1';
  }
  for (size_t m = 0; m < n; m += 1) {
    if ((is_friend(degree_1, i, m) && is_friend(degree_h, m, j))) {
      return '1';
    }
  }
  return '0';
}

/**
 * Compute the h-hop friendship for the whole network.
 * @param[in] n          The number of users.
 * @param[in] degree_1   The 1-hop friendship network
 * @param[in] degree_h   The h-hop friendship network
 * @param[out] result    The (h+1)-hop friendship network
 */
void compute_degree_h_plus_one(size_t n,  char **degree_1, 
                                char **degree_h, char **result) {
  for (size_t i = 0; i < n; i += 1) {
    for (size_t j = 0; j <= i; j += 1) {
      result[i][j] = is_degree_h_plus_1_friend(n, degree_1, degree_h, i, j);
    }
  }
}

void print_social(size_t n,  char **network)
{
  for (size_t i = 0; i < n; i += 1) {
    cs1010_println_string(network[i]);
  }
}

int main()
{
  size_t n = cs1010_read_size_t();
  size_t k = cs1010_read_size_t();
  char **degree_1;
  char **degree_h;
  char **result;

  degree_1 = calloc(n, sizeof(char *));
  if (degree_1 == NULL) {
      return 1;
  }
  degree_h = calloc(n, sizeof(char *));
  if (degree_h == NULL) {
      free(degree_1);
      return 1;
  }
  result = calloc(n, sizeof(char *));
  if (result == NULL) {
      free(degree_1);
      free(degree_h);
      return 1;
  }

  for (size_t i = 0; i < n; i ++) {
    degree_1[i] = cs1010_read_word();
    result[i] = calloc(i + 2, sizeof(char));
    degree_h[i] = calloc(i + 2, sizeof(char));
    for (size_t j = 0; j <= i; j++) {
      degree_h[i][j] = degree_1[i][j];
    }
  }

  for (size_t i = 1; i < k; i ++) {
    compute_degree_h_plus_one(n, degree_1, degree_h, result);
    swap(&degree_h, &result);
  }

  print_social(n, degree_h);

  for (size_t i = 0; i < n; i ++) {
    free(degree_1[i]);
    free(degree_h[i]);
    free(result[i]);
  }
  free(degree_1);
  free(degree_h);
  free(result);
}
