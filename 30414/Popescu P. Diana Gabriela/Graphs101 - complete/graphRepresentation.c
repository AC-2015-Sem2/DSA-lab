#include <stdlib.h>
#include "graphRepresentation.h"

void addLastList(NodeT** list, int content)
{
    if(list==NULL)
        *list=createNode(content);
    else
    {
        NodeT* t=*list;
        while(t->next!=NULL)
            t=t->next;
        t->next=createNode(content);
    }
}

void printLists()
{
    for(i=0; i<nrOfVerteces; i++)
    {
        printf("%d: ", i);
        NodeT* aux=arrayOfLists[i];
        while(aux!=NULL)
            printf("%d ", aux->content);
        printf("\n");
    }
}


int getNumberOfNeighborsOfVertexFromList(int v)
{
    int nr=0;
    NodeT* p=arrayOfLists[v];
    while (p!=NULL)
    {
        nr++;
        p=p->next;
    }
    return nr;
}

int* getAllNeighborsOfVertexFromList(int v)
{
    int i=0;
    int *aux=(int*)malloc(getNumberOfNeighborsOfVertexFromList(v)*sizeof(int));
    NodeT* p=arrayOfLists[v];
    while (p!=NULL)
    {
        aux[i]=p->content;
        i++;
        p=p->next;
    }
    return aux;
}

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
    printf("\n");
}


int getNumberOfNeighborsOfVertex(int v)
{
    if(v<nrOfVerteces)
    {
        int nrOfNeighbors=0;
        int i;
        for(i=0; i< nrOfVerteces; i++)
        {
            if(adjMatrix[v][i]>0 && i!=v)
            {
                nrOfNeighbors++;
            }
        }
        return nrOfNeighbors;
    }
    else
    {
        return 0;
    }
}

int * getAllNeighborsOfVertex(int v)
{
    if(v<nrOfVerteces)
    {
        int nrOfNeighbors = getNumberOfNeighborsOfVertex(v);
        int * neighbors = (int*)malloc(sizeof(int) * nrOfNeighbors);
        int i,j=0;
        for(i=0; i<nrOfVerteces; i++)
        {
            if(adjMatrix[v][i]>0 && i!=v)
            {
                neighbors[j]=i;
                j++;
            }
        }
        return neighbors;
    }
    else
    {
        return NULL;
    }
}

void listFromMatrix()
{
    int i;
    int j;
    for(i=0; i<nrOfVerteces; i++)
    {
        **(arrayOfLists+i)=NULL;
        for(j=0; j<nrOfVerteces; j++)
            if(adjMatrix[i][j]==1)
            addLastList(arrayOfLists+i, j);
    }
}

void matrixFromList()
{
    int i;
    int j;
    for(i=0; i<nrOfVerteces; i++)
        for(j=0; j<nrOfVerteces; j++)
        adjMatrix[i][j]=0;
    for(i=0; i<nrOfVerteces; i++)
    {
        NodeT* aux=arrayOfLists[i];
        while(aux!=NULL)
        {
            adjMatrix[i][aux->content]=1;
            adjMatrix[aux->content][i]=1;
            aux=aux->next;
        }
    }
}
