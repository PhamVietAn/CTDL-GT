#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

typedef struct {
    Node *front;
    Node *rear;
}Queue;

void initQueue(Queue *q) {
    q->front = NULL;
    q->rear = NULL;
}

int isQueueEmpty(Queue *q) {
    return q->front == NULL;
}

void enQueue(Queue *q, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Khong the cap phat bo nho");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;

    if (isQueueEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

void displayQueue(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("queue is empty\n");
        return;
    }

    Node *current = q->front;
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}

int main() {
    Queue q;
    initQueue(&q);

    // Trường hợp 1: Hàng đợi rỗng
    displayQueue(&q);

    // Trường hợp 2: Có phần tử
    enQueue(&q, 1);
    enQueue(&q, 2);
    enQueue(&q, 5);

    displayQueue(&q);

    return 0;
}
