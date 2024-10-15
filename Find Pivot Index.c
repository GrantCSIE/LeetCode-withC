#include <stdio.h>
#include <stdlib.h>

int pivotIndex(int* nums, int numsSize) {
    for(int i = 0; i < numsSize; i++){
        int left = i - 1;
        int right = i + 1;
        int left_sum = 0;
        int right_sum = 0;
        while(left != -1){
            left_sum += nums[left];     
            left -= 1;
        }
        while(right != numsSize){
            right_sum += nums[right];
            right ++;
        }
        if(left_sum == right_sum){
                return i;
        }
    }
    return -1;
}

int main(){
    int arr[] = {2,1,-1};
    int arrSize = sizeof(arr) / sizeof(int);

    int num = pivotIndex(arr, arrSize);
    
    printf("%d", num);
    return 0;
}