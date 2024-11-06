#include <stdio.h>
#include <stdlib.h>

int removeElement(int* nums, int numsSize, int val) {
    int idx_val = 0;
    int idx_d = 0;
    int i, j;
    while(idx_val != numsSize){
        for(i = idx_val; i < numsSize; i++){
            if(nums[i] == val){
                idx_val = i;
                break;
            }
        }
        if(i == numsSize){
            break;
        }
        for(j = idx_d; j < numsSize; j++){
            if(nums[j] != val){
                idx_d = j;
                break;
            }
        }
        if(j == numsSize){
            break;
        }
        if(idx_d > idx_val){
            int tmp = nums[idx_d];
            nums[idx_d] = nums[idx_val];
            nums[idx_val] = tmp;
            idx_val ++;
            idx_d ++;
        }
        else if(idx_d < idx_val){
            idx_d ++;
        }
    }
    int newsize = numsSize - (idx_val - 1);
    return newsize;
}

int main(){
    int* arr = (int *)malloc(8 *sizeof(int));
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 2;
    arr[4] = 3;
    arr[5] = 0;
    arr[6] = 4;
    arr[7] = 2;

    int newsize = removeElement(arr, 8, 2);

    for(int i = 0; i < newsize; i++){
        printf("%d, ", arr[i]);
    }
    return 0;
}
