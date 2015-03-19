#include "DLL.h"
#include <stdio.h>
#include <stdlib.h>
#include "DLL_TYPES.h"



void AF(sentinel s, int x)
{
    if (*(s.length)==0)
    {
        s.head->code=s.tail->code=x;
        s.head->next=s.head->prew=NULL;
        s.tail->next=s.tail->prew=NULL;
    }
    else if(*(s.length)==1)
    {
        s.head->code=x;
        s.head->next=s.tail;
        s.tail->prew=s.head;
    }
    else
    {
        NodeT*p=(NodeT*)malloc(sizeof(NodeT*));
        p->code=s.head->code;
        p->next=s.head->next;
        p->prew=s.head;
        s.head->code=x;
        p->next->prew=p;
        s.head->next=p;
    }
    *(s.length)=*(s.length)+1;
}

void AL(sentinel s, int x)
{
    if (*(s.length)==0)
    {
        s.head->code=s.tail->code=x;
        s.head->next=s.head->prew=NULL;
        s.tail->next=s.tail->prew=NULL;
    }
    else if(*(s.length)==1)
    {
        s.tail->code=x;
        s.tail->prew=s.head;
        s.head->next=s.tail;
    }
    else
    {
        NodeT*p=(NodeT*)malloc(sizeof(NodeT*));
        s.tail->prew->next=p;
        p->code=s.tail->code;
        p->next=s.tail;
        p->prew=s.tail->prew;
        s.tail->code=x;
        s.tail->prew=p;
    }
    *(s.length)=*(s.length)+1;
}

void DF(sentinel s)
{
    if (*(s.length)>2)
    {
        NodeT*p=(NodeT*)malloc(sizeof(NodeT*));
        p=s.head->next;
        s.head->code=p->code;
        s.head->next=p->next;
        p->next->prew=s.head;
        //free(p); // ????????????????????????????
    }
    if (*(s.length)>0)
        *(s.length)=*(s.length)-1;
}

void DL(sentinel s)
{
    if (*(s.length)>2)
    {
        NodeT*p=(NodeT*)malloc(sizeof(NodeT*));
        p=s.tail->prew;
        s.tail->code=p->code;
        s.tail->prew=p->prew;
        p->prew->next=s.tail;
        //free(p); //
    }
    if (*(s.length)>0)
        *(s.length)=*(s.length)-1;
}

void DOOM_THE_LIST(sentinel s)
{
    while (*(s.length)>0)
        DF(s);
}

void DE(sentinel s, int x)
{

    if(s.head->code==x)
        DF(s);
    else if(s.tail->code==x)
        DL(s);
    else
    {
        NodeT* aux=(NodeT*)malloc(sizeof(NodeT*));
        aux=s.head;
        while((aux!=NULL)&&(aux->code!=x))
        {
            aux=aux->next;
        }
        if (aux!=NULL)
        {
            NodeT* p=aux->next;
            aux->next=aux->next->next;
            free(p);
            if (*(s.length)>0)
            *(s.length)=*(s.length)-1;
        }
    }

}

void PRINT_ALL(sentinel s)
{
    NodeT* aux=(NodeT*)malloc(sizeof(NodeT*));
    aux=s.head;
    FILE *f;
    f=fopen("output.dat","a");
    if (f==NULL)
    {
        perror("Cannot create/open file");
    }
    while(aux!=NULL)
    {
        fprintf(f,"%d ",aux->code);
        aux=aux->next;
    }
    fprintf(f,"\n");
    fclose(f);
}

void PRINT_F(sentinel s, int x)
{
    if (x>=*(s.length))
        PRINT_ALL(s);
    else
    {
        int i=0;
        NodeT*aux=s.head;
        FILE *f;
        f=fopen("output.dat","a");
        if (f==NULL)
        {
            perror("Cannot create/open file");
        }
        while(i<x&&aux!=NULL)
        {
            fprintf(f,"%d ",aux->code);
            aux=aux->next;
            i++;
        }
        fprintf(f,"\n");
        fclose(f);
    }

}

void PRINT_L(sentinel s, int x)
{
    if (x>=*(s.length))
        PRINT_ALL(s);
    else
    {
        int i=0;
        NodeT*aux=s.tail;
        FILE *f;
        f=fopen("output.dat","a");
        if (f==NULL)
        {
            perror("Cannot create/open file");
        }
        while(i<x&&aux!=NULL)
        {
            fprintf(f,"%d ",aux->code);
            aux=aux->prew;
            i++;
        }
        fprintf(f,"\n");
        fclose(f);
    }
}
