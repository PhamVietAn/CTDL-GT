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


int main(void) {
    Stack* stack = CreateStack();

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    free(stack);

    return 0;
}