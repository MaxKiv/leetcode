/**
 * @brief moves element to back of the array
 *
 * @param element_index element to move back
 * @param nums pointer to start of array
 * @param numsSize size of array
 */
void moveElementToback(int element_index, int* nums, int numsSize) {
  int temp = *(nums + element_index);
  /* shift every element left */
  for(int i = element_index; i < numsSize-1; i++) {
    *(nums + i) = *(nums + i + 1);
  }
  /* set last element */
  *(nums + numsSize-1) = temp;
}

int removeDuplicates(int* nums, int numsSize) {
  int num_unique_elements = 0;
  int last = -9999999;
  for(int i = 0; i < numsSize; i++) {
    int current = *(nums + i);
    if(current == last) {
      moveElementToback(i, nums, numsSize);
      num_unique_elements++;
    }
    last = current;
  }
  return num_unique_elements;
}
