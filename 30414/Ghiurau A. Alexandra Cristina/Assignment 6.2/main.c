#include "graphRepresentation.h"
#include "graphTraversals.h"
#include "graphAlgorithms.h"

int main()
{
    FILE * f = fopen("matrix.txt","r");
    readFromAdjMatrix(f);
    printAdjMatrix();
    initRand();

    bfs(0);
    dfs(0);
    dfsRecurs(0);

    prim(0);
    dijkstra(0);
    bellmanFord(0);
    kruskal();

    vertexCover(adjMatrix);

    return 0;
}
