#include <stdio.h>
#include <stdlib.h>

// Cấu trúc một node trong danh sách kề
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Hàm tạo node mới
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Node** graph, int u, int v) {
    // Thêm v vào danh sách kề của u
    Node* newNode = createNode(v);
    newNode->next = graph[u];
    graph[u] = newNode;

    newNode = createNode(u);
    newNode->next = graph[v];
    graph[v] = newNode;
}

void printGraph(Node** graph, int n) {
    printf("Danh sach ke cua do thi:\n");
    for (int i = 0; i < n; i++) {
        printf("Dinh %d:", i);
        Node* temp = graph[i];
        while (temp) {
            printf(" %d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Nhap so dinh: ");
    scanf("%d", &n);

    Node** graph = (Node**)malloc(n * sizeof(Node*));
    for (int i = 0; i < n; i++) {
        graph[i] = NULL;
    }

    printf("Nhap cac canh u v (ket thuc bang -1 -1):\n");
    while (1) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (u == -1 && v == -1) break;

        if (u >= 0 && u < n && v >= 0 && v < n) {
            addEdge(graph, u, v);
        }
    }

    printGraph(graph, n);

    for (int i = 0; i < n; i++) {
        Node* temp = graph[i];
        while (temp) {
            Node* next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(graph);

    return 0;
}
