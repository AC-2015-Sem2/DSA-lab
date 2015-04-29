#include <stdio.h>
#include <stdlib.h>

#include "graph.h"
#include "stack.h"
#include "queue.h"
#include "list.h"
#include "matrix.h"

NodeT** MatrixToList(int **adjMatrix)
{
    NodeT** adjList=(NodeT**)malloc(nrOfVertices*sizeof(NodeT*));
    int i,j;
    for (i=0; i<nrOfVertices; i++)
    {
        adjList[i]=NULL;
        for (j=0; j<nrOfVertices; j++)
        {
            if (adjMatrix[i][j]==1)
                addNode(&adjList[i],j);
        }
    }
    return adjList;
}

void AdjListToMatrix(NodeT** adjList)
{
    int i;
    for(i=0; i<nrOfVertices; i++)
    {
        NodeT * temp=adjList[i];
        while(temp!=NULL)
        {
            adjMatrix[i][temp->content]=1;
            temp=temp->next;
        }
    }
}


void dfsRec(int v)
{
}

void dfsRecurs(int v)
{
}
