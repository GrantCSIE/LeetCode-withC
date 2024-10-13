#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 2 pointer approach with O(n) time complexity and O(n) space complexity
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int idx_nega;
    int idx_post;

    nums[numsSize - 1] = abs(nums[numsSize - 1]);

    for(int i = 0; i < numsSize; i++){
        if(nums[i] >= 0){
            idx_nega = i - 1;
            idx_post = i;
            break;
        }
    }

    int *tmp = (int *)malloc(numsSize * sizeof(int));
    int count = 0;
    for( ; idx_nega >= 0 && idx_post < numsSize; count++){
        if(abs(nums[idx_nega]) <= abs(nums[idx_post])){
            tmp[count] = nums[idx_nega] * nums[idx_nega];
            idx_nega -= 1;
        }
        else if(abs(nums[idx_nega]) > nums[idx_post]){
            tmp[count] = nums[idx_post] * nums[idx_post];
            idx_post ++;
        }
    }
    if(idx_nega == -1){
        for(int i = idx_post; idx_post < numsSize; idx_post++){
            tmp[count] = nums[idx_post] * nums[idx_post];
            count++;
        }
    }
    else if(idx_post == numsSize){
        for(int i = idx_nega; idx_nega >= 0; idx_nega--){
            tmp[count] = nums[idx_nega] * nums[idx_nega] ;
            count++;
        }
    }
    *returnSize = numsSize;
    return tmp;
}


/* approach with squaring each element and sorting
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
*/


int main(){
    int nums[] = {-7,-3,2,3,11};
    int numsSize = sizeof(nums) / sizeof(int);
    int returnSize;

    int *arr = sortedSquares(nums, numsSize, &returnSize);
    for(int i = 0; i < numsSize; i ++){
        printf("%d, ", arr[i]);
    }
    return 0;
}