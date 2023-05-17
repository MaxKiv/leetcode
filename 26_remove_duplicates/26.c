/**
 * @brief moves element to back of the array
 *
 * @param element_index element to move back
 * @param nums pointer to start of array
 * @param numsSize size of array
 */
void moveElementToback(int element_index, int *nums, int numsSize) {
  int temp = *(nums + element_index);
  for (int i = element_index; i < numsSize - 1; i++) {
    *(nums + i) = *(nums + i + 1);
  }
  *(nums + numsSize - 1) = temp;
}

/**
 * @brief removes duplicates from a sorted integer array by moving them to the
 * back
 * @param nums integer array to remove duplicates from
 * @param numsSize size of above array
 * @return number of unique items in the array
 */
int removeDuplicates(int *nums, int numsSize) {
  int num_unique_elements = numsSize;
  int last = -9999999;
  for (int i = 0; i < num_unique_elements; i++) {
    int current = *(nums + i);

    if (current == last) {
      moveElementToback(i, nums, numsSize);
      num_unique_elements--;
      i--;
    }

    last = current;
  }
  return num_unique_elements;
}
