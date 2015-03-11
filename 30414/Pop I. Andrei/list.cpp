# include <stdio.h>
# include <stdlib.h>
# include <string.h>
using namespace std;

typedef struct nod
{
    int data;
    struct nod *next;
}NODE;


NODE *head, *tail;

void printAll(FILE *out)
{
    NODE *p=head;

    while(p!=NULL)
    {
        fprintf(out, "%d ", p->data);
        p=p->next;
    }

    fprintf(out, "\n");
}

void addFirst(int data)
{
    if(head==NULL)
    {
        head=(NODE*) malloc(sizeof(NODE));
        head->next=NULL;
        tail=head;
        head->data=data;
    }

    else
    {
        NODE *newnode=(NODE*) malloc(sizeof(NODE));
        newnode->next=head;
        head=newnode;
        newnode->data=data;
    }
}

void addLast(int data)
{
    if(head==NULL)
    {
        head=(NODE*) malloc(sizeof(NODE));
        head->next=NULL;
        tail=head;
        head->data=data;
    }

    else
    {
        NODE *newnode;
        newnode=(NODE*) malloc(sizeof(NODE));
        newnode->data=data;

        newnode->next=NULL;
        tail->next=newnode;
        tail=newnode;
    }
}

void delFirst()
{
    NODE *curent;
    curent=head;

    if(head!=NULL)
    {
        head=head->next;
        free(curent);
    }
}

void delLast()
{
    NODE *curent=head;

    if(tail!=NULL)
    {
        while(curent->next!=tail)
            curent=curent->next;

        tail=curent;
        curent=curent->next;
        tail->next=NULL;
        free(curent);
    }
}

void ddl()
{
    NODE *p, *curent;
    p=head;

    head=tail=NULL;

    curent=p;
    if(p!=NULL)
        p=p->next;

    while(p!=NULL)
    {
        free(curent);
        curent=p;
        p=p->next;
    }
}

void delX(int x)
{
    NODE *p, *curent;

    if(head==NULL || head->data==x)
        delFirst();
    else
    {
        curent=p=head;
        p=p->next;

        while(p!=NULL && p->data!=x)
        {
            curent=p;
            p=p->next;
        }

        if(p!=NULL)
        {
            curent->next=p->next;
            free(p);
        }
    }
}

void printF(int nr, FILE *g)
{
    int elem=1;
    NODE *p=head;

    while(elem <= nr && p!=NULL)
    {
        fprintf(g,"%d ", p->data);
        p=p->next;
        elem+=1;
    }
    fprintf(g, "\n");

}

void printL(int nr, FILE *out)
{
    int cate=0;

    NODE *p=head;

    while(p!=NULL)
    {
        p=p->next;
        cate+=1;
    }

    if(nr>=cate)
        printAll(out);
    else
    {
        p=head;
        for(int i=1; i<=cate-nr; i++)
            p=p->next;

        while(p!=NULL)
        {
            fprintf(out, "%d ", p->data);
            p=p->next;
        }
        fprintf(out,"\n");
    }
}

int main()
{
    FILE *in, *out;

    char op[15]; //op is the vector in which I read the operation that the program will compute
    int data;

    in=fopen("input.dat", "r");
    if(in==NULL)
    {
        perror("error opening file");
        exit(1);
    }

    out=fopen("output.dat", "w");

    while(fscanf(in, "%s", op)!=EOF)
    {

        if(strcmp(op, "AF")==0)
        {
            fscanf(in, " %d", &data);
            addFirst(data);
        }
        else if(strcmp(op, "AL")==0)
        {
            fscanf(in, " %d", &data);
            addLast(data);
        }
        else if(strcmp(op, "DF")==0)
            delFirst();
        else if(strcmp(op, "DL")==0)
            delLast();
        else if(strcmp(op, "PRINT_ALL")==0)
            printAll(out);
        else if(strcmp(op, "DOOM_THE_LIST")==0)
            ddl();
        else if(strcmp(op, "DE")==0)
        {
            fscanf(in, " %d", &data);
            delX(data);
        }
        else if(strcmp(op, "PRINT_F")==0)
        {
            fscanf(in, " %d", &data);
            printF(data, out);
        }
        else
        {
            fscanf(in, " %d", &data);
            printL(data, out); //this is tricky because first we have to go trough the whole list and count how many elements it has (nr)
            //if the number (nr) of elem is less or equal to x we print the whole list
            //else we jump over the first nr-x elements and we print the last x elements
        }
    }

    return 0;
}

