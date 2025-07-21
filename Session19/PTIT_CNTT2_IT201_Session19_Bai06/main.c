#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Khong the cap phat bo nho.\n");
        exit(1);
    }

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

typedef struct QueueNode {
    Node* treeNode;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
} Queue;

void initQueue(Queue* q) {
    q->front = q->rear = NULL;
}

bool isEmpty(Queue* q) {
    return q->front == NULL;
}

void enqueue(Queue* q, Node* treeNode) {
    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
    temp->treeNode = treeNode;
    temp->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
}

Node* dequeue(Queue* q) {
    if (isEmpty(q)) return NULL;

    QueueNode* temp = q->front;
    Node* treeNode = temp->treeNode;
    q->front = q->front->next;

    if (q->front == NULL) q->rear = NULL;

    free(temp);
    return treeNode;
}

bool findValueBFS(Node* root, int target) {
    if (root == NULL) return false;

    Queue q;
    initQueue(&q);
    enqueue(&q, root);

    while (!isEmpty(&q)) {
        Node* current = dequeue(&q);
        if (current->data == target) return true;

        if (current->left) enqueue(&q, current->left);
        if (current->right) enqueue(&q, current->right);
    }

    return false;
}

int main() {
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    int findVal;
    printf("Find Val: ");
    scanf("%d", &findVal);
    bool found = findValueBFS(root, findVal);

    printf(found ? "true\n" : "false\n");

    free(root->left->left);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
