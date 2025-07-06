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

int getLength(Node* head) {
    Node* temp = head;
    int len = 0;
    while (temp != NULL) {
        temp = temp->next;
        len++;
    }
    return len;
}

Node* deleteNode(Node* head, int position) {
    int len = getLength(head);
    Node* temp = head;
    if (head == NULL || position <1 || position > len) {
        printf("Vi tri khong hop le");
        return head;
    }

    if (position == 1) {
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
        return head;
    }

    for (int i = 1; i < position; i++) {
        temp = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
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

    printf("Danh sach ban dau: ");
    printList(head);

    int pos;
    printf("\nNhap vi tri muon xoa: ");
    scanf("%d",&pos);

    head = deleteNode(head,pos);

    printf("Danh sach sau khi xoa: ");
    printList(head);
    return 0;
}