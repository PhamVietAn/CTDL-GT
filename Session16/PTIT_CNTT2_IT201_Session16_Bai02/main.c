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

Node* createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Khong the cap phat bo nho\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;

}

void addQueue(Queue *q, int data) {
    Node *newNode = createNode(data);
    if (newNode == NULL) {
        return;
    }
    if (isQueueEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

void printQueue(Queue *q) {
    Node *temp = q->front;
    printf("queue = {\n   front->");
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n   read->%d->NULL\n}\n",q->rear ? q->rear->data : -1);
}

int main() {
    Queue q;
    initQueue(&q);

    addQueue(&q, 1);
    addQueue(&q, 2);
    addQueue(&q, 3);
    addQueue(&q, 4);

    printQueue(&q);

    addQueue(&q, 5);

    printQueue(&q);

}