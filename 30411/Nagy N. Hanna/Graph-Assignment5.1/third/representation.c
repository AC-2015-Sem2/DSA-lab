#include "representation.h"

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

nodeT** getListfromMatrix(int** mtrx)
{
    int i, j, nr=nrOfVerteces;
    nodeT** adjList;
    adjList=(nodeT**)malloc(nr*sizeof(nodeT*));
    for(i=0; i<nr; i++)
    {
        adjList[i]=(nodeT*)malloc(sizeof(nodeT));
        adjList[i]->code=i;
        nodeT* aux=adjList[i];
        for(j=0; j<=nr; j++)
            if(mtrx[i][j]==1)
            {
                aux->next=create(j);
                aux=aux->next;
            }
    }
    return adjList;
}

void printList(FILE *f,nodeT** adjList)
{
    int nr=nrOfVerteces;
    int i;
    for(i=0; i<nr; i++)
    {
        fprintf(f,"%c: ", i+65);
        nodeT* aux=adjList[i]->next;
        while(aux!=NULL)
        {

        fprintf(f,"%c ", aux->code+65);
        aux=aux->next;

        }
        fprintf(f,"\n");
    }
    fclose(f);
}

int** getMatrixfromList(nodeT** adjList)
{
    int i=0, j, nr=nrOfVerteces;
    int ** m=(int**)malloc(nr* sizeof(int*));
    for (i=0; i<nr; i++)
        {
            *(m+i)=(int*)calloc(nr, sizeof(int*));
        }
    for(i=0; i<nr; i++)
    {
        nodeT* aux=adjList[i]->next;
        while(aux!=NULL)
        {
            j=aux->code;
            m[i][j]=1;
            m[j][i]=1;
            aux=aux->next;
        }
    }
    return m;
}
