#include <stdio.h>
#include <stdlib.h>

int* sortArrayByParity(int* nums, int numsSize, int* returnSize) {
    int idx_odd = 0;
    int idx_even = 0;
    while(idx_even != numsSize && idx_odd != numsSize){
        int i, j;
        for(i = idx_odd; i < numsSize; i++){
            if(nums[i] % 2 != 0){
                idx_odd = i;
                break;
            }
        }
        if(i == numsSize){
            break;
        }
        for(j = idx_even; j < numsSize; j++){
            if(nums[j] % 2 == 0){
                idx_even = j;
                break;
            }
        }
        if(j == numsSize){
            break;
        }
        printf("%d, %d\n", idx_even, idx_odd);
        if(idx_even > idx_odd){
            int tmp;
            tmp = nums[idx_even];
            nums[idx_even] = nums[idx_odd];
            nums[idx_odd] = tmp;
            idx_even ++;
            idx_odd ++;
        }
        else if(idx_even < idx_odd){
            idx_even ++;
        }
    }
    *returnSize = numsSize;
    return nums;
}

int main(){
    int *arr = (int *)malloc(5 * sizeof(int));;
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;

    int returnSize;
    arr = sortArrayByParity(arr, 3, &returnSize);
    for(int i = 0; i < 4; i++){
        printf("%d,", arr[i]);
    }
    return 0;
}
