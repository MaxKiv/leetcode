// swaps two elements
void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int removeElement(int* nums, int numsSize, int val){
// iterate nums
  int j = numsSize;
  for(size_t i = 0; i < j;) {
    /* printf("loop i: %zu",i); */
    if(nums[i] == val) {
      // swap with last unchecked/valid element
      /* printf("swapping nums[i]: %d with nums[--j]: %d\n", nums[i], nums[j]); */
      swap(&nums[i], &nums[--j]);
      /* printf("decremented j : %d\n",j); */
    } else {
      // only increment if not swapped
      i++;
    }
  }
  return j;}
