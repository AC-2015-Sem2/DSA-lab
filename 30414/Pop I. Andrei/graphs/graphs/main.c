# include "functions.h"

int main()
{
   FILE *in = fopen("input.txt", "r");
   int *path = (int*) malloc(100 * sizeof(int)), pathSize = 0;

    readMatrix(in);
    matrixToList();
    printList();
    listToMatrix();
    printMatrix();
    matrixToList();
    printList();
    listToMatrix();
    printMatrix();

    bfsOnLists(0);
    dfsOnLists(0);

    path = findPath(0);

    return 0;
}
