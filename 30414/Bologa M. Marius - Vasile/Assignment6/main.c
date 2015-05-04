#include "graphRepresentation.h"
#include "graphTraversals.h"
#include "graphAlgorithms.h"
#include "matrixtolistandviceversa.h"

int main()
{

    FILE * f = fopen("matrix.txt","r");
    readFromAdjMatrix(f);
    printAdjMatrix();
    //bfs(0);
   // dfs(0);
    //dfsRecurs(0);
      Prim(0);
      Kruskal();
      Dijkstra(0);
    //printAdjMatrix();
   // matrixToList();
   // printAList();
    //listToMatrix();
    //printAdjMatrixFromList();
    BellmanFord(0);
    return 0;
}
