#include "functions.h"

int main()
{
    FILE *file, *fileOutput;
    file= fopen("input.dat", "r");

    if(file== NULL)
    {
        perror("Cannot open file");
        return -100;
    }
    fileOutput = fopen("output.dat", "w");

    getContent = &getStringContent;
    printElement = &printStringElement;

    NodeT *root = NULL;
    root = createBinTree(file);
    prettyPrint(root,0,fileOutput);

    return 0;
}
