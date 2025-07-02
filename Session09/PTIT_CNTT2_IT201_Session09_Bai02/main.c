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

int main(void) {
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    Node* temp = head;
    int counter = 1;
    while (temp != NULL) {
        printf("Node %d: %d\n", counter, temp->data);
        temp = temp->next;
        counter++;
    }

    temp = head;
    while (temp != NULL) {
        Node* current = temp;
        temp = temp->next;
        free(current);
    }
    return 0;
}