#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int code;
    struct node* next;
} NodeT;
NodeT* head;
NodeT* tail;
void addFirst(int code)
{
    if(head==NULL)
    {
        head = (NodeT*)(malloc(sizeof(NodeT*)));
        head->code=code;
        head->next=NULL;
    }
    else if(tail==head)
    {
        NodeT* now=(NodeT*)malloc(sizeof(NodeT*));
        now->code=code;
        now->next=head;
        tail=head;
        head=now;

    }
    else
    {
        NodeT* nod;
        nod=(NodeT*)malloc(sizeof(NodeT*));
        nod->next = head;
        nod->code=code;
        head=nod;
    }
}
void addLast(int code)
{
    if (head==NULL)
    {
        head=(struct node*)malloc(sizeof(struct node*));
        head->code=code;
        head->next=NULL;
    }
    else
    {
        if (tail==head)
        {
            struct node *p=(struct node*)malloc(sizeof(struct node*));
            p->code=code;
            p->next=NULL;
            tail=p;
            head->next=tail;
        }
        else
        {
            struct node *p=(struct node*)malloc(sizeof(struct node*));
            p->code=code;
            p->next=NULL;
            tail->next=p;
            tail=p;
        }
    }
}
void removeNod(int code)
{
    NodeT* q,*q1;
    q1=NULL;
    q=head;
    while(q!=NULL)
    {
        if(q->code==code)
            break;
        q1=q;
        q=q->next;
    }
    if(q!=NULL)
    {
        if(q==head)
        {
            head=head->next;
            free(q);
            if(head==NULL)
                tail=NULL;
        }
        else
        {
            q1->next=q->next;
            if(q==tail)
                tail=q1;
            free(q);
        }
    }
}
void deletefirst()
{
    NodeT* q,*q1;
    q=head;
    head=head->next;
    free(q);
}
void deletelast()
{
    if(head!=NULL)
    {
        NodeT *aux=head;
    while(aux->next!=tail)
    {
        aux=aux->next;
    }
    aux->next=NULL;
    free(tail);
    tail=aux;
    }

}
void doomthelist()
{
    NodeT* p,*aux=head;
    while(aux!=NULL)
    {
        p=aux;
        aux=aux->next;
        free(p);
    }
    tail=NULL;
    head=NULL;

}
void printList(FILE *file)
{
    NodeT* aux=head;
    fprintf(file,"\n");
    while(aux!=NULL)
    {
        fprintf(file,"%d ",aux->code);
        aux=aux->next;
    }

}
void printbefore(int n,FILE *file)
{
    int i=0;
    NodeT* aux=head;
    fprintf(file,"\n");
    for(i=0; i<n; i++)
    {
        fprintf(file,"%d ",aux->code);
        aux=aux->next;
    }

}
void printafter(int n,FILE *file)
{
    int nr=0,i=0;
    NodeT* aux[100];
    aux[0]=head;
    fprintf(file,"\n");
    while(aux[i]->next!=NULL)
    {
        nr++;
        aux[i+1]=aux[i]->next;
        i++;
    }
    for(i=nr+1-n; i<nr+1; i++)
    {
        fprintf(file,"%d ",aux[i]->code);
    }
}
int main()
{
    FILE *file,*file2;
    file= fopen("input.dat","r");
    file2=fopen("output.dat","w");
    if (file==NULL)
    {
        perror("Cannot read file");
        return -200;
    }
    char line[1000];
    int number;
    while(fscanf(file,"%s",line)!=EOF)
    {

        //printf("\n%s",line);
        if(strcmp(line,"AF")==0)
        {
            fscanf(file,"%s",line);
            number=atoi(line);
            addFirst(number);
        }
        if(strcmp(line,"AL")==0)
        {
            fscanf(file,"%s",line);
            number=atoi(line);
            addLast(number);
        }
        if(strcmp(line,"DF")==0)
        {
            deletefirst();
        }
        if(strcmp(line,"DL")==0)
        {
            deletelast();
        }
        if(strcmp(line,"PRINT_ALL")==0)
        {
            printList(file2);
        }
        if(strcmp(line,"PRINT_F")==0)
        {
            fscanf(file,"%s",line);
            number=atoi(line);
            printbefore(number,file2);
        }
        if(strcmp(line,"PRINT_L")==0)
        {
            fscanf(file,"%s",line);
            number=atoi(line);
            printafter(number,file2);
        }
        if(strcmp(line,"DE")==0)
        {
            fscanf(file,"%s",line);
            number=atoi(line);
            removeNod(number);
        }
        if(strcmp(line,"DOOM_THE_LIST")==0)
        {
            doomthelist();
        }

    }
    fclose(file);
    return 0;
}
