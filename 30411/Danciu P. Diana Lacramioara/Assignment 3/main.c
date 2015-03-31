#include "header.h"

int main(void)
{
    TreeT *root1;
    ListT *firstFromList;

    root1 = createBinTree();
    printf("The input tree is : \n");
    prettyPrint(root1, 0);
    firstFromList = getListFromTree(root1);
    printf("The list from the tree is : \n");
    traverseList(firstFromList);
    printf("\n");
    root1 = getTreeFromList(&firstFromList);
    printf("The tree from the list is : \n");
    prettyPrint(root1, 0);
    return 0;
}
