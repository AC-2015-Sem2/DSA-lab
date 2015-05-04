#include "vertex_cover.h"
#include "utility.h"

///arbNumber is there to randomize a bit the edge it extracts
void minVertexCover(int** adjMat, int size, int arbNumber)
{
    int i;
    int count = 0;
    int* result = (int*)malloc(sizeof(int)*size);
    for(i = 0; i < size; i++)
        result[i] = 0;

    int** adjMatAux = getCopyOfAdjecencyMatrix(adjMat, size);

    while(adjMatIsEmpty(adjMatAux, size) == 0)
    {
        edge arbEdge = extractEdgeAndCutAllIncidentEdges(adjMatAux, size, arbNumber);
        result[count++] = arbEdge.source;
        result[count++] = arbEdge.destination;
    }

    for(i = 0; i < count; i++)
        printf("%d ", result[i]);
    printf("\n%d vertices\n", count);
}
