#include <stddef.h> // size_t typdef
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
  int *out = (int *)malloc(2 * sizeof(int));
  *returnSize = 2;
  for (size_t i = 0; i < numsSize; i++) {
    int remainder = target - nums[i];
    if (remainder < 0) {
      continue;
    }
    for (size_t j = 0; j < numsSize; j++) {
      // dont use the same item twice
      if (j == i) {
        continue;
      }
      if (nums[j] == remainder) {
        out[0] = nums[j];
        out[1] = remainder;
        return out;
      }
    }
  }
  return out;
}
