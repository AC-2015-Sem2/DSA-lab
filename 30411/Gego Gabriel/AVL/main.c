#include <stdio.h>
#include <stdlib.h>
#include "Functions.h"





int main()
{

    NodeT *root=NULL;
    int i=0;
    for(i=0; i<25; i++)
        root=insertNode(root,i);

    PreetyPrint(root,0);
    return 0;
}
