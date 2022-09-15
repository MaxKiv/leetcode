#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
  int *out = (int*) malloc(2*sizeof(int));
  *returnSize = 2;

  for(size_t i = 0; i < numsSize; i++) {
    int remainder = target - nums[i];
    /* printf("nums[i]: %d\t", nums[i]); */
    /* printf("remainder: %d\t", remainder); */
    for(size_t j = 0; j < numsSize; j++) {
      if(j == i) {
        continue;
      }
      /* printf("nums[j]: %d\n", nums[j]); */
      if(nums[j] == remainder) {
        /* printf("found answer, target %d\n", target); */
        /* printf("nums[i] = %d\t nums[j] =%d\n", nums[i], nums[j]); */
        out[0] = i;
        out[1] = j;
        return out;
      }
    }
  }

  /* printf("we never found answer :("); */
  return out;
}
