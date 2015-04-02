# include "parsetree.h"

int main()
{
    FILE *in;

    in=fopen("input.txt", "r");

    createQ(in);
    NodeT *root = createTree();

    prettyPrint(root, 0);

    return 0;
}
