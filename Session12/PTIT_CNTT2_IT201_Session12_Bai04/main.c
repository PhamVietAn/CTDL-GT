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

Node* deleteHead(Node* head) {
    if (head == NULL) return NULL;
    Node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
    return head;
}

Node* deleteTail(Node* head) {
    if (head == NULL) return NULL;

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    free(temp);
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

    int choice;
    printf("[1] Xoa phan tu o dau\n[2] Xoa phan tu o cuoi\n");
    printf("Nhap lua chon: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            head = deleteHead(head);
            break;

        case 2:
            head =deleteTail(head);
            break;

        default:
            printf("Lua chon khong hop le");
    }
    printf("danh sach sau khi xoa:");
    printList(head);


    return 0;
}