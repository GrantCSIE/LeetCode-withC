#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//time complexity O(n) and space complexity O(1) solution

int removeDuplicates(int* nums, int numsSize) {
    int tmp = nums[0];
    int idx = 1;
    for(int i = 1; i < numsSize; i++){
        if(nums[i] == tmp){ //if nums[i] is repeated
        }
        else if(nums[i] != tmp){ // if nums[i] is first appeared
            nums[idx] = nums[i];
            tmp = nums[idx];
            idx += 1;
        }
    }
    return idx;
}

/* O(n^2) solution
int removeDuplicates(int* nums, int numsSize) {
    int count = 0;
    int tmp = nums[0];
    int size = numsSize;
    for(int i = 1; i < size; ){
        if(nums[i] == tmp){
            for(int j = i; j < numsSize - 1; j++){
                nums[j] = nums[j + 1];
            }
            count ++;
            size -= 1;
        }
        else if(nums[i] != tmp){
            tmp = nums[i];
            i++;
        }
    }
    return numsSize - count;
}
*/

int main(){
    int *arr = (int *)malloc(3 * pow(10, 4) * sizeof(int));
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 2;
    int k = removeDuplicates(arr, 3);
    printf("k = %d\n", k);
    for(int i = 0; i < k; i++){
        printf("%d,", arr[i]);
    }
    return 0;
}