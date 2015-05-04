#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

int main()
{
    FILE* f = fopen("matrix.txt", "r");
    if (f == NULL) {
        perror("matrix.txt");
        exit(1);
    }
    struct graph* g;
    g = getGraph(f);
    printMatrixOfGraph(*g);
    vertexCover(*g);
    return 0;
}
