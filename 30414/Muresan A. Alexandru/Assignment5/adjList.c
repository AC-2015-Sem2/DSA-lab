#include <stdlib.h>
#include "adjList.h"

void addToAdjacencyList(int content, int* neighbourList)
{
    adjacencyList=(adjNode*)malloc(sizeof(adjNode));
    if (adjacencyList==NULL)
    {
        adjacencyList->neighbours=neighbourList;
        adjacencyList->nrOfNeighbours=getNumberOfNeighborsOfVertex(content);
        adjacencyList->next=NULL;
        adjacencyList->content=content;
    }
    else
    {
        adjNode *ownNode=(adjNode*)malloc(sizeof(adjNode));
        ownNode->content=content;
        ownNode->neighbours=neighbourList;
        ownNode->nrOfNeighbours= getNumberOfNeighborsOfVertex(content);
        ownNode->next=NULL;

        adjNode *auxNode= adjacencyList;
        while (auxNode->next!=NULL)
        {
            auxNode=auxNode->next;
        }

        auxNode->next=ownNode;

    }
}

void printVector(int *v, int len)
{
    int i;
    for(i=0; i<len; i++)
    {
        printf("%c ", *(v+i)+65);
    }
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
    printf("Adjacency list: \n");
    adjNode *ownNode= adjacencyList;
    while(ownNode !=NULL)
    {
        printf("Node %c: ", ownNode->content+65);
        printVector(ownNode->neighbours, getNumberOfNeighborsOfVertex(ownNode->content));
        printf("\n");
        ownNode=ownNode->next;
    }
}

void listToMatrix()
{
    int i, j;
    matrixFromList=(int**)malloc(nrOfVerteces*sizeof(int*));
    for(i=0; i<nrOfVerteces; i++)
    {
        *(matrixFromList+i)=(int*)malloc(nrOfVerteces*sizeof(int));
    }
    for(i=0; i<nrOfVerteces; i++)
    {
        for(j=0; j<nrOfVerteces; j++)
        {
            matrixFromList[i][j]=0;
        }
    }
    adjNode *ownNode= adjacencyList;
    while(ownNode!=NULL)
    {
        for(i=0; i<ownNode->nrOfNeighbours; i++)
        {
            matrixFromList[ownNode->content][ownNode->neighbours[i]]=1;
        }
        ownNode=ownNode->next;
    }
}

void printAdjMatrixFromList()
{
    int i, j;
    printf("\n Matrix from list:\n");
    printf("    ");
    for(i=0; i<nrOfVerteces;i++)
    {
        printf("%c   ", 65+i);
    }
    printf("\n");
    for(i=0; i<nrOfVerteces; i++)
    {
        printf("%c ", 65+i);
        for(j=0; j<nrOfVerteces; j++)
        {
            printf("%3d ", matrixFromList[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
