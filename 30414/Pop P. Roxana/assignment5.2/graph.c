#include "graph.h"

NodeT * createNode(int content)
{
    NodeT * newN = (NodeT*)malloc(sizeof(NodeT));
    newN->content=content;
    newN->next=NULL;
    return newN;
}
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
NodeT** constructAdjList(FILE * f,int * n)
{
    fscanf(f,"%d",n);
    fscanf(f,"\n");
    NodeT** adjList=(NodeT**)malloc((*n)*sizeof(NodeT*));
    int i;
    for (i=0;i<(*n);i++)
    {
        adjList[i]=NULL;///at first, the adjList of the i-th element is empty
        char *line=(char*)malloc(1024*sizeof(char));
        fgets(line,1024,f);
        char * tok;
        tok = strtok (line," ");
        int data;
        sscanf(tok,"%d",&data);
        addLast(&adjList[i],data);
        tok = strtok(NULL," ");
        while (tok != NULL)
        {
            sscanf(tok,"%d",&data);
            addLast(&adjList[i],data);
            tok = strtok (NULL, " ");
        }
        memset(line,0,1024);
    }
    return adjList;
}
int getNumberOfNeighborsOfVertex(int v)
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

int * getAllNeighborsOfVertex(int v)
{
    int k=0;
    int n=getNumberOfNeighborsOfVertex(v);
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

int longestPathRec(int v, int u,int * mark)
{
   if (mark[v]==1) return -1;
   if (v==u) return 0;
   mark[v]=1;
   int i;
   int max=-1;
   int* neighbours=getAllNeighborsOfVertex(v);
   int w;
   for (i=0;i<getNumberOfNeighborsOfVertex(v);i++)
   {
        w=longestPathRec(neighbours[i],u,mark);
        if (w>max) max=w;
   }
   if (max>-1) return max+1;
   else return -1;
}

int longestPath(int v, int u)///returns -1 if no such path
{
    int * mark=(int*)malloc(n*sizeof(int));
    int i;
    for (i=0;i<n;i++)
        mark[i]=0;
    return longestPathRec(v,u,mark);
}
