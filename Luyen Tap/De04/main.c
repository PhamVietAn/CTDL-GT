#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

typedef struct {
    char action;
    char value;
} Operation;

typedef struct {
    Operation data[MAX];
    int top;
} Stack;

char text[MAX];
int len = 0;

Stack undoStack = {.top = -1};
Stack redoStack = {.top = -1};

void push(Stack *s, Operation op) {
    if (s->top < MAX - 1)
        s->data[++s->top] = op;
}

Operation pop(Stack *s) {
    if (s->top >= 0)
        return s->data[s->top--];
    Operation o = {'X', '\0'};
    return o;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void insertChar(char c) {
    text[len++] = c;
    text[len] = '\0';
    Operation op = {'I', c};
    push(&undoStack, op);
    redoStack.top = -1; // clear redo
}

void undo() {
    if (isEmpty(&undoStack)) {
        printf("❌ Khong the undo.\n");
        return;
    }
    Operation op = pop(&undoStack);
    if (len > 0 && op.action == 'I') {
        len--;
        text[len] = '\0';
        push(&redoStack, op);
    }
}

void redo() {
    if (isEmpty(&redoStack)) {
        printf("❌ Khong the redo.\n");
        return;
    }
    Operation op = pop(&redoStack);
    if (op.action == 'I') {
        insertChar(op.value); // also push to undo
        undoStack.top--; // vì insertChar đã push rồi
    }
}

void display() {
    printf("📄 Van ban hien tai: %s\n", text);
}

int main() {
    char cmd[100];
    printf("———————— TEXT EDITOR ————————\n");
    while (1) {
        printf("Nhap lenh (INSERT x / UNDO / REDO / HIEN THI / THOAT): ");
        fgets(cmd, sizeof(cmd), stdin);
        cmd[strcspn(cmd, "\n")] = 0;

        if (strncmp(cmd, "INSERT ", 7) == 0 && strlen(cmd) == 8) {
            insertChar(cmd[7]);
        } else if (strcmp(cmd, "UNDO") == 0) {
            undo();
        } else if (strcmp(cmd, "REDO") == 0) {
            redo();
        } else if (strcmp(cmd, "HIEN THI") == 0) {
            display();
        } else if (strcmp(cmd, "THOAT") == 0) {
            printf("👋 Ket thuc chuong trinh.\n");
            break;
        } else {
            printf("❌ Lenh khong hop le!\n");
        }
    }
    return 0;
}
