#include <stdio.h>
#include <stdlib.h>

#include "Queue.h"
#include "Tree.h"
#include "prettyPrint.h"
#include "functions.h"

int main()
{
    FILE* f = openFile("input.dat");
    Queue* newQ = createQueue(f);
    printQueue(newQ);
    Tree* newT = buildBinaryTree(&newQ);
    preorder(newT);
    printf("\n");
    prettyPrint(newT, 0);

    fclose(f);
    return 0;
}
