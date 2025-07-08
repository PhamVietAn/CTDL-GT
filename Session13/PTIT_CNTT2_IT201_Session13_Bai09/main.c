#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

typedef struct {
    char data[MAX][MAX];
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

void push(Stack *s, char *value) {
    if (isFull(s)) {
        printf("Stack is full!\n");
        return;
    } else {
        strcpy(s->data[++(s->top)], value);
    }
}

void pop(Stack *s, char *dest) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        dest[0] = '\0';
        return ;
    }
    strcpy(dest, s->data[(s->top)--]);
}

int Toinfix(char *str, char *result) {
    Stack s;
    init(&s);

    char op1[MAX], op2[MAX], temp[MAX];

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        if (isdigit(ch)) {
            char operand[2] = {ch, '\0'};
            push(&s, operand);
        } else {
            pop(&s, op2);
            pop(&s, op1);
            sprintf(temp, "(%s%c%s)", op1, ch, op2);
            push(&s, temp);
        }
    }
    pop(&s, result);

}

int main(void) {
    char str[MAX], infix[MAX];

    printf("nhap bieu thuc hau to: ");
    scanf("%s", str);

    Toinfix(str, infix);

    printf("%s", infix);


    return 0;
}