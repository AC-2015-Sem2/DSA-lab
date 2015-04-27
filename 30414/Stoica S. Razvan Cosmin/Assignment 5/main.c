#include "queue.h"
#include "stack.h"
#include "graph.h"
#include "list.h"

int main()
{
    FILE * f = fopen("matrix.txt","r");
    readFromAdjMatrix(f);
    printAdjMatrix();
    adjList=createAdjList();
    printAdjList(adjList);
    bfs(0);
    dfs(0);
    printf("\n");
    printf("DFS Recursive\n");
    dfsRecurs(0);
    printf("\n");
    recreateAdjMatrix();
    printAdjMatrixAfter();
    return 0;
}
