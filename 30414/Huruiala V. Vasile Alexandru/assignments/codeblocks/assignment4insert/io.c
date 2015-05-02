#include <stdio.h>
#include "definition.h"
#define INPUT_FILE "input.dat"
#define OUTPUT_FILE "output.dat"

int openFiles(FILE** I, FILE** O)
{
    if((*I = fopen(INPUT_FILE, "r")) == NULL)
        return -1;
    if((*O = fopen(OUTPUT_FILE, "w")) == NULL)
        return -2;
    return 0;
}

void closeFiles(FILE** I, FILE** O)
{
    fclose(*I);
    *I = NULL;
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
