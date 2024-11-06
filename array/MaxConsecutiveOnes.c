#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int max = 0;
    int count = 0;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] == 1){
            count ++;
        }
        else{
            if(count > max){
                max = count;
            }
            count = 0;
        }
    }
    if(count > max){
        max = count;
    }
    return max;
}

int main(){
    int arr[6] = {1, 1, 0, 1, 1, 1};
    int num;
    int numsSize = 6;
    num = findMaxConsecutiveOnes(arr, numsSize);
    printf("%d", num);
    return 0;
}
