#include "main.h"

int main()
{
    //I1 is for insertion, I2 is for deletion
    FILE* I1 = NULL;
    FILE* I2 = NULL;
    FILE* O = NULL;
    openFiles(&I1, &I2, &O);

    BTree* root = NULL;
    //Creation using insertion
    root = createAVLFromFile(I1);
    //Printing before the deletion
    printf("After creation with insertion:\n");
    fprintf(O, "After creation with insertion:\n");
    prettyPrint(O, root, 0);
    //Deletion
    printf("After deletion:\n");
    fprintf(O, "After deletion:\n");
    deleteAVLFromFile(I2, &root);
    //The resulted tree should be a balanced binary search tree
    prettyPrint(O, root, 0);

    printf("\nIs balanced(0 - no, 1 - yes, 2 - obviously): %d\n", isBST(root));
    fprintf(O, "\nIs balanced(0 - no, 1 - yes, 2 - obviously): %d\n", isBST(root));
    printf("\nInorder print:\n");
    fprintf(O, "\nInorder print:\n");
    inorderPrint(O, root);
    printf("\nDone.\n");
    fprintf(O, "\nDone.\n");

    closeFiles(&I1, &I2, &O);
    return 0;
}
