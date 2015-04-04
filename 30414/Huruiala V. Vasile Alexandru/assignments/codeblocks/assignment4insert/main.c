#include "mainheader.h"

int main()
{
    FILE* I = NULL;
    FILE* O = NULL;
    openFiles(&I,&O);

    BTree* root = NULL;
    root = createAVLFromFile(I);

    prettyPrint(O, root, 0);

    printf("\nIs balanced(0 - no, 1 - yes, 2 - obviously): %d\n", isBST(root));
    fprintf(O, "\nIs balanced(0 - no, 1 - yes, 2 - obviously): %d\n", isBST(root));
    printf("\nInorder print:\n");
    fprintf(O, "\nInorder print:\n");
    inorderPrint(O, root);
    printf("\nDone.\n");
    fprintf(O, "\nDone.\n");

    closeFiles(&I, &O);
    return 0;
}
