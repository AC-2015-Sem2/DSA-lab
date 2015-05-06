# include "header.h"

edgeT *createEdge(int dest, int source)
{
    edgeT *edge = (edgeT*) malloc (sizeof(edgeT));

    edge->source = source;
    edge->dest = dest;
    edge->next = NULL;

    return edge;
}

void addAnEdge(int source, int dest)
{
    if(firstEdge == NULL)
    {
        firstEdge = lastEdge = createEdge(dest, source);
    }
    else
    {
        lastEdge->next = createEdge(dest, source);
        lastEdge = lastEdge->next;
    }
}

void removeEdges(int x)
{
    edgeT *p, *aux = firstEdge;

    p=aux;


    while(p!=NULL && (p->source == x || p->dest == x))
    {
        firstEdge = firstEdge ->next;
        free(p);
        p = firstEdge;
    }

    aux = p;

    if(p!=NULL)
    {
        p = p->next;
        while(p!=NULL)
        {
            if(p->source == x || p->dest == x)
            {
                aux->next = p->next;
                free(p);
                p = aux->next;
            }
            else
            {
                aux = p;
                p=p->next;
            }
        }
    }

}

void printEdges()
{
    edgeT *p = firstEdge;

    while(p!=NULL)
    {
        printf("%d-%d  ", p->source, p->dest);
        p=p->next;
    }
    printf("\n");

}

int getNrOfEdges()
{
    edgeT *p = firstEdge;
    int nr = 0;

    while(p!=NULL)
    {
        nr+=1;
        p=p->next;
    }
    return nr;
}

int hasOtherAdjacentEdges(int node)
{
    edgeT *p = firstEdge;
    int nr = 0;

    while(p!=NULL)
    {
        if(p->source == node || p->dest == node)
            nr+=1;
        p=p->next;
    }

    if(nr==1)
        return 0;
    else
        return 1;
}

