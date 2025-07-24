#include <stdio.h>
#include <stdlib.h>

void addEdge(int** graph, int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

void printGraph(int** graph, int n) {
    printf("Ma tran ke cua do thi:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;

    printf("Nhap so node: ");
    scanf("%d", &n);

    int** graph = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i <= n; i++) {
        graph[i] = (int*)calloc(n, sizeof(int));
    }

    printf("Nhap %d canh theo dinh u v (cach nhau boi dau cach):\n", n);
    for (int i = 0; i <= n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (u >= 0 && u < n && v >= 0 && v < n) {
            addEdge(graph, u, v);
        }
    }

    printGraph(graph, n);

    for (int i = 0; i < n; i++) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}
