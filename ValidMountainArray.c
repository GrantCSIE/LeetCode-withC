#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

bool validMountainArray(int* arr, int arrSize){
    if(arrSize < 3){
        return false;
    }
    else if(arrSize >= 3){
        int tmp = arr[0];
        int tmp_idx;
        for(int i = 1; i < arrSize; i ++){
            if(arr[i] == tmp){
                return false;
            }
            else if(arr[i] < tmp){ //start decreasing
                tmp = arr[i];
                for(int j = i + 1; j < arrSize; j++){
                    if(arr[j] > tmp){ //when decreasing, occur bigger num
                        return false;
                    }    
                    if(arr[j] == tmp){ // when decreasing, occur same num
                        return false;
                    }
                }
                return true;
            }
            else if(arr[i] > tmp){
                tmp = arr[i];
            }
        }
    }
    return false;
}

int main(){
    int arr[] = {0, 3, 2, 1};

    bool tmp = validMountainArray(arr, 4);

    printf("%d", tmp);
    return 0;
}