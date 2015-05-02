#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
int main()
{
    FILE* f = fopen("matrix.txt", "r");
    int nrVert = 0;
    int** adjMat = NULL;

    readAdjMatrix(f, &nrVert, &adjMat);
    printAdjMatrix(nrVert, adjMat);

    node** adjLst = AdjMatToAdjList(adjMat, nrVert);
    printAdjList(adjLst, nrVert);

    int a = 0;
    int b = 2;
    printf("The longest path from %d to %d(using adjacency matrix):\n", a, b);
    longestPathMat(a, b, adjMat, nrVert);
    printf("The longest path from %d to %d(using adjacency lists):\n", a, b);
    longestPathLst(a, b, adjLst, nrVert);
    return 0;
}
