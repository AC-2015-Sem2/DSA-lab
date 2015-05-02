# include "functions.h"

int main()
{
   FILE *f=fopen("input.txt", "r");
    readMatrix(f);
    printMatrix();
    matrixToList();
    printList();
    listToMatrix();
    printMatrix();
    bfsOnLists(0);
    dfsOnLists(0);
    fclose(f);


    return 0;
}
