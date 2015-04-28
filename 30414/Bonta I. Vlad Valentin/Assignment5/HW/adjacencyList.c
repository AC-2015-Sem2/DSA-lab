#include "adjacencyList.h"

void addToAdjacencyList(int data, int *neighborList)
{
    if(adjacencyList == NULL)
    {
        adjacencyList = (adjNode*)malloc(sizeof(adjNode));
        adjacencyList->neighbors = neighborList;
        adjacencyList->numberOfNeighbors = getNumberOfNeighborsOfVertex(data);
        adjacencyList->next = NULL;
        adjacencyList->content = data;
    }
    else
    {
        adjNode *tmp = (adjNode*)malloc(sizeof(adjNode));
        tmp->content = data;
        tmp->neighbors = neighborList;
        tmp->numberOfNeighbors = getNumberOfNeighborsOfVertex(data);
        tmp->next = NULL;
        adjNode *auxNode = adjacencyList;
        while(auxNode->next != NULL)
            auxNode = auxNode->next;
        auxNode->next = tmp;
    }
}

void printVector(int* vect, int n)
{
    int i;
    for(i = 0; i < n; i++)
        printf("%c ", *(vect+i) + 65);
}

void matrixToList()
{
    int i;
    for(i=0; i<nrOfVerteces; i++)
    {
        int *neighList = getAllNeighborsOfVertex(i);
        addToAdjacencyList(i, neighList);
    }
}

void printAdjList()
{
    printf("The adjacency list is: \n");
    adjNode *auxNode = adjacencyList;
    while(auxNode != NULL)
    {
        printf("Node %c: ",auxNode->content+65);
        printVector(auxNode->neighbors, getNumberOfNeighborsOfVertex(auxNode->content));
        printf("\n");
        auxNode = auxNode->next;
    }
}

void listToMatrix()
{
    int i, j;
    adjMatrixFromList=(int**)malloc(nrOfVerteces*sizeof(int*));
    for (i=0; i<nrOfVerteces; i++)
    {
        *(adjMatrixFromList+i)=(int*)malloc(nrOfVerteces*sizeof(int));
    }

    for(i=0; i<nrOfVerteces; i++)
        for(j=0; j<nrOfVerteces; j++)
            adjMatrixFromList[i][j] = 0;

    adjNode *auxNode = adjacencyList;
    while(auxNode != NULL)
    {
        for(i = 0; i < auxNode->numberOfNeighbors; i++)
            adjMatrixFromList[auxNode->content][auxNode->neighbors[i]] = 1;
        auxNode = auxNode->next;
    }
}

void printAdjMatrixFromList()
{
    int i,j;

    printf("\nThe transformed matrix is:\n");
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
            printf("%3d ",adjMatrixFromList[i][j]);
        printf("\n");
    }
    printf("\n");
}
