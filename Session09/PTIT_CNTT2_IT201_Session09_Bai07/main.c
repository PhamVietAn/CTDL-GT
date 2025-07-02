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

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void addList(Node** head, int value, int position) {
    Node* newNode = createNode(value);
    if (position <=1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    Node* temp = *head;
    for (int i = 0; temp!=NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Vi tri vuot qua danh sach\n");
        if (*head == NULL) {
            *head = newNode;
        } else {
            Node* current = *head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

int main(void) {
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    int value, position;
    printf("Danh sach ban dau: ");
    printList(head);
    printf("\n");

    printf("nhap phan tu muon them: ");
    scanf("%d", &value);

    printf("\nNhap vi tri muon them: ");
    scanf("%d", &position);

    addList(&head, value, position);

    printf("Danh sach sau khi them: ");
    printList(head);

    Node* temp = head;
    while (temp != NULL) {
        Node* current = temp;
        temp = temp->next;
        free(current);
    }
    return 0;
}