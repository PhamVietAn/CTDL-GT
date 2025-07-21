#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
    char name[20];
    int id;
}Student;

typedef struct Node {
    Student data;
    struct Node *left;
    struct Node *right;
}Node;

Node *createNode(Student data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->left = NULL;
    node->right = NULL;

}