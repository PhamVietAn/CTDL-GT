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

int deQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("queue is empty\n");
        return -1;
    }

    int value = q->array[q->front];
    q->front++;

    if (q->front > q->rear) {
        q->front = 0;
        q->rear = -1;
    }

    return value;
}

int main(void) {
    Queue q = initQueue(5);

    int val1 = deQueue(&q);

    q.array[0] = 1;
    q.array[1] = 2;
    q.array[2] = 5;
    q.rear = 2;

    int val2 = deQueue(&q);
    printf("return value = %d\n", val2);

    printf("queue = { front = %d, rear = %d }\n", q.front, q.rear);

    return 0;
}
