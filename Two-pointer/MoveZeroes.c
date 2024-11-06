#include <stdio.h>
#include <stdlib.h>

void moveZeroes(int* nums, int numsSize) {
    if(numsSize == 1){
    }   
    else if(numsSize > 1){
        int idx = 0;
        for(int i = 0; i < numsSize; i++){
            if(nums[i] != 0){
                nums[idx] = nums[i];
                idx ++;
            }
        }
        for(int i = idx; i < numsSize; i++){
            nums[i] = 0;
        }
    }
}

int main(){
    int arr[] = {0, 1, 0, 3, 12};
    moveZeroes(arr, 5);
    for(int i = 0; i < 5; i++){
        printf("%d, ", arr[i]);
    }
    return 0;
}
