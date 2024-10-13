#include <stdio.h>
#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int* tmparr = (int *)malloc(numsSize * sizeof(int));
    for(int i = 0; i < numsSize; i++){
        tmparr[i] = nums[i] * nums[i];
    }
    for(int i = 0; i < numsSize; i++){
        for(int j = i; j < numsSize; j++){
            if(tmparr[i] > tmparr[j]){
                int tmp = tmparr[i];
                tmparr[i] = tmparr[j];
                tmparr[j] = tmp;
            }
        }
    }
    *returnSize = numsSize;
    return tmparr;
}


int main(){
    int *arr = (int *)malloc(5 * sizeof(int));
    arr[0] = -4;
    arr[1] = -1;
    arr[2] = 0;
    arr[3] = 3;
    arr[4] = 10;
    int numsSize = 5;
    int returnSize;

    arr = sortedSquares(arr, numsSize, &returnSize);
    for(int i = 0; i < numsSize; i ++){
        printf("%d, ", arr[i]);
    }
    return 0;
}