#include <stdio.h>

void addEdge(int graph[3][3], int node1, int node2) {
    graph[node1][node2] = 1;
}

void printGraph(int graph[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[3][3] = {0};

    addEdge(graph, 1, 0);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);

    printf("Ma tran ke cua do thi vo huong:\n");
    printGraph(graph);

    return 0;
}
