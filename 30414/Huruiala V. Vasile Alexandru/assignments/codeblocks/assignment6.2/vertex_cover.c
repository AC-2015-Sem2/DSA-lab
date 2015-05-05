#include "vertex_cover.h"
#include "utility.h"

///arbNumber is there to randomize a bit the edge it extracts
void minVertexCover(int** adjMat, int size)
{
    int i;
    int count = 0;
    int* result = (int*)malloc(sizeof(int)*size);
    for(i = 0; i < size; i++)
        result[i] = 0;

    int** adjMatAux = getCopyOfAdjecencyMatrix(adjMat, size);

    int nEdges = noOfEdges(adjMatAux, size);

    while(adjMatIsEmpty(adjMatAux, size) == 0)
    {
        edge arbEdge = extractEdgeAndCutAllIncidentEdges(adjMatAux, size, getRand(1, nEdges--));
        result[count++] = arbEdge.source;
        result[count++] = arbEdge.destination;
    }

    for(i = 0; i < count; i++)
        printf("%d ", result[i]);
    printf("\n%d vertices\n", count);

    free(result);
    for(i = 0; i < size; i++)
        free(*(adjMatAux + i));
    free(adjMatAux);
}

void minVertexCoverNTimes(int** adjMat, int size, int iterations)
{
    int it = 0;
    int* output = (int*)malloc(sizeof(int)*size);
    for(it = 0; it < size; it++)
        output[it] = 0;
    for(it = 0; it < iterations; it++)
    {
        int i;
        int count = 0;

        int** adjMatAux = getCopyOfAdjecencyMatrix(adjMat, size);

        int nEdges = noOfEdges(adjMatAux, size);

        while(adjMatIsEmpty(adjMatAux, size) == 0)
        {
            extractEdgeAndCutAllIncidentEdges(adjMatAux, size, getRand(1, nEdges--));
            count += 2;
        }

        output[count]++;

        for(i = 0; i < size; i++)
            free(*(adjMatAux + i));
        free(adjMatAux);
    }
    FILE* o = fopen("output.dat", "w");
    for(it = 0; it < size; it++)
    {
        printf("%d:%d ", it,  output[it]);
        fprintf(o, "%d:%d ", it,  output[it]);
    }
    printf("\n");
    fprintf(o, "\n");
    free(output);
}
