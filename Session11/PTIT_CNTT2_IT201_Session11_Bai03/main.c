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

void search(Node* head, int value) {
    Node* temp = head;
    int found = 0, pos = 1;

    while (temp != NULL) {
        if (temp->data == value) {
            printf("True");
            found = 1;
            break;
        }
        temp = temp->next;
        pos++;
    }
    if (!found) {
        printf("False");
    }
}

int main(void) {
    Node* head = NULL;
    head = createNode(head,1);
    head = createNode(head,2);
    head = createNode(head,3);
    head = createNode(head,4);
    head = createNode(head,5);

    printList(head);

    printf("\n");

    int x;
    printf("Nhap so can tim kiem: ");
    scanf("%d",&x);
    search(head,x);

    return 0;
}