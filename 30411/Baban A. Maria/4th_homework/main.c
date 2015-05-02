#include "print.h"
#include "create.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    NodeT *root=createStaticTree();
    AVLTree(root);
    root=insertNode(root,18); //try to add 18;
    root=insertNode(root,5); //try to add 5 and error message: the node already exists (which is ok for my example tree)
    prettyPrint(root,0);
    return 0;
}
