# include "insdelHeader.h"

int main()
{
    NodeT *root = NULL;

    int i=0;
    for(i=0; i<90;i++)
        root=insertNode(root,i);

    for(i=20;i<80;i++)
        root=deleteNode(root, i);

    prettyPrint(root, 0);


    return 0;
}
