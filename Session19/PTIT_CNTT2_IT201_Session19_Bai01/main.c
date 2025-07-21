#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode() {
    int value;
    printf("Nhap gia tri cho node: ");
    scanf("%d", &value);

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

int main() {
    Node *node = createNode();

    printf("node = {\n");
    printf("   data: %d,\n", node->data);
    printf("   left->%s,\n", node->left == NULL ? "NULL" : "NOT NULL");
    printf("   right->%s\n", node->right == NULL ? "NULL" : "NOT NULL");
    printf("}\n");

    free(node);

    return 0;
}