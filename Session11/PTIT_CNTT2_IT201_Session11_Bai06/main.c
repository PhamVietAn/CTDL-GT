#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
}Node;

Node* createNode(Node* head,int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (head == NULL) return newNode;
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d <=> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

Node* deleteNode(Node* head) {
    if (head == NULL) return head;
    Node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
    return head;
}

int main(void) {
    Node* head = NULL;
    head = createNode(head,1);
    head = createNode(head,2);
    head = createNode(head,3);
    head = createNode(head,4);
    head = createNode(head,5);
    printf("before: ");
    printList(head);
    printf("\nafter: ");
    head = deleteNode(head);
    printList(head);
    return 0;
}