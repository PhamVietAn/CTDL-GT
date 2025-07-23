#include <stdio.h>

void printAdjacencyMatrix(int matrix[7][7], int size) {
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void printConnections(int matrix[7][7], char vertices[7], int size) {
    printf("\nConnections for each vertex:\n");
    for (int i = 0; i < size; i++) {
        printf("%c: ", vertices[i]);
        for (int j = 0; j < size; j++) {
            if (matrix[i][j]) {  // if there is a connection
                printf("%c ", vertices[j]);
            }
        }
        printf("\n");
    }
}

int main(void) {
    char vertexData[7] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    int adjacencyMatrix[7][7] = {
        {0,0,1,1,1,0,0},
        {0,0,1,0,0,1,0},
        {1,1,0,0,1,1,1},
        {1,0,0,0,0,0,0},
        {1,0,1,0,0,0,0},
        {0,1,1,0,0,0,0},
        {0,0,1,0,0,0,0}

    };

    printf("vertexData: ");
    for (int i = 0; i < 7; i++) {
        printf("%c ", vertexData[i]);
    }
    printf("\n");

    printAdjacencyMatrix(adjacencyMatrix, 7);
    printConnections(adjacencyMatrix, vertexData, 7);
    return 0;
}