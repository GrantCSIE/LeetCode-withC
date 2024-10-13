#include <stdio.h>
#include <stdlib.h>

int thirdMax(int* nums, int numsSize) {
    if(numsSize > 2){
        int first = 0, second = 1, third = 2;
        for(int i = 3; i < numsSize; i++){
            printf("%d, %d, %d\n", nums[first], nums[second], nums[third]);
            if(nums[i] > nums[first]){
                if(first != second){
                    third = second;
                    second = first;
                    first = i;
                }
                else if(first == second){
                    first = i;
                }
            }
            else if(nums[i] < nums[first] && nums[i] > nums[second]){
                if(second != third){
                    third = second;
                    second = i;
                }
                else if(second == third){
                    second = i;
                }
            }
            else if(nums[i] < nums[second] && nums[i] > nums[third]){
                third = i;
            }
            else if(nums[i] < nums[third]){

            }
        }
        return nums[third];
    }
    else if(numsSize == 2){
        if(nums[1] >= nums[0]){
            return nums[1];
        }
        else if(nums[1] < nums[0]){
            return nums[0];
        }
    }
    else if(numsSize == 1){
        return nums[0];
    }
    return -1;
}

int main(){
    int arr[] = {2, 2, 3, 1};
    int arrSize = sizeof(arr) / sizeof(int);

    int num = thirdMax(arr, arrSize);
    printf("%d", num);
    return 0;
}