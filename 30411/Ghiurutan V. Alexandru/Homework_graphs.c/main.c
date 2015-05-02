#include "adjListFromMatrix.h"


int main()
{
    readAdjMatrix();
    printAdjMatrix();
    bfs(0);
    dfs(0);
    dfsRecurs(0);
    createAdjList(adjMatrix);
    printAdjList();
    printf("\nTraversals with adjacency list:\n");
    bfsAdj(0);
    dfsAdj(0);
    dfsRecursAdj(0);
    int** newAdjMatr = listToMatrix(adjList, adjListlength);
    printAdjMatrix(newAdjMatr);

    return 0;
}
