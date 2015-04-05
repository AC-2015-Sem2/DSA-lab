#include <stdio.h>
#include <stdlib.h>

#include "Tree.h"
#include "prettyPrint.h"

Tree* buildTree() {
    Tree* newT = NULL;
    newT = insertLeaf(newT, 0);
    newT = insertLeaf(newT, 1);
    newT = insertLeaf(newT, 2);
    newT = insertLeaf(newT, 3);
    newT = insertLeaf(newT, 4);
    newT = insertLeaf(newT, 5);
    newT = insertLeaf(newT, 6);
    newT = insertLeaf(newT, 7);
    newT = insertLeaf(newT, 8);
    newT = insertLeaf(newT, 9);
    newT = insertLeaf(newT, 10);
    newT = insertLeaf(newT, 11);
    return newT;
}

int main()
{
    Tree* newT = buildTree();
    prettyPrint(newT, 0);
    printf("\n\n\n");
    deleteNode(newT, 9);
    prettyPrint(newT, 0);
    return 0;
}
