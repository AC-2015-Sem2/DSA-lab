#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} NodeT, temp;

struct list_heather
{
    NodeT *first;
    NodeT *last;
};
void create ()
{
    int data;
    temp=
}


/*struct list_heather *L;
//create the list
L->first=L->last=NULL;
//insert a node
if (L->first=NULL)
{
    L->first=L->last=p;
    p->prev=L->last;
    L->last=p;
}
else
{
    L->last->next=p;
    p->prev=L-last;
    L->last=p;
}*/


void addFirst(int p)
    if(L->first==NULL)
    {
        L->first=L->last=p;
        p->next=p->prev=NULL;
    }
    else
    {
        p->next=L->first;
        p->prev=NULL;
        L-first->prev=p;
        L->first=p;
    }
}

void addLast()
{
    if(L->first==NULL)
    {
        L->first=L->last=p;
        p->next=p->prev=NULL;
    }
    else
    {
        p->next=NULL;
        p->prev=L->last;
        L->last->next=p;
        L->last=p;
    }
}

void addGivenKey()
{
    p->prev=q;
    p->next=q->next;
    if (q->next!=NULL)
        q->next->prev=p;
    q->next=p;
    if(L->last==q)
        L->last=p;
}

void deleteFirst ()
{
    p=L->first;
    L->first=L->first->next;
    free(p);
    if(L->first==NULL)
        L->last=NULL;
    else
        L->first->prev=NULL;
}

void deleteLast()
{
    p=L->last;
    L->last=L->last->prev;
    if(L->last==NULL)
        L->first=NULL;
    else
        L->last->next=NULL;
}

void deleteGiven()
{
    if((L->first==p)&&(L->last==p))
    {
        L−>first=NULL;
        L−>last=NULL;
        free(p);
    }
    else if(p==L->first)
    {
        L->first=L->first->next;
        L->first->prev=NULL;
        free(p);
    }
    else
    {
        p->next->prev=p->prev;
        p−>prev−>next=p->next ;
        free(p) ;
    }
}

void deleteList()
{
    while(L->first!=NULL)
    {
        p=L->first;
        L->first=L->first->next ;
        free(p);
    }
    L->last=NULL;
}

int main()
{
    FILE *fd;
    FILE *f;
    char txts[20];
    int code;
    fd = fopen("input.txt", "r");
    if (fd==NULL)
    {
        perror("Cannot open file!");
        return -200;
    }
    f = fopen("output.txt", "w");
    if (f==NULL)
    {
        perror("Cannot create file!");
        return-100;
    }
    while(fscanf(fd,"%s %d\n", txts, &code) > 0)
    {
        if (strcmp(txts, "AF") == 0)
        {
            addFirst(code);
        }
        else if (strcmp(txts, "AL") == 0)
        {
            AddLast(code);
        }
        else if (strcmp(txts, "DF") == 0)
        {
            RemoveFirst();
        }
        else if (strcmp(txts, "DL") == 0)
        {
            RemoveLast();
        }
        else if (strcmp(txts, "DOOM_THE_LIST") == 0)
        {
            DeleteList();
        }
        else if (strcmp(txts, "DE") == 0)
        {
            RemoveNodeX(code);
        }
        else if (strcmp(txts, "PRINT_ALL") == 0)
        {
            printList(f);
            fprintf(f, " \n");
        }
        else if (strcmp(txts, "PRINT_F") == 0)
        {
            printListFront(f, code);
            fprintf(f, " \n");
        }
        else if (strcmp(txts, "PRINT_L") == 0)
        {
            PrintListLast(f, code);
            fprintf(f, " \n");
        }
    }
    fclose(fd);
    fclose(f);
    return 0;
}
