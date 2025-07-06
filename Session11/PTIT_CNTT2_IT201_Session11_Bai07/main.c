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

Node* insertNode(Node* head,int value, int position) {
    int length = getLength(head);
    if (position > length + 1 || position < 1) {
        printf("Vi tri khong hop le");
        return head;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;

    if (position == 1) {
        newNode->next = head;
        newNode->prev = NULL;
        if (head != NULL) {
            head->prev = newNode;
        }
        return newNode;
    }

    Node* temp = head;
    for (int i = 0; i < position - 1; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;

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

    int value, pos;
    printf("\nNhap gia tri muon them: ");
    scanf("%d",&value);
    printf("Nhap vi tri muon them: ");
    scanf("%d",&pos);

    head = insertNode(head,value,pos);

    printf("Danh sach sau khi them: ");
    printList(head);
    return 0;
}