#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int find_nums2_idx(int nums1_item, const int* nums2, int nums2Size) {
  int out = -1;
  for(int i = 0; i < nums2Size; ++i) {
    if(nums2[i] == nums1_item){
      out = i;
    }
  }
  return out;
}

int find_next_greater_element(int nums2_idx, int *nums2, int nums2Size) {
  int out = -1;
  for (size_t i = nums2_idx; i < nums2Size; ++i) {
    if (nums2[i] > nums2[nums2_idx]) {
      out = nums2[i];
      return out;
    } else {
    }
  }
  return out;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
  *returnSize = nums1Size;
  int* out = (int*)malloc(nums1Size * sizeof(int));
  for (size_t i = 0; i < nums1Size; ++i) {
    int nums2_idx = find_nums2_idx(nums1[i], nums2, nums2Size);
    out[i] = find_next_greater_element(nums2_idx, nums2, nums2Size);
  }
  return out;
}
