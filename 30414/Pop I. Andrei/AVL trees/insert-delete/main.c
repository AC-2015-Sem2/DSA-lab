# include "insdelHeader.h"

int main()
{
    NodeT *root = NULL;

    root = insertNode(root,10);
    root = insertNode(root,5);
    root = insertNode(root,15);
    root = insertNode(root,14);
    root = insertNode(root,20);
    root = insertNode(root,1);
    root = insertNode(root,8);
    root = insertNode(root,6);
    root = insertNode(root,7);


    root = deleteNode(root, 15);
    root = deleteNode(root, 14);
    root = deleteNode(root, 20);
    root = deleteNode(root, 1);
    root = deleteNode(root, 7);
    root = deleteNode(root, 8);


    prettyPrint(root, 0);

    return 0;
}
