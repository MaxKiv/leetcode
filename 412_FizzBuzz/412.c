#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** fizzBuzz(int n, int* returnSize){
    *returnSize = n+1;
    char** out = malloc(*returnSize*sizeof(char*));
    out[n] = malloc(sizeof(char));
    strcpy(out[n], "\0");

    for(unsigned int i = 0; i < n; ++i) {
        if((i % 15) == 0) {
            out[i] = malloc(8*sizeof(char));
            strcpy(out[i], "FizzBuzz");
        } else if ((i % 5) == 0) {
            out[i] = malloc(4*sizeof(char));
            strcpy(out[i], "Buzz");
        } else if ((i % 3) == 0) {
            out[i] = malloc(4*sizeof(char));
            strcpy(out[i], "Fizz");
        } else {
            out[i] = malloc(sizeof(char));
            char* num;
            *num = i;
            strcpy(out[i], num);
        }
    }

    return out;
}

int main() {

    int returnSize = 0;
    char** out = fizzBuzz(15, &returnSize);
    for(unsigned int i = 0; i < returnSize; ++i) {
        printf("%s ", out[i]);
    }
}
