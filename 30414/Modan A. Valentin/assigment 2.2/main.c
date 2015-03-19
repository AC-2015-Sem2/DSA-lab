# include <stdio.h>

typedef struct nod
{
    int sec;
    struct nod *next;
}TIME;

typedef struct node
{
    int time,money;
    struct node *next;
}NODE;

TIME *peek,*last;
NODE *head,*tail;

void enqueve(int time)
{    TIME *newnode;
    if(peek==NULL)
    {
        peek=(TIME*)malloc(sizeof(TIME));
        peek->sec=time;
        peek->next=NULL;
        last=peek;

    }

    else
    {
        newnode=(TIME*)malloc(sizeof(TIME));
        last->next=newnode;
        newnode->next=NULL;
        newnode->sec=time;
        last=newnode;
    }
}
void DOOM_THE_LIST()
{
    NODE *p, *position;
    p=position=head;
    head=tail=NULL;
    while(p!=NULL)
    {   p=p->next;
        free(position);
        position=p;
    }
}
void dequeve()
{
    TIME *position;
    position=peek;
    if(peek!=NULL)
    {
        peek=peek->next;
        free(position);
    }
}

void AL(int money,int time)
{
    NODE *newnode;
    if(head==NULL)
    {
        head=(NODE*)malloc(sizeof(NODE));
        head->time=time;
        head->money=money;
        head->next=NULL;
        tail=head;

    }

    else
    {
        newnode=(NODE*)malloc(sizeof(NODE));
        tail->next=newnode;
        newnode->next=NULL;
        newnode->time=time;
        newnode->money=money;
        tail=newnode;
    }
}

int main()
{
    FILE *input, *output;
    input=fopen("input.dat","r");
    output=fopen("output.dat","w");

    int t,n;
    int suma1,sumab;
    char s[1024];
    NODE *p;
    while(fscanf(input,"%d",&t))
         enqueve(t);
    while(fscanf(input,"%s",s)!=EOF)
    {
        fscanf(input,"%d",&n);
        fscanf(input,"%d",&t);
        AL(n,t);
    }

    while(peek!=NULL)
    {
    suma1=sumab=0;
      p=head;
      while((suma1+p->time<=peek->sec)&&(p->next!=NULL))
      {
          sumab=sumab+p->money;
          suma1=suma1+p->time;
          p=p->next;
      }
      if(p->next==NULL)
        sumab=sumab+p->money;
      fprintf(output,"after %d seconds: %d\n",peek->sec,sumab);
      dequeve();
    }
    return 0;
}
