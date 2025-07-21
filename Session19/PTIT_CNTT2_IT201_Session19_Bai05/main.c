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

bool findValueDFS(Node* root, int target) {
    if (root == NULL) return false;
    if (root->data == target) return true;

    if (findValueDFS(root->left, target)) return true;

    return findValueDFS(root->right, target);
}

int main() {
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    int findVal;
    printf("Find Value: ");
    scanf("%d", &findVal);
    bool found = findValueDFS(root, findVal);

    if (found)
        printf("true\n");
    else
        printf("false\n");

    free(root->left->left);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
