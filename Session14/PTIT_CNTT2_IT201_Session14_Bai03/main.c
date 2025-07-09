#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* CreateNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

typedef struct {
    Node* top;
} Stack;

Stack* CreateStack() {
    Stack* newStack = (Stack*)malloc(sizeof(Stack));
    if (newStack == NULL) {
        printf("Loi cap phat bo nho cho stack!\n");
        return NULL;
    }
    newStack->top = NULL;
    return newStack;
}

int isEmpty(Stack *s) {
    return s->top == NULL;
}

void push(Stack *s, int value) {
    Node* newNode = CreateNode(value);
    newNode->next = s->top;
    s->top = newNode;
}

void display(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Ngan xep trong.\n");
        return;
    }
    Node* temp = stack->top;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main(void) {
    Stack* stack = CreateStack();

    // push(stack, 5);
    // push(stack, 4);
    // push(stack, 3);
    // push(stack, 2);
    // push(stack, 1);

    display(stack);

    free(stack);

    return 0;
}