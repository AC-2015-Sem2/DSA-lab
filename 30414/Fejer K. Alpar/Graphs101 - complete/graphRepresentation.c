#include <stdlib.h>
#include "graphRepresentation.h"

void matrixToList()
{
    adjListNodeT *lastNode,*currentNode;
    adjListNeighborT *lastNeighbor,*currentNeighbor;
    int i,j;
    for (i=0; i<nrOfVerteces; i++)
    {
        if (i==0)
        {
            firstNode=(adjListNodeT*)malloc(sizeof(adjListNodeT));
            firstNode->node=0;
            firstNode->next=NULL;
            lastNode=firstNode;
            firstNode->neighbor=NULL;
            currentNode=firstNode;
        }
        else
        {
            currentNode=(adjListNodeT*)malloc(sizeof(adjListNodeT));
            currentNode->node=i;
            currentNode->next=NULL;
            lastNode->next=currentNode;
            currentNode->neighbor=NULL;
            lastNode=currentNode;
        }
        for (j=0; j<nrOfVerteces; j++)
        {
            if (adjMatrix[i][j]!=0)
            {
                if (currentNode->neighbor==NULL)
                {
                    currentNode->neighbor=(adjListNeighborT*)malloc(sizeof(adjListNeighborT));
                    lastNeighbor=currentNode->neighbor;
                    lastNeighbor->next=NULL;
                    lastNeighbor->node=j;
                    lastNeighbor->weight=adjMatrix[i][j];
                }
                else
                {
                    currentNeighbor=(adjListNeighborT*)malloc(sizeof(adjListNeighborT));
                    currentNeighbor->node=j;
                    currentNeighbor->next=NULL;
                    currentNeighbor->weight=adjMatrix[i][j];
                    lastNeighbor->next=currentNeighbor;
                    lastNeighbor=currentNeighbor;
                }
            }
        }
    }
}

void listToMatrix()
{
    int i,j;
    adjListNodeT* lNode=firstNode;
    adjListNeighborT* neighbor;
    for (i=0; i<nrOfVerteces; i++)
    {
        neighbor=lNode->neighbor;
        while (neighbor!=NULL)
        {
            adjMatrix[i][neighbor->node]==neighbor->weight;
            neighbor=neighbor->next;
        }
        lNode=lNode->next;
    }
}

void printAdjList()
{
    adjListNodeT* lNode=firstNode;
    adjListNeighborT* neighbor;
    printf("\n");
    while (lNode!=NULL)
    {
        printf("%d:",lNode->node);
        neighbor=lNode->neighbor;
        while (neighbor!=NULL)
        {
            printf(" %d",neighbor->node);
            neighbor=neighbor->next;
        }
        printf("\n");
        lNode=lNode->next;
    }
    printf("\n");
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
    adjListNeighborT *neighbor;
    adjListNodeT *currentNode;
    int i;
    int nrOfNeighbors=0;
    if (firstNode==NULL)
    {
        if(v<nrOfVerteces)
        {
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
    else
    {
        currentNode=firstNode;
        for (i=0; i<v; i++) currentNode=currentNode->next;
        neighbor=currentNode->neighbor;
        while (neighbor!=NULL)
        {
            nrOfNeighbors++;
            neighbor=neighbor->next;
        }
        return nrOfNeighbors;
    }
}

int * getAllNeighborsOfVertex(int v)
{
    adjListNeighborT *neighbor;
    adjListNodeT *currentNode;
    int i;
    int nrOfNeighbors = getNumberOfNeighborsOfVertex(v);
    int * neighbors = (int*)malloc(sizeof(int) * nrOfNeighbors);
    if (firstNode==NULL)
    {
        if(v<nrOfVerteces)
        {

            int j=0;
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
    else
    {
        currentNode=firstNode;
        for (i=0; i<v; i++) currentNode=currentNode->next;
        neighbor=currentNode->neighbor;
        i=0;
        while (neighbor!=NULL)
        {
            neighbors[i]=neighbor->node;
            neighbor=neighbor->next;
            i++;
        }
        return neighbors;
    }
}
