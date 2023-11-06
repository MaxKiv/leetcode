#include <stdio.h>
#include "../code/496.next-greater-element-i.c"

int main() {
  int nums1[3] = {4,1,2};
  int nums2[4] = {1,3,4,2};
  int returnSize = -1;
  int* out = nextGreaterElement(nums1, 3, nums2, 4, &returnSize);

  for(size_t i = 0; i < returnSize; ++i) {
    printf("%d ", out[i]);
  }
  printf("\n");
  free(out);
}
