
//
// Created by DELL on 7/21/2025.
//
#include <stdio.h>
#include <stdlib.h>

// Cấu trúc node của cây nhị phân
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Tạo node mới
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
// Queue dùng cho BFS
#define MAX_QUEUE 100

typedef struct Queue {
    Node* items[MAX_QUEUE];
    int front;// chỉ số phần tử đầu hàng đợi
    int rear;// chỉ số phần tử cuối hàng đợi
} Queue;

// KHỞI TẠO
void initQueue(Queue* q) {
    q->front=0;
    q->rear = 0;
}

// THÊM NODE
void enqueue(Queue* q, Node* node) {
    // KIỂM TRA HÀNG ĐỢI ĐẦY HAY CHƯA
    if (q->rear < MAX_QUEUE) {
        q->items[q->rear++] = node;
        // THÊM GIÁ TRỊ VÀ TĂNG REAR THÊM 1 ĐƠN VỊ
    }
}

// LẤY NODE KHỎI QUEUE
Node* dequeue(Queue* q) {
    // KIỂM TRA HÀNG ĐỢI CÓ RỖNG HAY KHÔNG
    if (q->front < q->rear) {
        return q->items[q->front++];
    }
    return NULL;
}

// KIỂM TRA QUEUE
int isEmpty(Queue* q) {
    return q->front == q->rear;
}
void levelOrder(Node* root) {
    if (root == NULL) return;
    Queue q;
    initQueue(&q);
    enqueue(&q, root);
    while (!isEmpty(&q)) {
        Node* current = dequeue(&q);
        printf("%d ", current->data);
        if (current->left != NULL)
            enqueue(&q, current->left);
        if (current->right != NULL)
            enqueue(&q, current->right);
    }
}
int main() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    printf("Duyet theo chieu rong  ");
    levelOrder(root);
    return 0;
}
