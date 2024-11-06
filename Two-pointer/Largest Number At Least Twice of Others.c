#include <stdio.h>
#include <stdlib.h>

int dominantIndex(int* nums, int numsSize) {
    int first, second;
    if(nums[0] > nums[1]){
        first = 0;
        second = 1;
    }
    else if(nums[0] <= nums[1]){
        first = 1;
        second = 0;
    }
    for(int i = 2; i < numsSize; i++){
        if(nums[i] > nums[first]){
            second = first;
            first = i;
        }
    }
    for(int i = 2; i < numsSize; i++){
        if(nums[i] > nums[second] && i != first){
            second = i;
        }
    }
    if(nums[first] >= 2 * nums[second]){
        return first;
    }
    else if(nums[first] < 2 * nums[second]){
        return -1;
    }
    exit(0);
}

int main(){

    int arr[] = {3,6,1,0};
    int arrSize = sizeof(arr)/ sizeof(int);

    int num = dominantIndex(arr, arrSize);
    printf("%d", num);
    return 0;
}
