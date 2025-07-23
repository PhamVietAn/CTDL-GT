#include <stdio.h>

void addEdge(int graph[3][3], int startNode, int endNode) {
    graph[startNode][endNode] = 1;
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

    int startNode = 1;
    int endNode = 2;

    addEdge(graph, startNode, endNode);

    printf("Ma tran ke cua do thi co huong:\n");
    printGraph(graph);

    return 0;
}
