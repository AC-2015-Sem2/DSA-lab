#include "queue.h"
#include "stack.h"
#include "graph.h"

int main()
{
    FILE * f = fopen("matrix.txt","r");
    readFromAdjMatrix(f);

    ///traversals using the matrix
    getNumberOfNeighborsOfVertex=&getNumberOfNeighborsOfVertexM;
    getAllNeighborsOfVertex=&getAllNeighborsOfVertexM;
    printf("\nTraversals using the matrix (before)\n");
    bfs(0);
    dfs(0);
    dfsRecurs(0);

    ///computing the array of adjacency lists from the adjacency matrix
    adjArray=fromMatrixToList(adjMatrix);
    ///traversals using the adjacency list
    getNumberOfNeighborsOfVertex=&getNumberOfNeighborsOfVertexL;
    getAllNeighborsOfVertex=&getAllNeighborsOfVertexL;
    printf("\nTraversals using the adjacency list\n");
    bfs(0);
    dfs(0);
    dfsRecurs(0);

    ///computing the the adjacency matrix from the array of adjacency lists
    fromAdjListToMatrix(adjArray);
    ///traversals, once again
    getNumberOfNeighborsOfVertex=&getNumberOfNeighborsOfVertexM;
    getAllNeighborsOfVertex=&getAllNeighborsOfVertexM;
    printf("\nTraversals using the matrix (after)\n");
    bfs(0);
    dfs(0);
    dfsRecurs(0);
    return 0;
}
