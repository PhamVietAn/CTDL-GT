#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL 200

// Cấu trúc 1 node stack
typedef struct Node {
    char url[MAX_URL];
    struct Node *next;
} Node;

Node *backStack = NULL;
Node *forwardStack = NULL;

// Hàm tạo node mới
Node* createNode(char *url) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->url, url);
    newNode->next = NULL;
    return newNode;
}

// Đẩy vào stack
void push(Node **stack, char *url) {
    Node *newNode = createNode(url);
    newNode->next = *stack;
    *stack = newNode;
}

// Lấy ra khỏi stack
char* pop(Node **stack) {
    if (*stack == NULL) return NULL;
    Node *temp = *stack;
    char *url = (char*)malloc(MAX_URL);
    strcpy(url, temp->url);
    *stack = temp->next;
    free(temp);
    return url;
}

// Lấy phần tử đầu nhưng không xoá
char* peek(Node *stack) {
    return stack ? stack->url : NULL;
}

// Giải phóng toàn bộ stack
void clearStack(Node **stack) {
    while (*stack != NULL) {
        Node *temp = *stack;
        *stack = temp->next;
        free(temp);
    }
}

// Lệnh VISIT
void visit(char *url) {
    if (peek(backStack)) {
        push(&backStack, url);
    } else {
        // Nếu chưa có trang nào, là lần đầu truy cập
        backStack = createNode(url);
    }
    clearStack(&forwardStack);
    printf("Truy cap: %s\n", url);
}

// Lệnh BACKWARD
void goBack() {
    if (backStack == NULL || backStack->next == NULL) {
        printf("Khong the quay lai.\n");
        return;
    }
    char *current = pop(&backStack);
    push(&forwardStack, current);
    free(current);
    printf("Dang o trang truoc: %s\n", peek(backStack));
}

// Lệnh FORWARD
void goForward() {
    if (forwardStack == NULL) {
        printf("Khong the tien toi.\n");
        return;
    }
    char *url = pop(&forwardStack);
    push(&backStack, url);
    printf("Quay lai trang sau: %s\n", url);
    free(url);
}

// Lệnh CURRENT
void currentPage() {
    char *url = peek(backStack);
    if (url) {
        printf("Trang hien tai: %s\n", url);
    } else {
        printf("Chua co trang web nao duoc truy cap.\n");
    }
}

// Hàm chính
int main() {
    char command[256];

    printf("——————————— WEB HISTORY ———————————\n");
    printf("Cac lenh: VISIT <url>, BACKWARD, FORWARD, CURRENT, THOAT\n");

    while (1) {
        printf("\nNhap lenh: ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0;

        if (strncmp(command, "VISIT ", 6) == 0) {
            char *url = command + 6;
            visit(url);
        } else if (strcmp(command, "BACKWARD") == 0) {
            goBack();
        } else if (strcmp(command, "FORWARD") == 0) {
            goForward();
        } else if (strcmp(command, "CURRENT") == 0) {
            currentPage();
        } else if (strcmp(command, "THOAT") == 0) {
            printf("Dang thoat chuong trinh.\n");
            break;
        } else {
            printf("Lenh khong hop le.\n");
        }
    }

    // Giải phóng bộ nhớ
    clearStack(&backStack);
    clearStack(&forwardStack);

    return 0;
}
