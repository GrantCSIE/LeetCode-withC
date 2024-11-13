#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* Two pointer approach

//test case: hannaH, result: Hannah
count   h a n n a H  (no terminated pointer '\0')
        s            
0       e
1         e
2           e
3             e
4               e
5                 e
6 = sSize->stop

        h a n n a H
        s         e -> swap h and H
        H a n n a h
          s     e   -> swap a and a
        H a n n a h
            s e     -> swap n and n
        H a n n a h
            e s     -> s > e, so exit
*/
void swap(char *a, char *b){
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

void reverseString(char* s, int sSize) {
    char *end = s;
    int count = 0;
    while(count != sSize){
        end++;
        count ++;
    }
    end -= 1;
    while(s < end){
        swap(s, end);
        s++;
        end --;
    }
    s = end;
}

int main(){
    char s[100] = {"hannaH"};
    int sSize = strlen(s);
    //printf("%d\n", sSize);
    reverseString(s, sSize);
    printf("%s", s);
    return 0;
}
