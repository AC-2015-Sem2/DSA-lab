# include "header.h"

int main()
{
    FILE *in = fopen("input.txt", "r");

    readFromAdjMatrix(in);
    //printAdjMatrix();

    vertexCover();

    return 0;
}
