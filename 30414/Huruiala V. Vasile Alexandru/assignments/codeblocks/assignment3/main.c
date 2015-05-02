#include "mainheader.h"

int main()
{
    FILE* IN;
    FILE* OUT;
    if(openFiles(&IN, &OUT) != 0)
        exit(-1);

    BinTree* root = createBinTree(IN);
    printf("Before:\n");
    fprintf(OUT, "Before:\n");
    prettyPrint(OUT, root, 0);

    DLL* head = BinTreeToDLList(root);

    DLLRewind(&head);
    printf("The list obtained form the tree:\n"); fprintf(OUT, "The list obtained form the tree:\n");
    DLLPrint(OUT, head);

    //I used a different root because we are allocating new memory
    BinTree* root1 = DDListToBinTree(head);
    printf("After:\n");
    fprintf(OUT, "After:\n");
    prettyPrint(OUT, root1, 0);

    closeFiles(&IN, &OUT);
    return 0;
}
