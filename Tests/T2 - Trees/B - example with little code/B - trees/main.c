#include "tree.h"

int main()
{
    FILE * f = fopen("tree.dat", "r");
    NodeT * root = createBinTree(f);
    postorder(root);
    printf("\n\n");
    printf("Max size of tree is: %d\n\n",size(root));

    int found;
    int s = 5;
    found = search(root, s);
    found ? printf("Element %d was found in the tree.\n",s) : printf("Element %d was not found in the tree.\n",s);
    s = 10;
    found = search(root, s);
    found ? printf("Element %d was found in the tree.\n\n",s) : printf("Element %d was not found in the tree.\n\n",s);

    mirror(root);
    postorder(root);
    printf("\n\n");

    int * paths = (int*)malloc(sizeof(int)*100);
    printPaths(root, paths, 0);

    return 0;
}
