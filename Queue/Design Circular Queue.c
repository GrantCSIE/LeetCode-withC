#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE (1001)

typedef struct {
    int queue[MAX_SIZE];
    int front;
    int back;
    int size;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* Q = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    Q->size = k + 1;
    for(int i = 0; i < (Q->size); i++){
        Q->queue[i] = -1;
    }
    Q->front = 0;
    Q->back = 0;
    return Q;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if(((obj->back) + 1) % (obj->size) == (obj->front)){
        return false;
    }
    else{
        obj->back = ((obj->back) + 1) % (obj->size);
        obj->queue[obj->back] = value;
    }
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(obj->front == obj->back){
        return false;
    }
    else{
        obj->front = ((obj->front) + 1) % obj->size;
    }
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if(obj->front == obj->back){
        return -1;
    }
    else{
        return obj->queue[((obj->front) + 1) % obj->size];
    }
    return -1;
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if(obj->front == obj->back){
        return -1;
    } 
    else{
        return obj->queue[obj->back];
    }
    return -1;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return (obj->front == obj->back) ? true: false;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return ((((obj->back) + 1) % obj->size) == obj->front) ? true : false;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);

 test case:
 ["MyCircularQueue","enQueue","enQueue","enQueue","enQueue","Rear","isFull","deQueue","enQueue","Rear"]
 [[3],[1],[2],[3],[4],[],[],[],[4],[]]

 output:
 1,1,1,0,3,1,1,1,4
*/

int main(){
    int k = 3;
    MyCircularQueue* obj = myCircularQueueCreate(k);
    bool param_1 = myCircularQueueEnQueue(obj, 1);

    bool param_2 = myCircularQueueEnQueue(obj, 2);

    bool param_3 = myCircularQueueEnQueue(obj, 3);

    bool param_4 = myCircularQueueEnQueue(obj, 4);

    int param_5 = myCircularQueueRear(obj);

    bool param_6 = myCircularQueueIsFull(obj);
 
    bool param_7 = myCircularQueueDeQueue(obj);

    bool param_8 = myCircularQueueEnQueue(obj, 4);

    int param_9 = myCircularQueueRear(obj);
 
    myCircularQueueFree(obj);

    printf("%d,%d,%d,%d,%d,%d,%d,%d,%d", param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9);
    return 0;
}
