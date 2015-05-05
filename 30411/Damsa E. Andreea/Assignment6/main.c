#include "graphRepresentation.h"
#include "graphTraversals.h"
#include "graphAlgorithms.h"
#include "matrixtolistandviceversa.h"

int main()
{

    FILE * f = fopen("matrix.txt","r");
    readFromAdjMatrix(f);
    /*printAdjMatrix();
    bfs(0);
    dfs(0);
    dfsRecurs(0);
    prim(0);
    kruskal();
    dijkstra(0);
     printAdjMatrix();*/
     prim(0);
     dijkstra(0);
    matrixToList();
    printAList();
    listToMatrix();
    BFord(5);
    kruskal();
    printAdjMatrixFromList();
    return 0;
}
