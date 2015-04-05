#include "definition.h"

int openFiles(FILE** I1, FILE** I2, FILE** O)
{
    if((*I1 = fopen(INPUT_FILE1, "r")) == NULL)
        return -1;
    if((*I2 = fopen(INPUT_FILE2, "r")) == NULL)
        return -2;
    if((*O = fopen(OUTPUT_FILE, "w")) == NULL)
        return -3;
    return 0;
}

void closeFiles(FILE** I1, FILE** I2, FILE** O)
{
    fclose(*I1);
    *I1 = NULL;
    fclose(*I2);
    *I2 = NULL;
    fclose(*O);
    *O = NULL;
}

void inorderPrint(FILE* O, BTree* root)
{
    if(root != NULL)
    {
        inorderPrint(O, root->left);
        printf("%d ", *(int*)root->data);
        fprintf(O, "%d ", *(int*)root->data);
        inorderPrint(O, root->right);
    }
}

void printElement(FILE* O, BTree* node)
{
    /**/
    printf("%4d", *(int*)node->data);
    fprintf(O, "%4d", *(int*)node->data);
    /**/
    /*DEBUG*
    printf("%d|%d", node->Lweight, node->Rweight);
    **/
}

//copy pasted
void prettyPrint(FILE* O, BTree *root,int recLevel) //! root, index, length, reccurence level
{
    if(root==NULL)
    {
        recLevel--; //! reached leaf, must decrement recurence level
        return;
    }
    recLevel++; //! otherwise increment it
    prettyPrint(O, root->right,recLevel); //! keep going right in the tree
    int j=0;

    //! print spaces for the appropriate recurence level
    for(j=0; j<recLevel-1; j++)
    {
        printf("     ");
        fprintf(O, "     ");
    }
    //! then print value
    printElement(O, root);

    //! print  a new line
    printf("\n");
    fprintf(O, "\n");

    prettyPrint(O, root->left,recLevel); //! keep going left in the tree
}
