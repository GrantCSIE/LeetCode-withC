#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int findNumbers(int* nums, int numsSize) {
    int num_even = 0;
    for(int i = 0 ; i < numsSize; i ++){
        int count = 0;
        int tmp = nums[i];
        while(tmp / 10 != 0){
            tmp = tmp / 10;
            count ++;
        }
        count ++;
        if(count % 2 == 0){
            num_even ++;
        }
    }
    return num_even;
}

int main(){
    int arr[5] = {12, 345, 2, 6, 7896};
    int numsSize = 5;

    int num = findNumbers(arr, numsSize);
    printf("%d", num);    
}