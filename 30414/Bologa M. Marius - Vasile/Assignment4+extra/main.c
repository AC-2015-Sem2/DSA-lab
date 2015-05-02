#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main()
{
    node *root = NULL;
    root = insertNode(root,1);
    root = insertNode(root,2);
    root = insertNode(root,3);
    root = insertNode(root,4);
    root = insertNode(root,5);
    root = insertNode(root,6);
    root = insertNode(root,7);
    prettyPrint(root, 0);
    root=deleteNode(root,6);
    root=deleteNode(root,1);
    prettyPrint(root, 0);
    return 0;
}




