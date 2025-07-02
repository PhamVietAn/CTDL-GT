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

void deleteNode(Node** head, int position) {
    if (*head == NULL) {
        printf("danh sach rong");
        return;
    }
    Node* temp = *head;
    Node* prev = NULL;

    if (position == 1) {
        *head = temp->next;
        free(temp);
        printf("Da xoa phan tu o vi tri %d\n", position);
        return;
    }

    for (int i = 1; i < position && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (prev == NULL) {
        printf("Vi tri khong ton tai");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Da xoa phan tu o vi tri %d\n", position);
}


int main(void) {
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    int position;
    printf("Danh sach ban dau: ");
    printList(head);
    printf("\n");

    printf("\nNhap vi tri muon xoa: ");
    scanf("%d", &position);

    deleteNode(&head, position);

    printf("Danh sach sau khi xoa: ");
    printList(head);

    Node* temp = head;
    while (temp != NULL) {
        Node* current = temp;
        temp = temp->next;
        free(current);
    }
    return 0;
}