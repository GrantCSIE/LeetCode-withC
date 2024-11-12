#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX(a, b) ((a) > (b)) ? (a) : (b)

/* // logic operation approach.
a b t  result  t+1
0 0 0    0      0
0 0 1    1      0 -> (a' && b' && t) for result
0 1 0    1      0 -> (a' && b && t') for result
0 1 1    0      1 -> (a' && b && t) for t+1
1 0 0    1      0 -> (a && b' && t') for result
1 0 1    0      1 -> (a && b' && t) for t+1
1 1 0    0      1 -> (a && b && t') for t+1
1 1 1    1      1 -> (a && b && t) for t+1 and result

therefore, result can be circulated as (a' && b' && t) || (a' && b && t') || (a && b' && t') || (a && b && t)
            and t+1 can be circulated as (a' && b && t) || (a && b' && t) || (a && b && t') || (a && b && t)
*/
char* addBinary(char* a, char* b) { 
    int len_a = strlen(a);
    int len_b = strlen(b);
    int max = MAX(len_a, len_b);
    char *result = (char *)malloc((max + 1) * sizeof(char));
    result[max] = '\0';
    int tmp = 0;
    int i = len_a - 1;
    int j = len_b - 1;
    while(i >= 0 && j >= 0){
        int x = a[i] - 48;
        int y = b[j] - 48;
        if(len_a <= len_b){
            result[j] = (!x && !y && tmp) || (!x && y && !tmp) || (x && !y && !tmp) || (x && y && tmp);
            result[j] += 48;
        }
        else if(len_a > len_b){
            result[i] = (!x && !y && tmp) || (!x && y && !tmp) || (x && !y && !tmp) || (x && y && tmp);
            result[i] += 48; 
        }
        tmp = (!x && y && tmp) || (x && !y && tmp) || (x && y && !tmp) || (x && y && tmp);
        i -= 1;
        j -= 1;
    }
    while(i >= 0){
        int x = a[i] - '0';
        int y = 0;
        result[i] = (!x && !y && tmp) || (!x && y && !tmp) || (x && !y && !tmp) || (x && y && tmp);
        result[i] += '0';
        tmp = (!x && y && tmp) || (x && !y && tmp) || (x && y && !tmp) || (x && y && tmp);
        i -= 1;
    }
    while(j >= 0){
        int x = 0;
        int y = b[j] - '0';
        result[j] = (!x && !y && tmp) || (!x && y && !tmp) || (x && !y && !tmp) || (x && y && tmp);
        result[j] += '0';
        tmp = (!x && y && tmp) || (x && !y && tmp) || (x && y && !tmp) || (x && y && tmp);
        j -= 1;
    }
    if(tmp == 1){
        char * append = (char *)malloc((max + 2) * sizeof(char));
        for(int i = max + 1; i > 0; i--){
            append[i] = result[i - 1];
        }
        append[0] = '1';
        result = append;
    }
    return result;
}

/* bitwise addition approach
char* addBinary(char* a, char* b) {
    int len1 = strlen(a);
    int len2 = strlen(b);
    int carry = 0 , i = len1-1, j = len2-1;
    int maxlen = len1> len2 ? len1 : len2;
    char *result = (char*)malloc((maxlen +1)*sizeof(char)); 
    result[maxlen] = '\0';
    while (i >= 0 || j >= 0) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';

            carry = sum >> 1; // carry is 1 if sum is 2 or greater, 0 otherwise
            result[--maxlen] = (sum & 1) + '0'; // set the rightmost bit of result to the sum's least significant bit
        }

        if (carry) { // if there is a final carry, prepend it to the result
            result = (char*)realloc(result, (strlen(result) + 2) * sizeof(char)); // reallocate memory for bigger result string
            memmove(result + 1, result, strlen(result) + 1); // shift result string to the right by 1
            result[0] = '1'; // set the leftmost bit to 1
        }

    return result;
}
*/


/* // conversion approach, not suitable for large test case
long bin2dec(char *a){
    long num = 0;
    int len = strlen(a);
    for(int i = 0; i < len; i++){
        num += (a[i] == '1') ? pow(2, len - i - 1) : 0;
    }
    return num;
}

char* dec2bin(long num){
    int len = 0;
    long tmp = num;
    while(tmp > 0){
        tmp = tmp / 2;
        len ++;
    }
    char *s = (char *)malloc((len+1) * sizeof(char));
    s[len] = '\0';
    for(int i = len - 1; i >= 0; i--){
        s[i] = (num % 2 == 0) ? '0' : '1';
        num = num / 2;
    }
    return s;
}

char* addBinary(char* a, char* b) {
    if(*a == '0'){
        return b;
    }
    else if(*b == '0'){
        return a;
    }
    long num_a = bin2dec(a);
    long num_b = bin2dec(b);
    return dec2bin(num_a + num_b);
}
*/


int main(){
    char a[129] = "10100000100100110110010000010101111011011001101110111111111101000000101111001110001111100001101";
    char b[129] = "110101001011101110001111100110001010100001101011101010000011011011001011101111001100000011011110011";
    //char a[129] = "100111";
    //char b[129] = "11100111"; 

    char *c = addBinary(a, b);
    printf("%s", c);
    return 0;
}
//Ans of test case 1: 110111101100010011000101110110100000011101000101011001000011011000001100011110011010010011000000000
//Ans of test case 2: 100001110