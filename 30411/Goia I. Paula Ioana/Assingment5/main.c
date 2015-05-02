#include <stdio.h>
#include <stdlib.h>
#include<stdio.h>
#include "AdjList.h"
#include "graph.h"
#include "stack.h"
#include "queue.h"

int main()
{
    FILE * f = fopen("matrix.txt","r");
    readFromAdjMatrix(f);
    printAdjMatrix();
printf("\n");
    nrOfVerteces=n;
    vertexCount=0;
    fromAdjMatrixToAdjList();
    printf("The Adjacency List Of The Given Graph is : \n");
   printGraph();
   printf("\n");
   fromAdjListToAdjMatrix();
    printf("The Adjacency Matrix resulted from the Adj List is : \n");
    printmatrix();
    printf("\n");
    printf("BFS :\n");
    bfs(0);
    printf("\n");
    printf("DFS :\n");
    dfs(0);
    printf("\n");
    printf("DFS REC :\n");
   dfsRecurs(0);
    return 0;
}
