#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **fizzBuzz(int n, int *returnSize) {
  *returnSize = n;
  char **out = malloc(n * sizeof(char *));

  for (unsigned int i = 1; i <= n; ++i) {
    out[i-1] = malloc(11);
    if ((i % 15) == 0) {
      strncpy(out[i-1], "FizzBuzz", 9);
    } else if ((i % 5) == 0) {
      strncpy(out[i-1], "Buzz", 5);
    } else if ((i % 3) == 0) {
      strncpy(out[i-1], "Fizz", 5);
    } else {
      sprintf(out[i-1], "%d", i);
    }
  }

  return out;
}


