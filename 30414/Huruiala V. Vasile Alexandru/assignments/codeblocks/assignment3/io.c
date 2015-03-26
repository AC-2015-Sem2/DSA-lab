#include <stdio.h>
#include "definition.h"

#define INPUT_FILE "input.dat"
#define OUTPUT_FILE "output.dat"

int openFiles(FILE** I, FILE** O)
{
    if((*I = fopen(INPUT_FILE, "r")) == NULL)
    {
        printf("Error. Could not open %s.\n", INPUT_FILE);
        return -1;
    }

    if((*O = fopen(OUTPUT_FILE, "w")) == NULL)
    {
        printf("Error. Could not open %s.\n", OUTPUT_FILE);
        return -2;
    }
    return 0;
}

int closeFiles(FILE** I, FILE** O)
{
    if(*I != NULL)
    {
        fclose(*I);
        *I = NULL;
    }
    if(*O != NULL)
    {
        fclose(*I);
        *O = NULL;
    }
    return 0;
}

void printElement(FILE* O, BinTree* node)
{
    printf("%c", *(char*)node->data); fprintf(O, "%c", *(char*)node->data);
}

//copy pasted
void prettyPrint(FILE* O, BinTree *root,int recLevel) //! root, index, length, reccurence level
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
        printf("     "); fprintf(O, "     ");
    }
    //! then print value
    printElement(O, root);

    //! print  a new line
    printf("\n"); fprintf(O, "\n");

    prettyPrint(O, root->left,recLevel); //! keep going left in the tree
}
