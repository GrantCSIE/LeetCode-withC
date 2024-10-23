#include <stdio.h>
#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int *result = (int *)malloc(matrixSize * (*matrixColSize) * sizeof(int));
    int count = 0;
    int lb_row = 0; int lb_col = 0; int ub_row = matrixSize; int ub_col = *matrixColSize;
    int i = 0; int j = 0;
    int dir = 0; // 0, 1, 2, 3 denote right, down, left, up, respetively.

    while(count < matrixSize * (*matrixColSize)){
        result[count++] = matrix[i][j];
        if(dir == 0){
            if(j == ub_col - 1){
                i ++;
                lb_row ++;
                dir = 1;
            }
            else if(j < ub_col - 1){
                j ++;
            }
        }
        else if(dir == 1){
            if(i == ub_row - 1){
                j -= 1;
                ub_col -= 1;
                dir = 2;
            }
            else if(i < ub_row - 1){
                i ++;
            }
        }
        else if(dir == 2){
            if(j == lb_col){
                i -= 1;
                ub_row -= 1;
                dir = 3;
            }
            else if(j > lb_col){
                j -= 1;
            }
        }
        else if(dir == 3){
            if(i == lb_row){
                j ++;
                lb_col ++;
                dir = 0;
            }
            else if(i > lb_row){
                i -= 1;
            }
        }
    }
    *returnSize = matrixSize * (*matrixColSize);
    return result;
}


int main(){
    int row = 3;
    int col = 3;
    int **arr = (int **)malloc(row * sizeof(int *));
    for(int i = 0; i < row; i++){
        arr[i] = (int *)malloc(col * sizeof(int));
    }
    int val[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j ++){
            arr[i][j] = val[i][j];
        }
    }

    int returnSize;

    int *result = spiralOrder(arr, row, &col, &returnSize);

    for(int i = 0; i < returnSize; i++){
        printf("%d,", result[i]);
    }
    return 0;
}