#include "tree.h"

int main()
{
    // printElement = &printStringElement;
    printElement = &printIntegerElement;

    // getContent = &getStringContent;
    getContent = &getIntegerContent;

    FILE * f = fopen("tree.dat", "r");
    FILE * f2 = fopen("tree2.dat", "r");

    NodeT * root = createBinTree(f);
    NodeT * root2 = createBinTree(f2);

    preorder(root);
    printf("\n\n");
    inorder(root);
    printf("\n\n");
    postorder(root);
    printf("\n\n");

    printf("Max Depth: %d\n\n", maxDepth(root));
    printf("Size: %d\n\n",size(root));

    int pathSum = 15;
    hasPathSum(root,pathSum) ? printf("The tree has a path sum of %d\n\n",pathSum) : printf("The tree does not have a path sum of %d\n\n",pathSum);
    pathSum = 16;
    hasPathSum(root,pathSum) ? printf("The tree has a path sum of %d\n\n",pathSum) : printf("The tree does not have a path sum of %d\n\n",pathSum);

    int * paths = (int*)malloc(sizeof(int)*100);
    printPaths(root, paths, 0);
    printf("\n\n");

    mirror(root);

    doubleTree(root);
    prettyPrint(root,0);
    printf("\n\n");

    isBST(root) ? printf("It's a BST.\n\n") : printf("It's not a BST.\n\n");

    sameTree(root, root2) ? printf("They are the same tree.\n\n") : printf("They are not the same tree.\n\n");
    sameTree(root, root) ? printf("They are the same tree.\n\n") : printf("They are not the same tree.\n\n");

    return 0;
}
