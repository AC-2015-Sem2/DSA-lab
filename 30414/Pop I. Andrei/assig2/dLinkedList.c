# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct nod
{
    int data;
    struct nod *next;
    struct nod *prev;
}NODE;

typedef struct nod1
{
    int nr;
    NODE *head;
    NODE *tail;
}SEN;

SEN *boss;

void printAll(FILE *out)
{
    NODE *p=boss->head;

    while(p!=NULL)
    {
        fprintf(out, "%d ", p->data);
        p=p->next;
    }

    fprintf(out, "\n");
}

void addFirst(int data)
{
    if(boss->head==NULL)
    {
        boss->head=(NODE*) malloc(sizeof(NODE));
        boss->head->next=NULL;
        boss->head->prev=NULL;
        boss->tail=boss->head;
        boss->head->data=data;
        boss->nr+=1;
    }

    else
    {
        NODE *newnode=(NODE*) malloc(sizeof(NODE));
        newnode->next=boss->head;
        boss->head->prev=newnode;
        newnode->prev=NULL;
        boss->head=newnode;
        newnode->data=data;
        boss->nr+=1;
    }
}

void addLast(int data)
{
    if(boss->head==NULL)
    {
        boss->head=(NODE*) malloc(sizeof(NODE));
        boss->head->next=NULL;
        boss->head->prev=boss->tail;
        boss->tail=boss->head;
        boss->head->data=data;
        boss->nr+=1;
    }

    else
    {
        NODE *newnode=(NODE*) malloc(sizeof(NODE));
        newnode->data=data;
        newnode->next=NULL;
        newnode->prev=boss->tail;
        boss->tail->next=newnode;
        boss->tail=newnode;
        boss->nr+=1;
    }
}

void delFirst()
{
    NODE *curent=boss->head;

    if(boss->head!=NULL)
    {
        boss->head->next->prev=NULL;
        boss->head=boss->head->next;
        free(curent);
        boss->nr-=1;
    }
}

void delLast()
{
    NODE *myNode=boss->tail;

    if(myNode!=NULL)
    {
        myNode->prev->next=NULL;
        boss->tail=myNode->prev;
        free(myNode);
    }
}

void ddl()
{
    NODE *p, *curent;
    p=boss->head;

    boss->head=boss->tail=NULL;

    curent=p;
    if(p!=NULL)
        p=p->next;

    while(p!=NULL)
    {
        free(curent);
        curent=p;
        p=p->next;
    }
    boss->nr=0;
}

void delX(int x)
{
    NODE *myNode;

    if(boss->head==NULL || boss->head->data==x)
        delFirst();
    else
        if(boss->tail->data==x)
            delLast();
        else
        {
            myNode=boss->head;

            while(myNode!=NULL && myNode->data!=x)
                myNode=myNode->next;

            if(myNode!=NULL)
            {
                myNode->prev->next=myNode->next;
                myNode->next->prev=myNode->prev;
                free(myNode);
            }
        }
}

void printF(int nr, FILE *g)
{
    int elem=1;
    NODE *myNode=boss->head;

    while(elem <= nr && myNode!=NULL)
    {
        fprintf(g,"%d ", myNode->data);
        myNode=myNode->next;
        elem+=1;
    }
    fprintf(g, "\n");

}

void printL(NODE *myNode, int nr, FILE *out)
{
    if(myNode==NULL || nr==0)
    {
        return;
        if(myNode!=NULL)
            fprintf(out, "%d ", myNode->data);
    }

    printL(myNode->prev, nr-1, out);
    fprintf(out, "%d ", myNode->data);
}

int main()
{
    FILE *in, *out;

    char op[15]; //op is the vector in which I read the operation that the program will compute
    int data;

    boss = (SEN*) malloc(sizeof(SEN));
    boss->head=0;
    boss->tail=0;

    in=fopen("input1.dat", "r");
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
            printL(boss->tail, data, out);
            fprintf(out, "\n"); //this is tricky because first we have to go trough the whole list and count how many elements it has (nr)
            //if the number (nr) of elem is less or equal to x we print the whole list
            //else we jump over the first nr-x elements and we print the last x elements
        }
    }

    return 0;
}


