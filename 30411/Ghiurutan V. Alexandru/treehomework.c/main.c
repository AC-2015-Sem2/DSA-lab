#include "Header.h"
int main()
{
    NodeT *root=createBinTree();
    NodeL *firstFromList=createListFromTree(root);
    traverseList(firstFromList);
    root=getTreeFromList();
    prettyPrint(root,0);
    return 0;
}
