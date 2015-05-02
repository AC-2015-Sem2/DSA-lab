#include "binaryTree.h"



int main()
{
    FILE *f, *pf;
    nodeT *root;
    pf=fopen("output.txt","w");
    if(pf==NULL) perror("Something wrong with creating file");
    f=fopen("inputs.txt","r+");
    if(f==NULL) perror("cannot be opened");
    root=createBinTree(f);
    prettyPrint(pf,root,0);

    return 0;
}
