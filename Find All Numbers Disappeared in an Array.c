#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void cyclesort(int *nums, int numsSize){
    for(int i = 0; i < numsSize; i++){
        while(nums[i] != nums[nums[i] - 1]){
            int tmp = nums[i];
            nums[i] = nums[nums[i] - 1];
            nums[tmp - 1] = tmp;
        }
    }
    
}
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    cyclesort(nums, numsSize);

    int* disappeared = (int*)calloc(0, numsSize * sizeof(int));
    int count = 0;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] != i + 1){
            disappeared[count] = i + 1;
            count ++;
        }
    }
    *returnSize = count;
    return disappeared;
}

int main(){
    int arr[] = {4, 3, 2, 7, 8, 2, 3, 1};
    int arrSize = sizeof(arr) / sizeof(int);
    int returnSize;

    int *result = findDisappearedNumbers(arr, arrSize, &returnSize);
    for(int i = 0; i < returnSize; i++){
        printf("%d, ", result[i]);
    }

    return 0;
}