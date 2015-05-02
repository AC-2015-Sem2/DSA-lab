#include "queue.h"
#include "stack.h"
#include "graph.h"

int main()
{
    FILE * f = fopen("matrix.txt","r");
    readFromAdjMatrix(f);
    printAdjMatrix();
    matrixToList();
    printAdjList();
    printf("\n");
    bfs(0);
    printf("\n");
    dfs(0);
    printf("\n");
    lBfs(0);
    printf("\n");
    lDfs(0);
    return 0;
}
