#include <stdio.h>
#include <stdint.h>

void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void printArray(int* nums, int numsSize) {
  for(uint16_t i = 0; i < numsSize; i++) {
    printf("%d ", nums[i]);
  }
  printf("\n");
}
int removeElement(int* nums, int numsSize, int val){
  // iterate nums
  int j = numsSize;
  for(size_t i = 0; i < j;) {
    printf("loop i: %zu",i);
    if(nums[i] == val) {
      // swap with last unchecked/valid element
      printf("swapping nums[i]: %d with nums[--j]: %d\n", nums[i], nums[j]);
      swap(&nums[i], &nums[--j]);
      printf("decremented j : %d\n",j);
    } else {
      // only increment if not swapped
      i++;
    }
  }
  return j;
}


int main() {

  int nums[] = {1,2,3,2,1};
  int val = 2;
  int size = sizeof(nums)/sizeof(int);
  printArray(nums, size);
  int out = removeElement(nums, size, val);
  printArray(nums, size);
  printf("result: %d", out);
  return 0;
}
