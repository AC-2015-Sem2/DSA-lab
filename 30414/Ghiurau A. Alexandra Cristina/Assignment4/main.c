#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int main()
{
    NodeT *root = createBinTree();
    postOrder(root);
    printf("\n");
    root = insert(root, 17);
    prettyPrint(root,0);
    //testing out
    root = insert(root, 17);
    root = insert(root, 18);
    root = insert(root, 19);
    root = insert(root, 20);
    root = insert(root, 21);
    root = insert(root, 22);
    root = insert(root, 23);
    root = insert(root, 24);

    prettyPrint(root,0);
    return 0;
}
