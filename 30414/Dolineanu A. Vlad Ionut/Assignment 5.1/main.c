#include "graphRepresentation.h"
#include "graphTraversals.h"
#include "graphAlgorithms.h"
#include "adjacencyList.h"



int main()
{
    FILE * f = fopen("matrix.txt","r");
    readFromAdjMatrix(f);
    printAdjMatrix();
    matrixToList();
    printAdjList();
    listToMatrix();
    printAdjMatrixFromList();
    //bfs(0);
    //dfs(0);
    //dfsRecurs(0);
    //prim(0);
    //kruskal();
    //dijkstra(0);

    return 0;
}
