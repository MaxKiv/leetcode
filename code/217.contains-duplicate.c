/// Category: algorithms
/// Level: Easy
/// Percent: 61.002808%



 /// Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
 /// 
 ///  
 /// Example 1:
 /// Input: nums = [1,2,3,1]
 /// Output: true
 /// Example 2:
 /// Input: nums = [1,2,3,4]
 /// Output: false
 /// Example 3:
 /// Input: nums = [1,1,1,3,3,4,3,2,4,2]
 /// Output: true
 /// 
 ///  
 /// Constraints:
 /// 
 /// 
 /// 	1 <= nums.length <= 10⁵
 /// 	-10⁹ <= nums[i] <= 10⁹
 ///

#include <stdlib.h>

int compare(const void *a, const void *b) {
  int int_a = *((int *)a);
  int int_b = *((int *)b);
  return int_a - int_b;
}

bool containsDuplicate(int* nums, int numsSize) {
  qsort(nums, numsSize, sizeof(int), compare);

  for(size_t i = 0; i < numsSize-1; ++i) {
    if(nums[i] == nums[i+1]) {
      return true;
    }
  }
  return false;
}
