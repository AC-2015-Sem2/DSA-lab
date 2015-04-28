#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "stack.h"
#include "queue.h"
#include "list.h"

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

    printf("\nThe adjacency matrix is:\n");
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

int getNumberOfNeighborsOfVertex(int v)
{
  int i,count=0;
  for (i=0; i<nrOfVerteces; i++)
    if (adjMatrix[i][v]==1)
      count++;
  return count;
}

int * getAllNeighborsOfVertex(int v)
{
  int nrOfNeighbours=getNumberOfNeighborsOfVertex(v);
  int *array=(int*)malloc(sizeof(int)*nrOfNeighbours);
  int i,count=0;
  for (i=0;i<nrOfVerteces;i++)
  {
    if(adjMatrix[i][v]==1)
        {
          array[count]=i;
          count++;
        }
    }
     return array;
}

int **AdjMatrixAfter;

void AddLast(NodeT** head, int x)
{
    if (*head==NULL)
    {
        *head = (NodeT*)malloc(sizeof(NodeT));
        (*head)->content=x;
        (*head)->next=NULL;
    }
    else
        {
        NodeT* last = *head;
        while(last->next!=NULL) last = last->next;
        NodeT* node=(NodeT*)malloc(sizeof(NodeT));
        node->content=x;
        node->next=NULL;
        last->next=node;
        }
}

NodeT **createAdjList(void)
{
    int i,j,k;
    NodeT **adjArray;
    adjArray=(NodeT**)malloc(sizeof(NodeT)*nrOfVerteces);
    for(i=0; i<nrOfVerteces; i++)
        {
        adjArray[i]=0;
        }
    for(j=0; j<nrOfVerteces; j++)
        {
        for(k=0; k<nrOfVerteces; k++)
            {
            if(adjMatrix[j][k]==1) AddLast(&adjArray[j],k);
            }
        }
    return adjArray;
}

void printAdjList(NodeT *adjList[nrOfVerteces])
{
  int j;
  printf("\nAdjancency List:\n\n");
  for(j=0; j<nrOfVerteces; j++)
  {
      printf("%c| ",j+65);
      NodeT *node=adjList[j];
      while (node!=NULL)
        {
         printf("%c ",node->content+65);
         node=node->next;
        }
     printf("\n");
  }
  printf("\n");
}

void recreateAdjMatrix()
{
    int i,j;
    AdjMatrixAfter=(int**)malloc(nrOfVerteces*sizeof(int*));
    for(i=0; i<nrOfVerteces; i++)
        {
        *(AdjMatrixAfter+i)=(int*)malloc(nrOfVerteces*sizeof(int));
        }
    for (i=0; i<nrOfVerteces; i++)
        for (j=0; j<nrOfVerteces; j++)
                AdjMatrixAfter[i][j]=0;
    for(j=0; j<nrOfVerteces; j++)
        {
        NodeT *node=adjList[j];
        while (node!=NULL)
        {
            AdjMatrixAfter[j][node->content]=1;
            node=node->next;
        }
    }
}

void printAdjMatrixAfter()
{
    int i,j;

    printf("\nThe  adjacency matrix is:\n");
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
            printf("%3d ",AdjMatrixAfter[i][j]);
        printf("\n");
    }
}

