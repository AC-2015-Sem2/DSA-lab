# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct node
{
    int data;
    struct node *next,*prev;
}node;

typedef struct sent
{
    int nr;
    node *head,*tail;
}sent;
sent *p=(sent*)malloc(sizeof(sent));

void AddFirst(int data){
    if(p->head==0)
    {
        p->head=(node*) malloc(sizeof(node));
        p->head->next=0;
        p->head->prev=0;
        p->tail=p->head;
        p->head->data=data;
        p->nr+=1;
    }
    else
    {
        node *aux=(node*) malloc(sizeof(node));
        aux->next=p->head;
        p->head->prev=aux;
        aux->prev=0;
        p->head=aux;
        aux->data=data;
        p->nr+=1;
    }
}
void AddLast(int data){
    if(p->head==0)
    {
        p->head=(node*) malloc(sizeof(node));
        p->head->next=0;
        p->head->prev=p->tail;
        p->tail=p->head;
        p->head->data=data;
        p->nr+=1;
    }
    else
    {
        node *aux=(node*) malloc(sizeof(node));
        aux->data=data;
        aux->next=0;
        aux->prev=p->tail;
        p->tail->next=aux;
        p->tail=aux;
        p->nr+=1;
    }
}
void DeleteFirst(){
    node *aux=p->head;
    if(p->head!=0)
    {
        p->head->next->prev=0;
        p->head=p->head->next;
        free(aux);
        p->nr-=1;
    }
}
void DeleteLast(){
    node *aux=p->tail;
    if(aux!=0)
    {
        aux->prev->next=0;
        p->tail=aux->prev;
        free(aux);
    }
}
void DeleteElem(int x){
    node *aux;

    if(p->head==0 || p->head->data==x)
        DeleteFirst();
    else
        if(p->tail->data==x)
            DeleteLast();
        else
        {
            aux=p->head;

            while(aux!=NULL && aux->data!=x)
                aux=aux->next;

            if(aux!=0)
            {
                aux->prev->next=aux->next;
                aux->next->prev=aux->prev;
                free(aux);
            }
        }
}
void Doom_The_List(){
    node *aux, *aux2;
    aux=p->head;
    p->head=0;
    p->tail=0;
    if(aux!=0)
        aux=aux->next;
    while(aux!=0)
    {
        free(aux2);
        aux2=aux;
        aux=aux->next;
    }
    p->nr=0;
}
void PrintAll(FILE *f2){
    node *aux=p->head;
    while(aux!=0)
    {
        fprintf(f2, "%d ", aux->data);
        aux=aux->next;
    }

    fprintf(f2, "\n");
}
void PrintFirst(int x, FILE *f2){
    int q=1;
    node *aux=p->head;

    while(q <= x && aux!=0)
    {
        fprintf(f2,"%d ", aux->data);
        aux=aux->next;
        q+=1;
    }
    fprintf(f2, "\n");

}
void PrintLast(node *aux, int nr, FILE *f2){
    if(aux==0 || nr==0)
    {
        return;
        if(aux!=0)
            fprintf(f2, "%d ", aux->data);
    }

    PrintLast(aux->prev, nr-1, f2);
    fprintf(f2, "%d ", aux->data);
}

int main()
{
    FILE *f1=fopen("input.dat","r");
    FILE *f2=fopen("output.dat","w");
    char s[15];
    int data;
    p->head=0;
    p->tail=0;

    while(fscanf(f1, "%s", s)==1)
    {
        if(strcmp(s, "AF")==0)
        {
            fscanf(f1, " %d", &data);
            AddFirst(data);
        }
        if(strcmp(s, "AL")==0)
        {
            fscanf(f1, " %d", &data);
            AddLast(data);
        }
        if(strcmp(s, "DF")==0)
            DeleteFirst();
        if(strcmp(s, "DL")==0)
            DeleteLast();
        if(strcmp(s, "DE")==0)
        {
            fscanf(f1, "%d", &data);
            DeleteElem(data);
        }
        if(strcmp(s, "DOOM_THE_LIST")==0)
            Doom_The_List();
        if(strcmp(s, "PRINT_ALL")==0)
            PrintAll(f2);
        if(strcmp(s, "PRINT_F")==0)
        {
            fscanf(f1, "%d", &data);
            PrintFirst(data, f2);
        }
        if (strcmp(s,"PRINT_L")==0)
        {
            fscanf(f1, "%d", &data);
            PrintLast(p->tail, data, f2);
            fprintf(f2, "\n");
        }
    }

    return 0;
}
