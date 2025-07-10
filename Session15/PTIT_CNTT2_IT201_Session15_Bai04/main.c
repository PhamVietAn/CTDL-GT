#include <stdio.h>
#include <stdbool.h>
#define MAX 5

typedef struct {
    int array[MAX];
    int front;
    int rear;
    int capacity;
} Queue;

Queue initQueue(int size) {
    Queue q;
    q.front = 0;
    q.rear = -1;
    q.capacity = size;
    return q;
}

bool isEmpty(Queue* q) {
    return q->rear == -1;
}

void printQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("queue is empty\n");
        return;
    }

    for (int i = q->front; i <= q->rear; i++) {
        printf("%d\n", q->array[i]);
    }
}


int main(void) {

    Queue q = initQueue(5);

    printQueue(&q);

    // q.array[0] = 1;
    // q.array[1] = 2;
    // q.array[2] = 5;
    // q.rear = 2;
    //
    // printQueue(&q);

    return 0;
}
