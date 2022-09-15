#include <stdio.h>
#include <stdlib.h>
#include "util.h"

extern int* twoSum(int* nums, int numsSize, int target, int* returnSize);

int main() {
  int nums[] = {-1,-2,-3,-4,-5};
  int target = -8;
  size_t numsSize = sizeof(nums)/sizeof(nums[0]);

  printf("target: %d\n", target);
  printf("input array:\n");
  max_print(nums, numsSize, sizeof(int));

  int* returnSize = malloc(sizeof(int));
  int* out = twoSum(nums, numsSize, target,  returnSize);

  printf("returnsize: %d\n", *returnSize);
  printf("Returned array:\n");
  max_print(out, *returnSize, sizeof(int));

}
