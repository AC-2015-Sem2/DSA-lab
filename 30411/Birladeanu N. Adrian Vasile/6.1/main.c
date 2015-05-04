#include "graphRepresentation.h"
#include "graphTraversals.h"
#include "graphAlgorithms.h"

int main()
{
    FILE * f1 = fopen("matrix.txt","r");
    readFromAdjMatrix(f1);
    printAdjMatrix();
    //bfs(0);
    //dfs(0);
    //dfsRecurs(0);
    printf("\n");
    kruskal();
    //printf("\n");
    //prim(0);
    printf("\n");
    bellmanFord();
    printf("\n");
    return 0;
}
