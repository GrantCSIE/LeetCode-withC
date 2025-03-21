#include <stdio.h>
#include <stdlib.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i, j;
    if(m == 0){
        for(int i = 0; i < n; i++){
            nums1[i] = nums2[i];
        } 
    }
    else if(n == 0){

    }
    else if(m == 0 && n == 0){
        
    }
    else{
        for(i = 0, j = 0; i < m && j < n; i++){
            if(nums2[j] <= nums1[i]){ //element of 2nd array is smaller than element of 1st array.
                for(int k = m; k > i; k--){ //moving items
                    nums1[k] = nums1[k - 1];
                    }
                nums1[i] = nums2[j];
                j++;
                m++;
            }
        }
        while(j < n){
            nums1[i] = nums2[j];
            i++;
            j++;
        }       
    }
}    

int main(){
    int nums1Size = 3;
    int nums2Size = 3;
    int m = 3;
    int n = 3;
    int *arr1 = (int *)malloc((9) *sizeof(int));
    arr1[0] = 1;
    arr1[1] = 2;
    arr1[2] = 3;
    arr1[3] = 0;
    arr1[4] = 0;
    arr1[5] = 0;
    int arr2[3] = {2, 5, 6};

    merge(arr1, nums1Size, m, arr2, nums2Size, n);

    for(int i = 0; i < m + n; i ++){
        printf("%d,", arr1[i]);
    }
    printf("\n");
    nums1Size = 1;
    nums2Size = 1;
    m = 1;
    n = 1;
    arr1 = (int *)malloc((2) *sizeof(int));
    arr1[0] = 1;
    arr1[1] = 0;
    int arr3[1] = {2};

    merge(arr1, nums1Size, m, arr3, nums2Size, n);

    for(int i = 0; i < m + n; i ++){
        printf("%d,", arr1[i]);
    }
    return 0;
}
