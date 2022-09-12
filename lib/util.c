#include "util.h"

void swap(int* a, int* b) {
  int temp = *b;
  *a = *b;
  *b = temp;
}

void bubble_sort(int* a, int size) {
  for(int j = 0; j < size; j++) {
    for(int i = 0; i < size-1; i++) {
      if(a[i] > a[i+1])
        swap(&a[i], &a[i+1]);
    }
  }
}

void bubble_sort_n(int *a, int size) {

}
