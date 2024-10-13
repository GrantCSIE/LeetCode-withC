#include <stdio.h>
#include <stdlib.h>

int* counting_sort(int* arr, int arrSize){
    int max = arr[0];
    for(int i = 1; i < arrSize; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    int *countarr = (int *)calloc(1, (max + 1) * sizeof(int));
    int countarrSize = (max + 1);


    for(int i = 0; i < arrSize; i++){ //儲存每個數字在arr出現的次數
        countarr[arr[i]] ++;
    }
    for(int i = 1; i < countarrSize; i++){ //累積出現的次數到下一個index
        countarr[i] += countarr[i - 1];
    }

    int *sortarr = (int *)malloc(arrSize * sizeof(int));

    for(int i = arrSize - 1; i >= 0; i--){
        sortarr[countarr[arr[i]] - 1] = arr[i];
        countarr[arr[i]] --;
    }

    return sortarr;
}

int heightChecker(int* heights, int heightsSize) {
    int *sortarr = counting_sort(heights, heightsSize);
    int count = 0;
    for(int i = 0; i < heightsSize; i++){
        if(heights[i] != sortarr[i]){
            count ++;
        }
    }
    return count;
}

int main(){
    int arr[] = {5, 1, 2, 3, 4};
    int arrSize = sizeof(arr)/ sizeof(int);

    int number = heightChecker(arr, arrSize);

    printf("%d", number);
    return 0;
}