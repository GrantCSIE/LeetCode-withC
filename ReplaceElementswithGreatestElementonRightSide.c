#include <stdio.h>
#include <stdlib.h>

// O(n) solution
int* replaceElements(int* arr, int arrSize, int* returnSize) {
    *returnSize = arrSize;
    int max = arr[arrSize - 1];
    for(int i = arrSize - 2; i >= 0; i --){
        if(arr[i] > max){
            int tmp = arr[i];
            arr[i] = max;
            max = tmp;
        }
        else if(arr[i] <= max){
            arr[i] = max;
        }
    }
    arr[arrSize - 1] = -1;
    return arr;
}


/* O(n^2) solution
int* replaceElements(int* arr, int arrSize, int* returnSize) {
    *returnSize = arrSize;
    for(int i = 0; i < arrSize - 1; i++){
        int tmp = arr[i + 1];
        for(int j = i + 2; j < arrSize; j++){
            if(arr[j] > tmp){
                tmp = arr[j];
            }
        }
        arr[i] = tmp;
    }
    arr[arrSize - 1] = -1;
    return arr;
}
*/

int main(){
    int arr [] = {17, 18, 5, 4, 6, 1};
    int *returnSize;
    returnSize = replaceElements(arr, 6,  returnSize);

    for(int i = 0; i < *returnSize; i++){
        printf("%d, ", arr[i]);
    }
    return 0;
}