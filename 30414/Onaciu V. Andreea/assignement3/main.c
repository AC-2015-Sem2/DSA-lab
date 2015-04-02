#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
int main()
{
    nodeT *root=createStaticBinTree();
    nodeL *head=createListFromTree(root);
    printf("The list from the tree:\n");
    printAll(head);
    printf("The tree from the list:\n");
    root=createTreeFromList();
    //inorder(root);
    prettyPrint(root,0);
    return 0;
}
