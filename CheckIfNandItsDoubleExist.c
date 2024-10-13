#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

struct HashTable{
    int val
};

void init(struct HashTable * table){
    for(int i = 0; i < 2 * 1000; i++){
        table[i].val = 0;
    }
}

bool checkIfExist(int* arr, int arrSize) {
    struct HashTable * table = (struct HashTable *)malloc((2 * pow(10, 3) + 2) * sizeof(struct HashTable));

    init(table);
    
    for(int i = 0; i < arrSize; i++){
        if(arr[i] > 0){ // if num > 0, then shift the index to num + 1001
            table[arr[i] + 1000 + 1].val = 1;
        }
        else if(arr[i] < 0){ // if num < 0, then store it to its positive index.
            table[abs(arr[i])].val = 1;
        }
        else if(arr[i] == 0){
            table[0].val += 1;
        }
    }
    for(int i = 0; i < arrSize; i++){
        if(arr[i] % 2 == 0){
            if(arr[i] < 0 && table[abs(arr[i] / 2)].val == 1){ //there is a negative num which is half of arr[i]
                printf("%d, %d",arr[i], abs(arr[i] / 2));
                return true;
            }
            else if(arr[i] > 0 && table[(arr[i] / 2) + 1000 + 1].val == 1){ //there is a positive num which is half og arr[i]
                printf("%d, %d",arr[i], abs(arr[i] / 2));
                return true;
            }
            else if(arr[i] == 0 && table[arr[i]].val >= 2){
                printf("%d, %d",arr[i], abs(arr[i]));
                return true;
            }
        }
    }
    free(table);
    return false;
}

int main(){
    int *arr = (int *)malloc((2 * pow(10, 3) + 2) * sizeof(int));
    arr[0] = -778;
    arr[1] = -481;
    arr[2] = 842;
    arr[3] = 495;

    bool tmp = checkIfExist(arr, 4);
    if(tmp == true){
        printf("True");
    }
    else{
        printf("False");
    }
    return 0;
}