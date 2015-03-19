#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} NODE;

typedef struct  santinel
{
    NODE *head;
    NODE *tail;
}san;

 void init(san *s)
 {
     s->head=NULL;
     s->tail=NULL;
 }

void print_all(san *s,FILE *g)
{
    NODE* x=s->head;
    while(x!=NULL)
    {
        fprintf(g,"%d ", x->data);
        x=x->next;
    }
    fprintf(g, "\n");
}

void Add_first(san *s,int data)
{
    if(s->head == NULL)
    {
        s->head = (NODE*)malloc(sizeof(NODE));
        s->head->data = data;
        s->head->next = NULL;
        s->tail = s->head;
    }
    else
    {
        NODE *new;
        new = (NODE*)malloc(sizeof(NODE));
        new->data = data;
        new->next = s->head;
        s->head->prev = new;
        s->head = new;
    }
}

void Add_last(san *s,int data)
{
    if(s->head == NULL)
    {
        s->head = (NODE*)malloc(sizeof(NODE));
        s->head->data = data;
        s->head->next = NULL;
        s->tail = s->head;
    }
    else
    {
        NODE *new;
        new = (NODE*)malloc(sizeof(NODE));
        new->data=data;
        new->next = NULL;
        s->tail->next = new;
        new -> prev = s->tail;
        s->tail = new;
    }
}

void Delete_first(san *s)
{
    NODE *new;
    new = s->head->next;
    free(s->head);
    s->head = new;
}

void Delete_last(san *s)
{
    NODE *x=s->tail;
    x->prev->next=NULL;
    s->tail = x->prev;
}

void Doom_list(san *s)
{
    NODE *x=s->head;
    if(s->head==NULL)
        return;
    else
    {
        while(x!=NULL)
        {
            s->head = x->next;
            free(x);
            x=s->head;
        }
        s->tail=NULL;
    }
}
void Delete_x(san *s,int data)
{
    NODE *x=s->head;
    if(s->head==NULL)
        return ;
    else
    {
        while (x!=NULL)
        {
            if(x->data==data)
            {
                (x->prev)->next=x->next;
                (x->next)->prev= x->prev;
                free(x);
            }
            else
                x=x->next;
        }
    }
}

void print_f(san *s,FILE *g,int data)
{
    NODE *x=s->head;
    while(x!=NULL && data!=0)
    {
        fprintf(g,"%d ",x->data);
        data=data-1;
        x= x->next;
    }
    fprintf(g,"\n");

}

void print_l(san *s,FILE *g, int data)
{
    NODE *x=s->tail;
    int i;
    for(i=data; i>0; i--)
    {
        fprintf(g,"%d ",x->data);
        x=x->prev;
    }
}
int main()
{
    FILE	*f, *g;
    char	*wtd; //what to do
    int		data;
    san *s;
    s=(san*)malloc(sizeof(san));
    init(s);
    f = fopen("input.txt", "r");
    g = fopen("output.txt", "w");
    if(f==NULL)
        perror("File error");
    if(g==NULL)
        perror("File error");
    wtd = (char *)malloc(sizeof(char) * 20);

    while (fscanf(f, "%s", wtd) == 1)
    {
        fscanf(f, "%d", &data);
        if (strcmp(wtd, "AF") == 0)
            Add_first(s,data);
        else if (strcmp(wtd, "AL") == 0)
            Add_last(s,data);
        else if (strcmp(wtd, "DF") == 0)
            Delete_first(s);
        else if (strcmp(wtd, "DL") == 0)
            Delete_last(s);
        else if (strcmp(wtd, "DOOM_THE_LIST") == 0)
            Doom_list(s);
        else if (strcmp(wtd, "DE") == 0)
            Delete_x(s,data);
        else if (strcmp(wtd, "PRINT_ALL") == 0)
            print_all(s,g);
        else if (strcmp(wtd, "PRINT_F") == 0)
            print_f(s,g, data);
        else if (strcmp(wtd, "PRINT_L") == 0)
            print_l(s,g, data);
    }
    fclose(f);
    fclose(g);
    return 0;
}
