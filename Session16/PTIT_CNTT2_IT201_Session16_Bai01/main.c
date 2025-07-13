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

int main() {
    Queue q;
    initQueue(&q);

    enQueue(&q, 10);
    enQueue(&q, 20);
    enQueue(&q, 30);

    Node *temp = q.front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}