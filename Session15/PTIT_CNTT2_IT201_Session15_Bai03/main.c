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

void printQueue(Queue* q) {
    printf("queue = {\n");
    printf("  array = [");
    for (int i = 0; i <= q->rear; i++) {
        printf("%d", q->array[i]);
        if (i < q->rear) printf(", ");
    }
    printf("],\n");
    printf("  front = %d,\n", q->front);
    printf("  rear = %d,\n", q->rear);
    printf("  capacity = %d\n", q->capacity);
    printf("}\n");
}

bool isEmpty(Queue* q) {
    return q->rear == -1;
}

int main(void) {
    Queue q1 = initQueue(5);
    Queue q2 = initQueue(5);

    q2.rear = 2;
    q2.array[0] = 1;
    q2.array[1] = 2;
    q2.array[2] = 5;

    printf("q1 empty? %s\n", isEmpty(&q1) ? "true" : "false");
    printf("q2 empty? %s\n", isEmpty(&q2) ? "true" : "false");

    return 0;
}
