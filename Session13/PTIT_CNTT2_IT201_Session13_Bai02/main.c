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
    printf("Stack: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

int main(void) {
    Stack s;
    init(&s);

    int value;
    for (int i = 0; i < 5; i++) {
        printf("[%d]: ",i+1);
        scanf("%d", &value);
        push(&s, value);
    }

    printfStack(&s);
    printf("Top: %d\n", s.top);
    printf("Cap: %d\n", MAX);


    return 0;
}