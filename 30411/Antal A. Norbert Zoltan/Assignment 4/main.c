#include <stdlib.h>
#include <string.h>
#include "treeFunctions.h"

void readFile(FILE*, NodeT**, NodeT*(*)(NodeT*, int));

int main()
{
    FILE* ifile = fopen("inp.txt", "r");
    NodeT* root = NULL;
    readFile(ifile, &root, &insertF);
    FILE* ofile = fopen("output.txt", "w");
    prettyPrint(root, 0, ofile);
    fprintf(ofile, "\n");
    readFile(ifile, &root, &deleteF);
    fclose(ifile);
    prettyPrint(root, 0, ofile);
    fclose(ofile);
    return 0;
}

void readFile (FILE* file, NodeT** node, NodeT* (*treeFct)(NodeT*, int)){
    char* inp = (char*)malloc(51);
    fgets(inp, 50, file);
    char* tok = strtok(inp, " ");
    while (tok){
        *node = (*treeFct)(*node, atoi(tok));
        tok = strtok(NULL, " ");
    }
}


