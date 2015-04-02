# include "tree.h"

int main()
{
    NodeT *root = createBinaryTree();
    NodeL *first = getList(root);
    traverseList(first);
    root=getFromList(&first);
    prettyPrint(root, 0);

    return 0;
}
