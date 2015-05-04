#include "graphRepresentation.h"
#include "graphTraversals.h"
#include "graphAlgorithms.h"

int main()
{
    FILE * f = fopen("matrix.txt","r");
    readFromAdjMatrix(f);
    printAdjMatrix();
    bfs(0);
    dfs(0);
    dfsRecurs(0);
    prim(0);
    kruskal();
    dijkstra(0);
    int ok=BellmanFord(0);
    ok?printf("The graph contains no negative weight cycle\n"):printf("The graph contains negative weight cycle\n");
    return 0;
}
