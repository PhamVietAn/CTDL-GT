#include <stdio.h>

#define MAX 5

typedef struct {
    int data[MAX];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack is full!\n");
        return;
    } else {
        s->data[++(s->top)] = value;
    }
}

void printfStack(Stack* s) {
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->data[i]);
    }
}

int main(void) {
    Stack s;
    init(&s);
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);

    printfStack(&s);

    return 0;
}