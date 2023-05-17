#include <stdio.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** largestLocal(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes){
  return NULL;
}

// print a square 2d array
void printArray2(int size, int array[size][size]) {
  for(size_t i = 0; i<size; i++) {
    for(size_t j = 0; j<size; j++) {
      printf("%d ", array[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

// test code
int main() {

  /* Input: grid = [[9,9,8,1],[5,6,2,6],[8,2,6,4],[6,2,2,2]] */
  /* Output: [[9,9],[8,6]] */
  int input[4][4] = {{9,9,8,1},{5,6,2,6},{8,2,6,4},{6,2,2,2}};
  int output[2][2] = {{9,9},{8,6}};

  printf("input:\n");
  printArray2(4, input);
}
