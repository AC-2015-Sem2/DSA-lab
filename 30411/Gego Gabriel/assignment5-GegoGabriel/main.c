#include "queue.h"
#include "stack.h"
#include "graph.h"
#include "list.h"
#include "matrix.h"

int main()
{
    FILE * f = fopen("matrix.txt","r");
    readFromAdjMatrix(f);

    printf("Traversals with matrix \n");
    bfsMatrix(0);
    dfsMatrix(0);

    adList=MatrixToList(adjMatrix);

    printf("Traversals with adjacency\n");
    bfsList(0);
    dfsList(0);

    AdjListToMatrix(adList);

    printf("Traversal with matrix after transformation from list2matrix\n");
    bfsMatrix(0);
    dfsMatrix(0);
    return 0;

}
