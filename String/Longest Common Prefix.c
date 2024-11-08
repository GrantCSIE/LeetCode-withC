#include <stdio.h>
#include <stdlib.h>

#define MIN(a, b) ((a) < (b)) ? (a) : (b)

int strlen(char *s){
    int count = 0;
    char *tmp = s;
    while(*tmp != '\0'){
        tmp ++;
        count ++;
    }
    return count;
}

char* longestCommonPrefix(char** strs, int strsSize) {
    int min_len = strlen(strs[0]);
    for(int i = 1; i < strsSize; i++){
        min_len = MIN(min_len, strlen(strs[i]));
    }
    char *common = (char*)calloc((min_len + 1), sizeof(char));
    
    for(int j = 0; j < min_len; j++){ //find each char among strings
        char tmp = strs[0][j];
        for(int i = 1; i < strsSize; i++){ // iterate from first string to last string
            if(tmp != strs[i][j]){
                return common;
            }
        }
        common[j] = tmp;
    }
    return common;
}
