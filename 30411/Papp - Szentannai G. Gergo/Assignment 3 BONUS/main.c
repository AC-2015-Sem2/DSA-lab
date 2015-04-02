#include "tree.h"

int main()
{
    FILE* in;
    in=fopen("input.txt","r");


    NodeT *root = createBinTree(in);  // Construct binary tree from a .txt file

    printf("Tree of the mathematical expression (horizontal, root on the left):\n\n");
    prettyPrint(root,0);  // Print the tree

    float result = calc(root);

    printf("\n\nValue of expression is: %.3f\n",result);


    return 0;
}
