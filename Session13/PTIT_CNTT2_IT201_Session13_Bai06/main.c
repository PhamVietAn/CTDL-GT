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

void removeSpace(char* src, char* dest) {
    int count = 0;
    for (int i = 0; src[i] != '\0'; i++) {
        if (src[i] != ' ') {
            dest[count++] = src[i];
        }
    }
    dest[count] = '\0';
}

bool isPalindrome(char* str) {
    char cleaned[MAX];
    removeSpace(str, cleaned);
    Stack s;
    init(&s);

    int len = strlen(cleaned);

    for (int i = 0; i < len / 2; i++) {
        push(&s, cleaned[i]);
    }

    int start = (len % 2 == 0) ? len / 2 : len / 2 + 1;

    for (int i = start; i < len; i++) {
        if (pop(&s) != cleaned[i]) {
            return false;
        }
    }
    return true;
}


int main(void) {
    char str[MAX];

    printf("Enter string: ");
    fgets(str, MAX, stdin);
    str[strcspn(str, "\n")] = '\0';

    if (isPalindrome(str)) {
        printf("true");
    } else {
        printf("false");
    }



    return 0;
}