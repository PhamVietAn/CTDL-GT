#include <stdio.h>

#define MAX 5

typedef struct {
    int data[MAX];
    int top;
    int cap;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
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
    printf("Stack: ");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}



int main(void) {
    Stack s = {
        .data = {10, 20,30, 40, 50},
        .top = 4,
        .cap = MAX
    };

    printfStack(&s);



    return 0;
}