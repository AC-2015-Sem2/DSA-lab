#include "queue.h"
#include "stack.h"
#include "graph.h"

int main()
{
    FILE * f = fopen("matrix.txt","r");
    readFromAdjMatrix(f);
    printAdjMatrix(adjMatrix);

    int n = getNumberOfNeighborsOfVertex(4);
    int* v = getAllNeighborsOfVertex(4);
    int i;
    printf("\nNeighbors of E:\n");
    for (i = 0; i < n; i++) {
        printf("%c ", v[i] + 65);
    }
    printf("\n\n");

    createAdjLists(adjMatrix);
    printAdjLists();

    bfs(0);
    dfs(0);
    dfsRecurs(0);

    int** newAdjMatr = createAdjMatrixFromLists(adjLists, adjListLengths);
    printAdjMatrix(newAdjMatr);

    char* c = longestSimplePath();
    printf("\nLongest simple path:%s\n", c);
    return 0;
}
