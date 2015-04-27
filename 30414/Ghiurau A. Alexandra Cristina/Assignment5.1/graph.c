#include <stdio.h>
#include <stdlib.h>

#include "graph.h"
#include "stack.h"
#include "queue.h"
#include "list.h"

//! representation

void readFromAdjMatrix(FILE * f)
{
    int n;
    fscanf(f,"%d",&n);
    nrOfVerteces=n;
    int i,j;
    adjMatrix=(int**)malloc(n*sizeof(int*));
    for (i=0; i<n; i++)
    {
        *(adjMatrix+i)=(int*)malloc(n*sizeof(int));
    }
    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
            fscanf(f,"%d",&adjMatrix[i][j]);
    fclose(f);
}

void printAdjMatrix()
{
    int i,j;

    printf("\nThe matrix is:\n");
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
            printf("%3d ",adjMatrix[i][j]);
        printf("\n");
    }
}

NodeT ** listFromMatrix()
{
    NodeT** adjList=(NodeT**)malloc(sizeof(NodeT*)*nrOfVerteces); //create (allocate memory) for a vector of type listL
    int i,j;
    for (i=0; i<nrOfVerteces; i++)
    {
        adjList[i] = NULL;
        for (j=0; j<nrOfVerteces; j++)
        {
            if (adjMatrix[i][j]==1) //at each index, if there is a path, put it in a list
                addLast(j);
        }
    }
    return adjList;

}

void matrixFromList(NodeT **adjList)
{
    int i;
    for(i=0; i<nrOfVerteces; i++)
    {
        NodeT * aux = adjList[i];
        while(aux != NULL)
        {
            adjMatrix[i][aux->content]++;
            aux=aux->next;
        }
    }
     printList();
}

int getNumberOfNeighborsOfVertex1(int v)
{
    int counter = 0;
    int j;
    for(j=0; j<nrOfVerteces; j++)
    {
        if(adjMatrix[v][j]==1)
        {
            counter++;
        }
    }
    return counter;
}

int * getAllNeighborsOfVertex1(int v)
{
    //returns a vector containing.. (the size is from getNumberOfNeighbors)
    int count=0;
    int j;
    int k = getNumberOfNeighborsOfVertex(v);
    int * neighbors = (int*)malloc(sizeof(int)*k);
    for (j=0; j<nrOfVerteces; j++)
    {
        if(adjMatrix[v][j]==1)
        {
            neighbors[count]=j;
            count++;
        }
    }
    return neighbors;
}

int getNumberOfNeighborsOfVertex2(int v)
{
    int counter = 0;
    NodeT *aux = adjArray[v];
    while(aux != NULL)
    {
        counter++;
        aux = aux->next;
    }
    return counter;
}

int * getAllNeighborsOfVertex2(int v)
{
    int count=0;
    int k = getNumberOfNeighborsOfVertex(v);
    int * neighbors = (int*)malloc(sizeof(int)*k);
    NodeT *aux = adjArray[v];
    while(aux != NULL)
    {
        neighbors[count]=aux->content;
        count++;
        aux = aux->next;
    }
    return neighbors;
}


