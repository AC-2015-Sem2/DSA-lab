#include "header.h"

int main(void)
{
    TreeT *root;
    FILE *f;

    f = fopen("input.txt", "r+");
    if (f == NULL)
    {
        perror("Cannot open file");
        return(-1);
    }
    root = createBinTree(f);
    printf("The tree made from the input is : \n");
    prettyPrint(root, 0);
    return 0;
}
