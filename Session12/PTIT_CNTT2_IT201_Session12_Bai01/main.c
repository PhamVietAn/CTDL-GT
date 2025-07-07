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

int main(void) {
    Node* head = NULL;

    int n;
    printf("So luong phan tu trong danh sach: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int data;
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &data);
        head = createNode(head, data);
    }

    printList(head);
    return 0;
}