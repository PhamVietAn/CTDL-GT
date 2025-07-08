#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100

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

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return s->data[(s->top)--];
}
char peak(Stack *s) {
    if (isEmpty(s)) {
        return s->data[(s->top)];
    }
    return '\0';
}

bool isMatching(char open, char close) {
    return (open == '(' && close == ')')|| (open == '[' && close == ']')|| (open == '{' && close == '}') || (open == '[' && close == ']');
}

bool isBracket(char* expr) {
    Stack s;
    init(&s);

    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];

        if (ch == '(' || ch == '[' || ch == '{') {
            push(&s, ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (isEmpty(&s)) {
                return false;
            }
            char open = pop(&s);
            if (!isMatching(open, ch)) {
                return false;
            }
        }
    }
    return isEmpty(&s);
}


int main(void) {
    char str[MAX];

    printf("Enter string: ");
    fgets(str, MAX, stdin);
    str[strcspn(str, "\n")] = '\0';

    if (isBracket(str)) {
        printf("true");
    } else {
        printf("false");
    }



    return 0;
}