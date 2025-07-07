#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
}Node;

Node* createNode(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;
    newNode->prev = NULL;
    if (head != NULL) {
        head->prev = newNode;
    }
    return newNode;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

Node* findMiddle(Node* head, int* pos) {
    if (head == NULL) return NULL;
    Node* shortt = head;
    Node* longg = head;
    *pos = 1;

    while (longg != NULL && longg->next != NULL) {
        shortt = shortt->next;
        longg = longg->next->next;
        (*pos)++;
    }
    return shortt;
}

int main(void) {
    Node* head = NULL;

    head = createNode(head, 6);
    head = createNode(head, 1);
    head = createNode(head, 2);
    head = createNode(head, 3);
    head = createNode(head, 4);
    head = createNode(head, 5);

    printf("danh sach ban dau: ");
    printList(head);

    int pos ;
    Node* middle = findMiddle(head, &pos);
    printf("Node %d: %d", pos, middle->data);
    return 0;
}