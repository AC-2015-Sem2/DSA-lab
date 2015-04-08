#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int main()
{
    NodeT *root = NULL;
    root = createBinTree();
    //testing out
    int i;
    for(i=0;i<150;i++)
        root = insert(root, i);


    prettyPrint(root,0);
    return 0;


    prettyPrint(root,0);
    return 0;
}
