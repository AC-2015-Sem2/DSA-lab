#include <stdio.h>
#include <stdlib.h>

#include "graph.h"
#include "stack.h"
#include "queue.h"
#include "list.h"


void addNode(NodeT** head,int content)
{
    if((*head) == NULL)
        (*head) = createNode(content);
    else
    {
        NodeT * temp = (*head);
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=createNode(content);
    }

}


int getNumberOfNeighborsOfVertexFromList(int v)
{
    int nr=0;
    NodeT * temp=adList[v];
    while(temp!=NULL)
    {
        nr++;
        temp=temp->next;
    }
    return nr;
}

int * getAllNeighborsOfVertexFromList(int v)
{
    int l=0, n=getNumberOfNeighborsOfVertexFromList(v);
    int * neighbours=(int*)malloc(n*sizeof(int));
    NodeT* temp=adList[v];
    while(temp!=NULL)
    {
        neighbours[l]=temp->content;
        l++;
        temp=temp->next;
    }
    return neighbours;
}


void bfsList(int searchNode)
{
    int* visited=(int*)malloc(nrOfVertices*sizeof(int));
    int i;
    for (i=0; i<nrOfVertices; i++)
    {
        visited[i]=UNVISITED;
    }
    visited[searchNode]=VISITED;
    enqueue(searchNode);
    printf("%d ",searchNode);
    while(!isEmptyQueue())
    {
        int v=peekQueue()->content;
        dequeue();
        int* aux=getAllNeighborsOfVertexFromList(v);
        for (i=0; i<getNumberOfNeighborsOfVertexFromList(v); i++)
        {
            int w=aux[i];
            if (visited[w]==UNVISITED)
            {
                visited[w]=VISITED;
                enqueue(w);
                printf("%d ",w);
            }
        }
    }
    printf("\n");
}

void dfsList(int searchNode)
{
    int* visited=(int*)malloc(nrOfVertices*sizeof(int));
    int i;
    for (i=0; i<nrOfVertices; i++)
    {
        visited[i]=0;
    }
    push(searchNode);
    while(!isEmptyStack())
    {
        int v=peekStack()->content;
        pop();
        if (visited[v]==0)
        {
            visited[v]=1;
            int* aux=getAllNeighborsOfVertexFromList(v);
            for (i=getNumberOfNeighborsOfVertexFromList(v)-1; i>=0; i--)
            {
                int w=aux[i];
                if (visited[w]==0)
                    push(w);
            }
            printf("%d ",v);
        }
    }
    printf("\n");
}
