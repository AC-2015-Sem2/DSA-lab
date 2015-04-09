#include "tree.h"

int main()
{
    FILE * f = fopen("tree.dat", "r");
    NodeT * root = createBinTree(f);
    inorder(root);
    printf("\n\n");
    printf("Max depth of tree is: %d\n\n",maxDepth(root));

    int found;
    int s = 5;
    found = search(root, s);
    found ? printf("Element %d was found in the tree.\n",s) : printf("Element %d was not found in the tree.\n",s);
    s = 10;
    found = search(root, s);
    found ? printf("Element %d was found in the tree.\n\n",s) : printf("Element %d was not found in the tree.\n\n",s);


    int hasPath;
    int pathSum = 27;
    hasPath = hasPathSum(root, pathSum);
    hasPath ? printf("%d is pathSum\n",pathSum) : printf("%d is not pathSum\n",pathSum);
    pathSum = 16;
    hasPath = hasPathSum(root, pathSum);
    hasPath ? printf("%d is pathSum\n\n",pathSum) : printf("%d is not pathSum\n\n",pathSum);

    return 0;
}
