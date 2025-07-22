#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

int findLevel(Node* root, int value, int level) {
    if (root == NULL)
        return 0;

    if (root->data == value)
        return level;

    int leftLevel = findLevel(root->left, value, level + 1);
    if (leftLevel != 0)
        return leftLevel;

    return findLevel(root->right, value, level + 1);
}

int main(void) {
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    int searchValue;
    printf("Nhap gia tri muon tim tang: ");
    scanf("%d", &searchValue);

    int level = findLevel(root, searchValue, 1);

    if (level != 0)
        printf("Gia tri %d nam o tang %d\n", searchValue, level);
    else
        printf("Khong tim thay gia tri %d trong cay\n", searchValue);

    return 0;
}
