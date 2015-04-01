#include <stdlib.h>
#include "treeFunctions.h"

int main()
{
    FILE* ifile = fopen("inp.txt", "r");
    char* inp = (char*)malloc(11);
    NodeT* root = NULL;
    while (fgets(inp, 10, ifile)){
        root = insertF(root, atoi(inp));
    }
    fclose(ifile);
    FILE* ofile = fopen("output.txt", "w");
    prettyPrint(root, 0, ofile);
    fclose(ofile);
    return 0;
}
