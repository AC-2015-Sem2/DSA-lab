#include "graphRepresentation.h"
#include "graphTraversals.h"
#include "graphAlgorithms.h"

int main()
{
    FILE * f = fopen("matrix2.txt","r");
    readFromAdjMatrix(f);
    printAdjMatrix();


    bfs(0);
    dfs(0);
    dfsRecurs(0);

    prim(0);
    dijkstra(0);
    bellmanFord(0);
    kruskal();

    return 0;
}
