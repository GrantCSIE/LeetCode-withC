#include <stdio.h>
#include <stdlib.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef struct{
    int min;
    int num; 
    struct Node *next;
}Node;

typedef struct {
    Node *top;
} MinStack;

MinStack* minStackCreate() {
    MinStack *start = (MinStack *)malloc(sizeof(MinStack));
    start->top = NULL;
    return start;
}

void minStackPush(MinStack* obj, int val) {
    Node *new = (Node *)malloc(sizeof(Node));
    new->num = val;
    new->min = (obj->top == NULL) ? val : MIN(val, obj->top->min);
    new->next = obj->top;
    obj->top = new;
}

void minStackPop(MinStack* obj) {
    if((obj->top) != NULL){
        Node *tmp = obj->top;
        obj->top = obj->top->next;
        free(tmp);
    }
}

int minStackTop(MinStack* obj) {
    return obj->top->num;
}

int minStackGetMin(MinStack* obj) {
    return obj->top->min;
}

void minStackFree(MinStack* obj) {
    free(obj);
}


/*
test case: 
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

output:
-3
-2
*/

int main(){
    MinStack* obj = minStackCreate();
    minStackPush(obj, -2);
    minStackPush(obj, 0);
    minStackPush(obj, -3);
    printf("%d\n", minStackGetMin(obj));
    minStackPop(obj);
    minStackTop(obj);
    printf("%d\n",minStackGetMin(obj));
    return 0;
}

