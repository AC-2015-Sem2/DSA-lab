#include "trees.h"

int main()
{
    NodeT *root = createBinTree();
    NodeL *firstFromList = getListFromTree(root);

    traverseList(firstFromList);
    root = getTreeFromList(&firstFromList);
    printf("\n");
    prettyPrint(root, 0);
    return 0;
}
