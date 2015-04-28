#include "queue.h"
#include "stack.h"
#include "graph.h"
#include "myHW.h"

/*
if V<<E use matrix
else if V>>E use list

prim/Kruskal
Djisktra/Fleury
*/

int main()
{
    FILE * f = fopen("matrix.txt","r");
    readFromAdjMatrix(f);
    printAdjMatrix();
    adjList = createListFromMatrix();
    printList(adjList);
    bfs(0);
    printf("\n");
    dfs(0);
    printf("\n");
    dfsRecurs(0);
    printf("\n\n");
    int** a = createMatrixFromList(adjList);
    //print matrix
    for (int i = 0; i < nrOfVerteces; i++) {
        for (int j = 0; j < nrOfVerteces; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    //
    //longestPath(0, 1);
    return 0;
}
