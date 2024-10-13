#include<stdio.h>
#include<stdlib.h>

int main(){
    int arr[5] = {1,12,3000,40,5};
    for(int i = 0; i < 5; i++){
        printf("%d element of the array is %5d\t", i + 1, arr[i]); //%5d 代表該輸出必須使用5個int輸出
        printf("%d element of the array is located at %d\n", i + 1, &arr[i]);
    }
    printf("the first element is located at %d", &arr); //&arr紀錄array的第一個元素所在的記憶體位置
}
