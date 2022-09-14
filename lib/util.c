#include "util.h"

#include <stdio.h>

void max_print(void* array, size_t size, size_t typeBytes) {
  for(size_t i = 0; i < size; i++) {
    printf("%d ", *(int*)(array+(i*typeBytes)));
  }
  printf("\n");
}
