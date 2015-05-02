#include "matrixtolistandviceversa.h"

void matrixToList()
{
    int i;
    for(i=0; i<nrOfVerteces; i++)
    {
        int *neighList = getAllNeighborsOfVertex(i);
        if(adjList == NULL)
        {
            adjList = (adjacencyNode*)malloc(sizeof(adjacencyNode));
            adjList->neighbors = neighList;
            adjList->nrNeighbors = getNumberOfNeighborsOfVertex(i);
            adjList->next = NULL;
            adjList->data = i;
        }
        else
        {
            adjacencyNode *tempNode = (adjacencyNode*)malloc(sizeof(adjacencyNode));
            tempNode->data = i;
            tempNode->neighbors = neighList;
            tempNode->nrNeighbors = getNumberOfNeighborsOfVertex(i);
            tempNode->next = NULL;

            adjacencyNode *auxNode = adjList;

            while(auxNode->next != NULL)
                auxNode = auxNode->next;

            auxNode->next = tempNode;
        }
    }
}

void printVector(int* vect, int len)
{
    int i;
    for(i = 0; i < len; i++)
        printf("%c ", *(vect+i)+65);
}

void printAdjMatrixFromList()
{
    int i,j;

    printf("\nThe matrix obtained from the adjacency list is:\n");
    printf("    ");
    for (i=0; i<nrOfVerteces; i++)
    {
        printf("%c   ",65+i);
    }
    printf("\n");
    for (i=0; i<nrOfVerteces; i++)
    {
        printf("%c ",65+i);
        for (j=0; j<nrOfVerteces; j++)
            printf("%3d ",matrixFromAdjList[i][j]);
        printf("\n");
    }
    printf("\n");
}
void printAList()
{
    printf("\nThe list obtained from the adjacency matrix is:\n");
    adjacencyNode *auxNode = adjList;
    while(auxNode != NULL)
    {
        printf("%c: ",auxNode->data+65);
        printVector(auxNode->neighbors, getNumberOfNeighborsOfVertex(auxNode->data));

        printf("\n");
        auxNode = auxNode->next;
    }
}


void listToMatrix()
{
    int i, j;
    matrixFromAdjList=(int**)malloc(nrOfVerteces*sizeof(int*));
    for (i=0; i<nrOfVerteces; i++)
    {
        *(matrixFromAdjList+i)=(int*)malloc(nrOfVerteces*sizeof(int));
    }

    for(i=0; i<nrOfVerteces; i++)
        for(j=0; j<nrOfVerteces; j++)
            matrixFromAdjList[i][j] = 0;

    adjacencyNode *auxNode = adjList;
    while(auxNode != NULL)
    {
        for(i = 0; i < auxNode->nrNeighbors; i++)
            matrixFromAdjList[auxNode->data][auxNode->neighbors[i]] = 1;
        auxNode = auxNode->next;
    }
}

