#include <stdio.h>
#include <stdlib.h>

int thirdMax(int* nums, int numsSize) {
    if(numsSize == 1){
        return nums[0];
    }
    else if(numsSize == 2){
        if(nums[0] > nums[1]){
            return nums[0];
        }
        else if(nums[0] < nums[1])
        {
            return nums[1];
        }
    }
    else if(numsSize > 2){
        int f = 0, s = 0, t = 0;
        for(int i = 1; i < numsSize; i++){
            if(nums[i] > nums[f]){ 
                // current num is larger than largerest num
                if(f != s){ 
                    // largest num is not equal to second largest
                    t = s;
                    s = f;
                    f = i;
                }
                else if (f == s || s != t || s == t){ 
                    // the largest num is equal to the second largest num
                    f = i;
                }
            }
            if(nums[i] < nums[f] && (nums[i] > nums[s] || f == s)){ 
                // current num is smaller than the largest num, 
                // but larger than the second largest num
                // or the second num is not defined
                if(s != t){
                    t = s;
                    s = i;
                }
                else if(s == t){
                    s = i;
                }
            }
            else if(nums[i] < nums[s] && (nums[i] > nums[t] || s == t || f == t)){
            // current num is smaller than the second largest num, 
                // but larger than the third largest num
                // or the third num is not defined
                // or the second num is not defined
                t = i;
            }
            else if(nums[i] < nums[t]){
                // the current num is smaller than the third num, do nothing.
    
            }
        }
        if(nums[f] == nums[s] || nums[s] == nums[t]){
            // if there's not exist any the second and third largest num.
            return nums[f];
        }
        else if(nums[f] != nums[s] && nums[s] != nums[t]){
            // if three maximum nums are existed.
            return nums[t];
        }
    }
    printf("error");
    exit(0);
}

int main(){
    int arr[] = {3, 2, 1};
    int arrSize = sizeof(arr) / sizeof(int);

    int num = thirdMax(arr, arrSize);

    printf("result: %d", num);

    return 0;

}