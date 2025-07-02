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

Node* swapNodes(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node* newHead = head->next;
    Node* curr = head;
    Node* prev = NULL;
    while (curr != NULL && curr->next != NULL) {
        Node* firstNode = curr;
        Node* secondNode = curr->next;
        Node* nextPair = secondNode->next;

        secondNode->next = firstNode;
        firstNode->next = nextPair;

        if (prev != NULL) {
            prev->next = secondNode;
        }
        prev = firstNode;
        curr = nextPair;
    }
    return newHead;
}


int main(void) {
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Danh sach ban dau: ");
    printList(head);
    printf("\n");

    head = swapNodes(head);

    printf("Danh sach sau khi doi vi tri: ");
    printList(head);

    Node* temp = head;
    while (temp != NULL) {
        Node* current = temp;
        temp = temp->next;
        free(current);
    }
    return 0;
}