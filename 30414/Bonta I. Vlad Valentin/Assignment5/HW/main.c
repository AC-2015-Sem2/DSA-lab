#include "graphRepresentation.h"
#include "graphTraversals.h"
#include "graphAlgorithms.h"
#include "adjacencyList.h"

int main()
{
    FILE * f = fopen("matrix2.txt","r");
    readFromAdjMatrix(f);
    printAdjMatrix();
    matrixToList();
    printAdjList();
    listToMatrix();
    printAdjMatrixFromList();
    return 0;
}
