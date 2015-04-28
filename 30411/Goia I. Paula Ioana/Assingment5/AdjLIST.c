#include <stdio.h>
#include <stdlib.h>
#include "AdjList.h"


void readFromAdjMatrix(FILE * f)
{
    int i,j;
    fscanf(f,"%d",&n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
          fscanf(f,"%d",&adjMatrix[i][j]);
}

void InsertVertex(int vertexKey)
{
    graph[vertexCount].vertexKey=vertexKey;
    graph[vertexCount].edgePointer=NULL;
    vertexCount++;
}

void insertEdge(int vertex1, int vertex2)
{
    //For first vertex
    edge *e,*e1,*e2;
    e=graph[vertex1].edgePointer;
    while(e&& e->edgePointer)
    {
        e=e->edgePointer;
    }
    e1=(struct edge *)malloc(sizeof(*e1));
    e1->vertexIndex=vertex2;
    e1->edgePointer=NULL;
    if(e)
        e->edgePointer=e1;
    else
        graph[vertex1].edgePointer=e1;

    //For second vertex
    e=graph[vertex2].edgePointer;
    while(e&& e->edgePointer)
    {
        e=e->edgePointer;
    }
    e2=(struct edge *)malloc(sizeof(*e2));
    e2->vertexIndex=vertex1;
    e2->edgePointer=NULL;
    if(e)
        e->edgePointer=e2;
    else
        graph[vertex2].edgePointer=e2;
}

void insertAllVert()
{
    int i;
    for(i=0; i<n; i++)
    {
        InsertVertex(i);
    }
}

void insertAllEdges()
{
    int i,j;
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            if(adjMatrix[i][j]==1)
            {
                insertEdge(i,j);
                adjMatrix[j][i]=0;
            }
}
void fromAdjMatrixToAdjList()
{
    insertAllVert();
    insertAllEdges();
}
  void printGraph()
{
    int i;
    struct edge *e;
    for(i=0;i<vertexCount;i++)
    {
        printf("%d(%d)",i,graph[i].vertexKey);
        e=graph[i].edgePointer;
        while(e)
        {
            printf("->%d",e->vertexIndex);
            e=e->edgePointer;
        }
        printf("\n");
    }
}
void fromAdjListToAdjMatrix()
{
    int i;
    for(i=0; i<n; i++)
    {
        edge *e;
        e=graph[i].edgePointer;
        while(e)
        {
            b[graph[i].vertexKey][graph[e->vertexIndex].vertexKey]=1;
            e=e->edgePointer;
        }
    }
}

void printmatrix()
{
    int i,j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            printf("  %d  ",b[i][j]);
        printf("\n");
    }
}
void printAdjMatrix()
{
    int i,j;
    printf("\nThe matrix is:\n");
    printf("    ");
    for (i=0; i<n; i++)
    {
        printf("%c   ",65+i);
    }
    printf("\n");
    for (i=0; i<n; i++)
    {
        printf("%c ",65+i);
        for (j=0; j<n; j++)
            printf("%3d ",adjMatrix[i][j]);
        printf("\n");
    }
}
