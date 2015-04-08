#include "AVL_tree.h"

int main()
{
    cmpContents = &cmpIntegerContents;

    // getContent = &getStringContent;
    getContent = &getIntegerContent;

        // printElement = &printStringElement;
    printElement = &printIntegerElement;

    // NodeT * root = createBinTree();
    //NodeT * root = createStaticBinTree();

    int a[] = {1, 2, 3, 7, 12, 14, 90}, i;
    NodeT *newNode, *root = NULL;

    for (i = 0; i < 7; i++) {
        printf("insert: %d\n", *(a+i));
        newNode = createNode((void*)(*(a+i)));
        root = insertIn(root, newNode);
        prettyPrint(root, 0);
        printf("\n\n");
    }
    newNode = createNode((void*)12);
    root = remFrom(root, newNode);
    prettyPrint(root, 0);
    return 0;
}
