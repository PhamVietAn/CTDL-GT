#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void convertMatrixToList(int matrix[100][100], Node* list[], int n) {
    for (int i = 0; i < n; i++) {
        list[i] = NULL;
        for (int j = n - 1; j >= 0; j--) {
            if (matrix[i][j] == 1) {
                Node* newNode = createNode(j);
                newNode->next = list[i];
                list[i] = newNode;
            }
        }
    }
}

void printAdjList(Node* list[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d:", i);
        Node* temp = list[i];
        while (temp) {
            printf(" %d ->", temp->vertex);
            temp = temp->next;
        }
        printf(" NULL\n");
    }
}

int main() {
    int n;
    int matrix[100][100];
    Node* adjList[100];

    printf("Nhap so dinh: ");
    scanf("%d", &n);

    printf("Nhap ma tran ke (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);

    convertMatrixToList(matrix, adjList, n);

    printAdjList(adjList, n);

    for (int i = 0; i < n; i++) {
        Node* temp = adjList[i];
        while (temp) {
            Node* next = temp->next;
            free(temp);
            temp = next;
        }
    }

    return 0;
}
