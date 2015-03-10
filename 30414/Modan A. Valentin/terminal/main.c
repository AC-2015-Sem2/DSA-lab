# include <stdio.h>

typedef struct nod
{
    int data;
    struct nod *next;
}NODE;

NODE *head, *tail;

void PRINT_ALL(FILE *output)
{   NODE *p;
    p=head;

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
    p=position=head;
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
    NODE *p=head;
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
    if(head==NULL)
    {
        head=(NODE*) malloc(sizeof(NODE));
        head->data=data;
        head->next=NULL;
        tail=head;
    }

    else
    {
        newnode=(NODE*) malloc(sizeof(NODE));
        newnode->data=data;
        newnode->next=head;
        head=newnode;
    }
}

void AL(int data)
{    NODE *newnode;
    if(head==NULL)
    {
        head=(NODE*) malloc(sizeof(NODE));
        head->data=data;
        head->next=NULL;
        tail=head;

    }

    else
    {
        newnode=(NODE*) malloc(sizeof(NODE));
        tail->next=newnode;
        newnode->next=NULL;
        newnode->data=data;
        tail=newnode;
    }
}

void DF()
{   NODE *position;
    position=head;
    if(head!=NULL)
    {
        head=head->next;
        free(position);
    }
}

void DL()
{   NODE *position;
    position=head;
    if(tail!=NULL)
    {
        while(position->next!=tail)
            position=position->next;

        tail=position;
        position=position->next;
        tail->next=NULL;
        free(position);
    }
}

void DOOM_THE_LIST()
{   NODE *p,*position;
    p=position=head;
    head=tail=NULL;
    while(p!=NULL)
    {   p=p->next;
        free(position);
        position=p;
    }
}

void DE(int x)
{
    NODE *p, *position,*obliterate;
    while(head!=NULL&&head->data==x)
        DF();
    while(tail!=NULL&&tail->data==x)
        DL();
        position=p=head;
        p=p->next;
        while(p!=NULL)
        {
            while(p!=NULL&&p->data==x)
            {
                position->next=p->next;
                obliterate=p;
                p=p->next;
                free(obliterate);
            }

            position=p;
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
