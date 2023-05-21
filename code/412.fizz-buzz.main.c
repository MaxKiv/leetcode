#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "412.fizz-buzz.c"

char **fizzBuzz(int n, int *returnSize);

int main() {

  int returnSize = 0;
  char **out = fizzBuzz(15, &returnSize);
  for (unsigned int i = 0; i < returnSize; ++i) {
    printf("%s ", out[i]);
    fflush(stdout);
  }

  return 0;
}
