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

Node* insertAtTail(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        head = newNode;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

int main(void) {
    Node* head = NULL;

    head = createNode(head, 5);
    head = createNode(head, 4);
    head = createNode(head, 3);
    head = createNode(head, 2);
    head = createNode(head, 1);

    printf("Danh sach ban dau: ");
    printList(head);

    int value;
    printf("Nhap phan tu muon them: ");
    scanf("%d", &value);
    head = insertAtTail(head, value);
    printf("\ndanh sach sau them: ");
    printList(head);


    return 0;
}