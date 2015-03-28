#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treeAndList.h"

NodeL *head, *tail, *copyhead;

int main()
{
    getContent = &getStringContent;
    printElement = &printStringElement;

    NodeT * root = createBinTree();
    NodeL * firstFromList = getListFromTree(root);
    copyhead = firstFromList;
    traverse(firstFromList);


    printf("\n--------- START PRETTY PRINT ------------\n\n");
    prettyPrint(root,0);
    printf("\n\n--------- END PRETTY PRINT ------------\n\n");

    root = getTreeFromList();

    printf("\n--------- START PRETTY PRINT ------------\n\n");
    prettyPrint(root,0);
    printf("\n\n--------- END PRETTY PRINT ------------\n\n");

    return 0;
}
