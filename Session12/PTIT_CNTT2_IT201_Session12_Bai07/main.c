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

void sortListAscending(Node* head) {
    if (head == NULL) return;

    int swap;
    Node *ptr1;
    Node *ptr2 = NULL;

    do {
        swap = 0;
        ptr1 = head;

        while (ptr1->next != ptr2) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swap = 1;
            }
            ptr1 = ptr1->next;
        }
        ptr2 = ptr1;
    }while (swap);
}

void sortListDescending(Node* head) {
    if (head == NULL) return;

    int swap;
    Node *ptr1;
    Node *ptr2 = NULL;

    do {
        swap = 0;
        ptr1 = head;

        while (ptr1->next != ptr2) {
            if (ptr1->data < ptr1->next->data) { // đảo chiều so với tăng dần
                // Hoán đổi giá trị data
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swap = 1;
            }
            ptr1 = ptr1->next;
        }
        ptr2 = ptr1;
    } while (swap);
}

int main(void) {
    Node* head = NULL;

    head = createNode(head, 1);
    head = createNode(head, 5);
    head = createNode(head, 2);
    head = createNode(head, 4);
    head = createNode(head, 3);

    printf("danh sach ban dau: ");
    printList(head);

    int choice;
    printf("[1] Sap xep tang dan\n[2] Sap xep giam dan");
    printf("\nLua chon: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            sortListAscending(head);
            break;
        case 2:
            sortListDescending(head);
            break;
        default:
            printf("Lua chon khong hop le\n");
            break;

    }

    printf("danh sach sau sap xep: ");
    printList(head);
    return 0;
}