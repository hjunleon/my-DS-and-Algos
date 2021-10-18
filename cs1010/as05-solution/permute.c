#include <stdio.h>
#include <stdlib.h>
#include <sys/times.h>

int main(int argc, char *argv[])
{
  if (argc != 2) {
    fprintf(stderr, "usage: %s <n>\n", argv[0]);
    return 1;
  }
  srandom((unsigned int)times(0));

  char *end;
  long n = strtol(argv[1], &end, 10);

  long *seq = malloc((size_t)n * sizeof(long));
  if (seq == NULL) {
    fprintf(stderr, "memory not enough.\n");
    return 2;
  }
  for (long i = 0; i < n; i += 1) {
    seq[i] = i + 1;
  }

  for (int i = 0; i < n; i += 1) {
    long pos1 = random() % n;
    long pos2 = random() % n;
    long temp;
    temp = seq[pos1];
    seq[pos1] = seq[pos2];
    seq[pos2] = temp;
  }

  for (long i = 0; i < n; i += 1) {
    printf("%ld ", seq[i]);
  }
  printf("\n");
  free(seq);
}
