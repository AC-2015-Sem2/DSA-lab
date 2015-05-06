#include <stdlib.h>
#include <time.h>
#include "utility.h"

void initRand()
{
    srand(time(NULL));
}

//Random uint between min and max
int getRand(int min, int max)
{
    return min + rand() % (max - min + 1);
}

int** getCopyOfAdjecencyMatrix(int** adjMat, int size)
{
    int i, j;
    int** copyAdjMat =(int**)malloc(sizeof(int*) * size);
    for(i = 0; i < size; i++)
    {
        *(copyAdjMat+i)=(int*)malloc(sizeof(int) * size);
        for(j = 0; j < size; j++)
        {
            copyAdjMat[i][j] = adjMat[i][j];
        }
    }
    return copyAdjMat;
}

///Only counts above the main diagonal
int noOfEdges(int** adjMat, int size)
{
    int count = 0;
    int i, j;
    for(i = 0; i < size - 1; i++)
        for(j = i + 1; j < size; j++)
            if(adjMat[i][j] > 0)
                count++;

    return count;
}

edge extractMinEdge(int** adjMat, int size)
{
    int i, j;
    edge minEdge;
    minEdge.weight = -1;

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if(adjMat[i][j] > 0)
            {
                if(adjMat[i][j] < minEdge.weight || minEdge.weight == -1)
                {
                    minEdge.source = i;
                    minEdge.destination = j;
                    minEdge.weight = adjMat[i][j];
                }
            }
        }
    }
    ///Delete min edge form the matrix
    adjMat[minEdge.source][minEdge.destination] = 0;
    adjMat[minEdge.destination][minEdge.source] = 0;

    return minEdge;
}

int adjMatIsEmpty(int** adjMat, int size)
{
    int isEmpty = 1;

    int i, j;
    for(i = 0; i < size && isEmpty == 1; i++)
        for(j = 0; j < size && isEmpty == 1; j++)
            if(adjMat[i][j] > 0)
                isEmpty = 0;

    return isEmpty;
}

///Extracts the arbNumber-th valid edge(it works better if you don't pick the first edge
///otherwise the edges it would cut would not affect the next extraction(on the graph I tested it))
edge extractEdgeAndCutAllIncidentEdges(int** adjMat, int size, int arbNumber)
{
    int i, j;
    edge arbEdge;
    arbEdge.weight = -1;
    int iteration = 0;

    for (i = 0; i < size && iteration < arbNumber; i++)
    {
        for (j = 0; j < size && iteration < arbNumber; j++)
        {
            if(adjMat[i][j] > 0)
            {
                arbEdge.source = i;
                arbEdge.destination = j;
                arbEdge.weight = adjMat[i][j];
                iteration++;
            }
        }
    }
    ///Delete all edges incident on source and destination
    for(i = 0; i < size; i++)
    {
        adjMat[arbEdge.source][i] = 0;
        adjMat[i][arbEdge.source] = 0;

        adjMat[arbEdge.destination][i] = 0;
        adjMat[i][arbEdge.destination] = 0;
    }

    return arbEdge;
}
