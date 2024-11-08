#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize) {
    int* result = (int *)malloc(matSize * (*matColSize) * sizeof(int));
    int count = 0;

    int i = 0; int j = 0;
    
    int dir = 1; // 1 denotes right up path, 0 denotes right down path.

    while(count < matSize * (*matColSize)){
        result[count] = mat[i][j];
        count ++;
        if(dir == 1){
            if(j == *matColSize - 1){
                dir = 0;
                i ++;
            }
            else if(j < *matColSize - 1 && i == 0){
                dir = 0;
                j++;
            }
            else if(j < *matColSize - 1 && i > 0){
                i -= 1;
                j ++;
            }
        }
        else if(dir == 0){
            if(i == matSize - 1){
                dir = 1;
                j++;
            }
            else if(i < matSize - 1 && j == 0){
                dir = 1;
                i ++;
            }
            else if(i < matSize - 1 && j > 0){
                i ++;
                j -= 1;
            }
        }
    }

    *returnSize = count;
    return result;
}

int main(){
    int rows = 3, cols = 3;
    int **arr = (int **)malloc(rows * sizeof(int *));
    for(int i = 0; i < rows; i++){
        arr[i] = (int *)malloc(cols * sizeof(int));
    }

    int val[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            arr[i][j] = val[i][j];
        }
    }

    int matSize = 3;
    int matColSize = 3;

    //int matSize = sizeof(arr) / sizeof(arr[0][0]); // get the number of elements in 2D array.
    //int matColSize = sizeof(arr[0]) / sizeof(arr[0][0]); // get the number of columns in 2D array.
    //int matrowSize = sizeof(mat) / sizeof(mat[0]);// get the number of rows in 2D array.
    
    int returnSize;

    int *result = findDiagonalOrder(arr, matSize, &matColSize, &returnSize);

    for(int i = 0; i < returnSize; i++){
        printf("%d,", result[i]);
    }
    return 0;
}
