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
    bellman(0);
    kruskal();
    printAdjMatrix();
    dijkstra(0);
    matrixToList();
    printAdjList();
    dfs(0);
    bfs(0);
    dfsRecurs(0);
    listToMatrix();
    printAdjMatrix();
    prim(0);
    dijkstra(0);
    return 0;
}
