#include <stdio.h>
#include <stdlib.h>
FILE *f, *pf;
typedef struct node
{
    int code;
    struct node *next;
} nodeT;
nodeT *aa,*bb;

void intersect(NodeT *a , NodeT *b)
{
    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));

}

void addfirst(NodeT *a , NodeT *b, int code)
{
    if(a==NULL)
    {
        a=(NodeT*)malloc(sizeof(NodeT*));
        a->code=code;
        a->next=NULL;
    }
    else if(b==NULL)
    {
        b=a;
        NodeT *p=(NodeT*)malloc(sizeof(NodeT*));
        p->code=code;
        p->next=a;
        a=p;
    }
    else
    {
        NodeT *p=(NodeT*)malloc(sizeof(NodeT));
        p->code=code;
        p->next=a;
        a=p;
    }
}

void addlast(NodeT *a , int code)
{
    if(a==NULL)
    {
        a=(NodeT*)malloc(sizeof(NodeT*));
        a->code=code;
        a->next=NULL;
    }
    else
    {
        nodeT *aux= a;
        nodeT *aux1=NULL;
        nodeT *d=(nodeT*)malloc(sizeof(nodeT*));
        d->code=code;
        while(aux != NULL)
        {
            aux1=aux;
            aux=aux->next;
        }

}

void printlist(nodeT *a)
{
    NodeT* aux=a;
    while(aux!=NULL)
    {
        fprintf(pf,"%d ",aux->code);
        aux=aux->next;
    }
    fprintf(pf,"\n");
}

int main()
{
    f=fopen("input.txt","r");
    if(f==NULL) perror("Cannot be opened");
    pf=fopen("output.txt","w");
    if(pf==NULL) perror("Cannot be written");

    int n;
    while( fscanf(f,"%d ",&n)>0)//reading the first line
    {
        addlast(&aa,n);  // creating the first list;
    }
    char x;
    fscanf(f,"%c\n",&x);     // going to the second line

    while(fscanf(f,"%d ",&n)> 0)
    {
        addlast(&bb,n);

    }
    intersect(&aa,&bb);
    printlist(&aa);
    fclose(f);
    fclose(pf);

    return 0;
}
