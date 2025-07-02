#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

int search(Node *head, int key) {
    Node *current = head;
    while (current != NULL) {
        if (current->data == key) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int main(void) {
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    Node* temp = head;

    int key;
    printf("Nhap phan tu can tim: ");
    scanf("%d", &key);
    if (search(head, key)) {
        printf("True");
    } else {
        printf("False");
    }

    temp = head;
    while (temp != NULL) {
        Node* current = temp;
        temp = temp->next;
        free(current);
    }
    return 0;
}