#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int* result = (int *)malloc((digitsSize + 1) * sizeof(int));
    if(digits[digitsSize - 1] + 1 != 10){
        for(int i = 0; i < digitsSize; i++){
            result[i] = digits[i];
        }
        result[digitsSize - 1] ++;
        *returnSize = digitsSize;
        return result;
    }
    else if(digits[digitsSize - 1] + 1 == 10){
        *returnSize = digitsSize;
        result[*returnSize - 1] = 0;
        int tmp = 1;
        for(int i = *returnSize - 2; i >= 0 ; i--){
            if(digits[i] + 1 == 10 && tmp == 1){
                result[i] = 0;
                tmp = 1;
            }
            else if(digits[i] + 1 != 10 && tmp == 1){
                result[i] = digits[i] + 1;
                tmp = 0;
            }
            else if(tmp == 0){
                result[i] = digits[i];
                tmp = 0;
            }
        }
        if(tmp == 1){
            *returnSize = digitsSize + 1;
            for(int i = 1; i < *returnSize; i++){
                result[i] = result[i - 1];
            }
            result[0] = 1;
            return result;
        }
        else if(tmp == 0){
            return result;
        }
    }
    exit(-1);
}

/* will lead integer overflow in case: [9,8,7,6,5,4,3,2,1,0]
int getlength(int a){
    int tmp = a;
    int length = 1;
    while(tmp / 10 >= 1){
        tmp = tmp / 10;
        length ++;
    }
    return length;
}

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int* result = (int *)malloc((digitsSize + 1) * sizeof(int));
    int sum = 0;
    for(int i = 0; i < digitsSize; i++){
        sum += digits[i] * (int)round(pow(10, digitsSize - 1 - i));
    }
    sum ++;
    int count = getlength(sum);
    if(count > digitsSize){
        digitsSize ++;
    }
    else if(count == digitsSize){

    }
    for(int i = 0; i < digitsSize; i++){
        result[i] = sum / (int)round(pow(10, digitsSize - 1 - i));
        sum -= result[i] * (int)round(pow(10, digitsSize - 1 - i));
    }
    *returnSize = digitsSize;
    return result;
}
*/

int main(){
    int arr[] = {9,8,7,6,5,4,3,2,1,0};
    int arrSize = sizeof(arr)/ sizeof(int);
    int returnSize;

    int* result = plusOne(arr, arrSize, &returnSize);

    for(int i = 0; i < returnSize; i++){
        printf("%d, ", result[i]);
    }
    return 0;
}
