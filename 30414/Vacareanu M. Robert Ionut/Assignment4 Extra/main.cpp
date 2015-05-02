#include "header.h"
#include "functions.cpp"
int main()
{
    NodeT* root = NULL;
    for(int i = 0; i<50; i++) root = insertNode(root, i);
    prettyPrint(root, 0);
    printf("\n\n\n\n\n\n\n\n\n\n\n");
    for(int j=0; j<40; j++) root=deleteNode(root, j);
    prettyPrint(root,0);

return 0;
}
