#include "matrix.h"

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

void printMatrix(int** Matrix)
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
            printf("%3d ",Matrix[i][j]);
        printf("\n");
    }
}

NodeT** getListfromMatrix(int** matrix)
{
    int i, j, n=nrOfVerteces;
    NodeT** adjList;
    adjList=(NodeT**)malloc(n*sizeof(NodeT*));
    for(i=0; i<n; i++)
    {
        adjList[i]=(NodeT*)malloc(sizeof(NodeT));
        adjList[i]->data=i;
        NodeT* aux=adjList[i];
        for(j=0; j<=n; j++)
            if(matrix[i][j]==1)
            {
                aux->next=createNode(j);
                aux=aux->next;
            }
    }
    return adjList;
}

void printList(NodeT** adjList)
{
    int n=nrOfVerteces;
    int i;
    printf("Adjacency list: \n");
    for(i=0; i<n; i++)
    {
        printf("%c: ", 65+i);
        NodeT* aux=adjList[i]->next;
        while(aux!=NULL)
        {
            if(aux->next!=NULL)
                printf("%c, ", aux->data+65);
            else
                printf("%c; \n", aux->data+65);
            aux=aux->next;
        }
    }
}

int** getMatrixfromList(NodeT** adjList)
{
    int i, j, n=nrOfVerteces;
    int** matrix=(int**)calloc(n, sizeof(int*));
    for (i=0; i<n; i++)
        {
            *(matrix+i)=(int*)calloc(n, sizeof(int));
        }
    for(i=0; i<n; i++)
    {
        NodeT* aux=adjList[i]->next;
        while(aux!=NULL)
        {
            j=aux->data;
            matrix[i][j]=1;
            matrix[j][i]=1;
            aux=aux->next;
        }
    }
    return matrix;
}
