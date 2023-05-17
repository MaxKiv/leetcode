#include <stdio.h>
#include <stdlib.h>

#include "1.two-sum.c"

extern int *twoSum(int *nums, int numsSize, int target, int *returnSize);

void pip(void *arr, int arrSize, int elementBytes) {
  for (size_t i = 0; i < arrSize; i++) {
    printf("%d ", *(int *)(arr + elementBytes * i));
  }
  printf("\n");
}

int main() {
  int nums[] = {1, 10, 11, 2, 3, 7, 9};
  int target = 10;
  int numsSize = (int)sizeof(nums) / sizeof(nums[0]);
  int *returnSize;
  printf("Input\n");
  pip(nums, numsSize, sizeof(nums[0]));
  int *out = twoSum(nums, numsSize, target, returnSize);
  printf("Output\n");
  pip(out, *returnSize, sizeof(out[0]));
  printf("Output size: %d", *returnSize);
}
