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

Node* deleteByValue(Node* head, int value) {
    Node* curr = head;
    while (curr != NULL) {
        if (curr->data == value) {
            Node* toDelete = curr;

            if (curr->prev != NULL) {
                curr->prev->next = curr->next;
            } else {
                head = curr->next;
            }
            if (curr->next != NULL) {
                curr->next->prev = curr->prev;
            }
            curr = curr->next;
            free(toDelete);
        } else {
            curr = curr->next;
        }
    }
    return head;
}

int main(void) {
    Node* head = NULL;

    head = createNode(head, 5);
    head = createNode(head, 4);
    head = createNode(head, 3);
    head = createNode(head, 5);
    head = createNode(head, 2);
    head = createNode(head, 1);

    printf("danh sach ban dau: ");
    printList(head);

    int value;
    printf("Nhap phan tu muon xoa: ");
    scanf("%d", &value);
    head = deleteByValue(head, value);
    printf("danh sach sau khi xoa: ");
    printList(head);
    return 0;
}