#include <stdlib.h>
#include <stdio.h>

void print(int* array, int arraySize) {
  for(size_t i = 0; i < arraySize; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getConcatenation(int* nums, int numsSize, int* returnSize){
  // output array
  printf("numsSize %d\n", numsSize);
  printf("int size %d\n", (int)sizeof(int));
  printf("malloc out size %d\n", (int) (numsSize * 2 * sizeof(int)));

  int outSize = (int) (numsSize * 2 * sizeof(int));
  int* out = malloc(outSize);

  for(int j = 0; j < 2; j++) {
    for(int i = 0; i < numsSize; i++) {
      out[j*numsSize + i] = nums[i];
      printf("adding: %d\n", nums[i]);
    }
  }
  *returnSize = (int) outSize / sizeof(int);
  printf("returnSize %d\n", *returnSize);
  return out;
}

int main() {
  /* int* out = malloc(numsSize*2 * sizeof(int)); */
  int* returnSize;
  int in[5] = {1,2,3,4,5};
  int inputSize = (int)sizeof(in) / sizeof(int);

  print(in, inputSize);

  int* returnsize;
  int* out = getConcatenation(in, inputSize, returnsize);

  print(out, *returnsize);
}
