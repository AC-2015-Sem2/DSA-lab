#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "matrix.h"
#include "list.h"

int main()
{
    FILE *f=fopen("matrix.txt", "r");
    readFromAdjMatrix(f);
    NodeT** adjList=getListfromMatrix(adjMatrix);
    printList(adjList);
    printf("\nBFS: ");
    bfs(adjList, 0);
    printf("\nDFS: ");
    dfs(adjList, 0);
    printf("\nDFS Rec: ");
    dfsRecurs(0, adjList);
    printMatrix(adjMatrix);
    int** matrix=getMatrixfromList(adjList);
    printMatrix(matrix);
    printf("\n");
    fclose(f);
    return 0;
}
