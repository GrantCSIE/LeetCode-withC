#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void shifting(int *arr, int arrSize, int index){
    if(index != arrSize){
    }
}


void duplicateZeros(int* arr, int arrSize) {
    for(int i = 0; i < arrSize; i++){
        if(arr[i] == 0 && i + 1 != arrSize){
            int tmp = arr[i + 1];
            arr[i + 1] = 0;
            if(i + 2 != arrSize){
                for(int j = arrSize - 1; j > i + 2; j--){
                    arr[j] = arr[j - 1];
                }
                arr[i + 2] = tmp;
                i++;
            }
        }
    }
}

int main(){
    int *arr = (int *)malloc(9 *sizeof(int));
    int arrSize = 9;
    arr[0] = 1;
    arr[1] = 5;
    arr[2] = 2;
    arr[3] = 0;
    arr[4] = 6;
    arr[5] = 8;
    arr[6] = 0;
    arr[7] = 6;
    arr[8] = 0;
    duplicateZeros(arr, arrSize);
    for(int i = 0; i < arrSize; i++){
        printf("%d,", arr[i]);
    }
    return 0;
}