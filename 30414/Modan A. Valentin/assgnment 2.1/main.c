# include <stdio.h>

typedef struct nod
{
    int data;
    struct nod *next;
    struct nod *previous;

}NODE;
typedef struct node
{
    NODE *head,*tail;
}SENTINEL;

SENTINEL *lista;
void PRINT_ALL(FILE *output)
{   NODE *p;
    //p=lista->lista->head;
    p=lista->head;
    //p=lista->head;

    while(p!=NULL)
    {
        fprintf(output,"%d ", p->data);
        p=p->next;
    }
    fprintf(output,"\n");

}
void PRINT_L(int nr,FILE *output)
{
    int aux=nr;
    NODE *p,*position;
    p=position=lista->head;
    while(p!=NULL&&aux>0)
    {
        p=p->next;
        aux--;
    }
    while(p!=NULL)
    {
        p=p->next;
        position=position->next;
    }
    while(position!=NULL)
    {
        fprintf(output,"%d ",position->data);
        position=position->next;
    }
    fprintf(output,"\n");
}
void PRINT_F(int nr,FILE *output)
{
    NODE *p=lista->head;
    while(nr>0&&p!=NULL)
    {
        fprintf(output,"%d ",p->data);
        p=p->next;
        nr--;
    }
    fprintf(output,"\n");

}
void AF(int data)
{
       NODE *newnode;
    if(lista->head==NULL)
    {
        lista->head=(NODE*) malloc(sizeof(NODE));
        lista->head->data=data;
        lista->head->next=NULL;
        lista->head->previous=NULL;
        lista->tail=lista->head;
    }

    else
    {
        newnode=(NODE*) malloc(sizeof(NODE));
        newnode->data=data;
        newnode->next=lista->head;
        newnode->previous=NULL;
        lista->head=newnode;
    }
}

void AL(int data)
{    NODE *newnode;
    if(lista->head==NULL)
    {
        lista->head=(NODE*) malloc(sizeof(NODE));
        lista->head->data=data;
        lista->head->next=NULL;
        lista->head->previous=NULL;
        lista->tail=lista->head;

    }

    else
    {
        newnode=(NODE*) malloc(sizeof(NODE));
        lista->tail->next=newnode;
        newnode->next=NULL;
        newnode->previous=lista->tail;
        newnode->data=data;
        lista->tail=newnode;
    }
}

void DF()
{   NODE *position;
    position=lista->head;
    if(lista->head!=NULL)
    {
        lista->head=lista->head->next;
        lista->head->previous=NULL;
        free(position);
    }
}

void DL()
{   NODE *position;
    position=lista->tail;
    if(lista->tail!=NULL)
    {
        lista->tail=lista->tail->previous;
        lista->tail->next=NULL;
        free(position);
    }

}

void DOOM_THE_LIST()
{
    while(lista->head->next!=NULL)
    {
        lista->head=lista->head->next;
        free(lista->head->previous);
         lista->head->previous=NULL;

    }
    free(lista->head);
    lista->tail=lista->head=NULL;

}

void DE(int x)
{
    NODE *p, *position,*obliterate;
    while(lista->head!=NULL&&lista->head->data==x)
        DF();
    while(lista->tail!=NULL&&lista->tail->data==x)
        DL();
        position=p=lista->head;
        p=p->next;
        while(p!=NULL)
        {
            while(p!=NULL&&p->data==x)
            {
                position=p;
                p->previous->next=p->next;
                p->next->previous=p->previous;
                p=p->next;
                free(position);
            }
            p=p->next;
        }


}
int main()
{
    FILE *input, *output;
    input=fopen("input.dat","r");
    output=fopen("output.dat","w");
    int x;
    char c[1024];

lista = (SENTINEL*) malloc(sizeof(SENTINEL));
    lista->head=0;
    lista->tail=0;
    while(fscanf(input,"%s",c)!=EOF)
    {
        if(strcmp(c,"PRINT_ALL")==0)
                PRINT_ALL(output);
        else
            if(strcmp(c,"AF")==0)
            {
                fscanf(input,"%d",&x);
                AF(x);
            }
        else
            if(strcmp(c,"AL")==0)
            {
                fscanf(input,"%d",&x);
                AL(x);
            }
        else
            if(strcmp(c,"DF")==0)
                DF();
        else
            if(strcmp(c,"DL")==0)
                DL();
        else
            if(strcmp(c,"DOOM_THE_LIST")==0)
                DOOM_THE_LIST();
        else
            if(strcmp(c,"DE")==0)
            {
                fscanf(input,"%d",&x);
                DE(x);
            }
        else
            if(strcmp(c,"PRINT_F")==0)
            {
                fscanf(input,"%d",&x);
                PRINT_F(x,output);
            }
        else
            if(strcmp(c,"PRINT_L")==0)
            {
                fscanf(input,"%d",&x);
                PRINT_L(x,output);
            }
    }
    return 0;
}
