#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listFunctions.h"
#include "treeFunctions.h"

int main()
{
    f = fopen("input.dat", "r");

    nodeT* root = createBinaryTree();
    nodeL* firstFromList = getListFromTree(root);
    root = getTreeFromList(firstFromList);

    printList(firstFromList);
    printf("\n\n\n");
    prettyPrint(root, 0);

    fclose(f);
    return 0;
}
