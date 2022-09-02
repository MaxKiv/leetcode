#include <stdlib.h>
#include <stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getConcatenation(int* nums, int numsSize, int* returnSize){
  // output array
  int* out = malloc(numsSize*2 * sizeof(int));
  for(int j = 1; j < 3; j++) {
    for(int i = 0; i < sizeof(out); i++) {
      out[j*i] = nums[i];
    }
  }
  *returnSize = sizeof(out);
  return out;
}

int main() {
  /* int* out = malloc(numsSize*2 * sizeof(int)); */
  int* returnSize;
  int in[5] = {1,2,3,4,5};
  int inputSize = (int)sizeof(in) / sizeof(int);
  printf("inputSize %d", inputSize);
  for(int i = 0; i < inputSize; i++) {
    printf("in[%d] = %d\n", i, in[i]);
  }
}
