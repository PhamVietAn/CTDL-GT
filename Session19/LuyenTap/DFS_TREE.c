//
// Created by DELL on 7/21/2025.
//

#include <stdio.h>
#include <stdlib.h>
// DUYỆT THEO CHIỀU SÂU : DFS
// BƯỚC 1: TẠO CẤU TRÚC NODE
typedef struct Student {
    int id;
    char name[20];
};
typedef  struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;
// Tạo hàm tạo node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    // Kiểm tra cấp phát ô nhớ thành công hay không
    if (newNode == NULL) {
        printf("cap phat khong thanh cong");
        return NULL;
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
// BƯỚC 2: Triển Khai DFS
// CÁCH 1: Dùng inorder (LNR_ LEFT-NODE-RIGHT)
void inorder(Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
// CÁCH 2: DÙNG PREORDER ( NLR_ NODE-LEFT-RIGHT)
void preorder(Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
// CÁCH 3: DÙNG POSTORDER ( LRN_ LEFT-RIGHT-NODE)
void postorder(Node* root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// BƯỚC 3: TẠO CÂY TRIỂN KHAI TRONG MAIN

int main() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    // SAU KHI TẠO CÂY XONG THÌ ĐI DUYỆT
    printf("DUYET CAY THEO INORDER \n");// 4 2 5 1 3
    inorder(root);
    printf("DUYET CAY THEO PREORDER \n");
    preorder(root);

}