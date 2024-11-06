#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    int **result = (int **)malloc(numRows * sizeof(int *));
    *returnColumnSizes = (int *)malloc(numRows * sizeof(int)); 
    /*
    initialize the pointer returnColumnSizes with space numRows * sizeof(int) and casting to pointer (int *).
    it is similar to initializing an array: int *arr = (int *)malloc(numRows * sizeof(int));
    */
    int last = 1;
    result[0] = (int *)malloc(last * sizeof(int));
    result[0][0] = 1;

    (*returnColumnSizes)[0] = 1; 
    /*
    First, get the address of pointer returnColumnSizes by (*returnColumnSizes), 
    which indicates the start address of the space malloc(numRows * sizeof(int))
    Then, assign the 1-th of element to 1.

    It is also similar to assigning the 1-st element of an array:
    arr[0] = 1;
    */

    for(int i = 1; i < numRows; i++){
        result[i] = (int *)malloc(++last * sizeof(int));
        (*returnColumnSizes)[i] = last;
        for(int j = 0; j < last; j++){
            if(j == 0 || j == last - 1){
                result[i][j] = 1;
            }
            else if(j > 0 && j < last - 1){
                result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
            }
        }
    }
    *returnSize = numRows;
    return result;
}

int main(){

    int rows = 20;
    int returnSize;
    int *returnColumnSizes; // claim returnColumnSizes is a pointer(will act like an array after)
    
    int **result = generate(rows, &returnSize, &returnColumnSizes); 
    // pass the addresses of a value returnSize and a pointer returnColumnSizes, which is denoted as (int *) and (int **), respectively.
    
    for(int i = 0; i < returnSize; i++){
        printf("[");
        for(int j = 0; j < returnColumnSizes[i]; j++){
            printf("%d, ", result[i][j]);
        }
        printf("]");
    }
    return 0;
}
