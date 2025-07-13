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

void peek(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("queue is empty\n");
    } else {
        printf("%d\n", q->front->data);
    }
}

void deQueue(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("queue is empty\n");
        return;
    }

    Node *temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
}

int main() {
    Queue q;
    initQueue(&q);
    deQueue(&q);

    enQueue(&q, 1);
    enQueue(&q, 2);
    enQueue(&q, 5);

    deQueue(&q);

    Node *cur = q.front;
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }

    return 0;
}
