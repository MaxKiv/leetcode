#include <stdio.h>

#include "26.c"

#define SIZE 10

void moveElementToback(int element_index, int* nums, int numsSize);

void print_array(int *nums, int numsSize);

int main() {
  /* int arr[SIZE] = {0, 1, 1, 1, 4, 5, 5, 7, 8, 9}; */ 
  int arr[SIZE] = {0,0,1,1,1,2,2,3,3,4};
  print_array(arr, SIZE);
  /* moveElementToback(3, arr, SIZE); */
  int num_uniq = removeDuplicates(arr, SIZE);
  print_array(arr, SIZE);
  printf("number of unique items: %d", num_uniq);
}

void print_array(int *nums, int numsSize) {
  printf("array:\n");
  for(size_t i = 0; i < numsSize; i++) {
    printf(" %d", *(nums+i));
  }
  printf("\n");
}
