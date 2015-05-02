#include "prettyPrint.h"

#include <stdio.h>

void printElement(Tree* t) {
    printf("%d ", t->val);
}

void prettyPrint(Tree* t, int recLevel) //! root, index, length, reccurence level
{
    if(t == NULL) {
        recLevel--; //! reached leaf, must decrement recurence level
        return;
    }
    recLevel++; //! otherwise increment it
    prettyPrint(t->right, recLevel); //! keep going right in the tree
    int j=0;
    //! print spaces for the appropriate recurence level
    for(j=0; j < recLevel-1; j++) {
        printf("   ");
    }
    //! then print value
    printElement(t);
    //! print a new line
    printf("\n");
    prettyPrint(t->left, recLevel); //! keep going left in the tree
}