#include <stdio.h>
#include <stdlib.h>


int removeElement(int* nums, int numsSize, int val) {
    int idx_val = 0, idx_nonval = 0;
    int count = 0;
    for(idx_val = 0; idx_val < numsSize; idx_val++){
        if(nums[idx_val] == val){
            for(idx_nonval = idx_val; idx_nonval < numsSize; idx_nonval++){
                if(nums[idx_nonval] != val){
                    break;
                }
            }
            if(idx_nonval != numsSize){ // 如果在想要找的val之後有找到不是val
                nums[idx_val] = nums[idx_nonval];
                nums[idx_nonval] = val;
                count = 0;
            }
            else if(idx_nonval == numsSize){ //如果之後再也沒有出現過val
                count ++;
            }
        }
    }
    return numsSize - count;
}
/*
int removeElement(int* nums, int numsSize, int val) {
    int count = 0;
    int dummy_idx = numsSize - 1;
    for(int i = 0; i < numsSize; ){
        if(nums[i] == val){
            nums[i] = nums[dummy_idx];
            nums[dummy_idx] = -1;
            dummy_idx -= 1;
            count ++;
        }
        else if(nums[i] != val){
            i++;
        }
    }
    return numsSize - count;
}
*/

int main(){

    int arr[] = {0, 1, 2, 2, 3, 0, 4, 2};
    int val = 2 ;
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    int newarrSize = removeElement(arr, arrSize, val);
    printf("%d\n", newarrSize);
    return 0;
}
