#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;

void initQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
}

void enqueue(Queue* q, int value) {
    if (q->rear < MAX_SIZE - 1) {
        q->rear++;
        q->data[q->rear] = value;
    }
}

int dequeue(Queue* q) {
    return q->data[q->front++];
}

bool isEmpty(Queue* q) {
    return q->front > q->rear;
}

bool isIncreasingByOne(Queue* q) {
    while (q->rear - q->front >= 1) {
        int first = dequeue(q);
        int second = q->data[q->front];
        if (second - first != 1) {
            return false;
        }
    }
    return true;
}

int main() {
    Queue q;
    initQueue(&q);

    int n, x;
    printf("Nhap so phan tu: ");
    scanf("%d", &n);

    printf("Nhap %d so nguyen duong:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(&q, x);
    }

    if (isIncreasingByOne(&q)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    return 0;
}
