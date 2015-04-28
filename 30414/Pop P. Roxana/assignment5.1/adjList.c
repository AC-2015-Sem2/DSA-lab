#include <stdio.h>
#include <stdlib.h>

#include "graph.h"
#include "stack.h"
#include "queue.h"

void addLast(NodeT** head,int content)
{
    if((*head) == NULL)
    {
        (*head) = createNode(content);

    }
    else
    {
        NodeT * curr = (*head);
        while(curr->next!=NULL)
        {
            curr=curr->next;
        }
        curr->next=createNode(content);
    }

}
NodeT** fromMatrixToList(int **adjMatrix)
{
    NodeT** adjList=(NodeT**)malloc(nrOfVerteces*sizeof(NodeT*));
    int i,j;
    for (i=0;i<nrOfVerteces;i++)
    {
        adjList[i]=NULL;///at first, the adjList of the i-th element is empty
        for (j=0;j<nrOfVerteces;j++)
    {
        if (adjMatrix[i][j]==1) addLast(&adjList[i],j);
    }

    }
    return adjList;
}

void fromAdjListToMatrix(NodeT** adjList)
{
    int i;
    for(i=0;i<nrOfVerteces;i++)
    {
    NodeT * curr=adjList[i];///traverses each neighbor of the i-th node
    while(curr!=NULL)
    {
        adjMatrix[i][curr->content]=1;
        curr=curr->next;
    }
    }
}

int getNumberOfNeighborsOfVertexL(int v)
{
    int s=0;
    NodeT * curr=adjArray[v];
    while(curr!=NULL)
    {
        s++;
        curr=curr->next;
    }
    return s;
}

int * getAllNeighborsOfVertexL(int v)
{
    int k=0;
    int n=getNumberOfNeighborsOfVertexL(v);
    int * a=(int*)malloc(n*sizeof(int));
    NodeT* curr=adjArray[v];
    while(curr!=NULL)
    {
        a[k]=curr->content;
        k++;
        curr=curr->next;
    }
    return a;
}
