#include <stdlib.h>
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
  return out;
}
