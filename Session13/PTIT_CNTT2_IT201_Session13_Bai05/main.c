#include <stdio.h>

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

void printfArr(int *arr, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d, ", arr[i]);
    }
    printf("]\n");
}

int reverse(int arr[], int n) {
    Stack s;
    init(&s);

    for (int i = 0; i < n; i++) {
        push(&s, arr[i]);
    }

    for (int i = 0; i < n; i++) {
        arr[i] = pop(&s);
    }
}

int main(void) {
    int arr[MAX], n;

    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("[%d]", i);
        scanf("%d", &arr[i]);
    }

    printf("Mang ban dau: ");
    printfArr(arr, n);

    reverse(arr, n);

    printf("\nMang sau sap xep: ");
    printfArr(arr, n);

    return 0;
}