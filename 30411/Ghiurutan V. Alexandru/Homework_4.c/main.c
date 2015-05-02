#include "Print.h"

int main()
{
    FILE *f=fopen("input.txt","r");
    if(f==NULL)
    {
        perror("Can't open file!\n");
        return -1;
    }
    NodeT *root=createBinTree(f);
    AVLTree(root);
    root=insertNode(root,11);
    root=insertNode(root,12);
    root=deleteNode(root,12);
    prettyPrint(root,0);
    return 0;
}

