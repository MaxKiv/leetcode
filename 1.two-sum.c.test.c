#include <stdio.h>

#include "1.two-sum.c"

extern int *twoSum(int *nums, int numsSize, int target, int *returnSize);

/* void pip(void* arr, int bytesInElement) { */
/*   int size = sizeof(arr)/bytesInElement; */
/*   for(size_t i =0; i < size; i++) { */
/*     printf("%p ", *(arr+bytesInElement*i); */
/*   } */
/*     printf("\n"); */
/* } */

int main() {
  int nums[] = {1,10,11,2,3,7,9};
  int target = 10;
  int numsSize = (int) sizeof(nums)/sizeof(int);
  int* returnsize;

}
