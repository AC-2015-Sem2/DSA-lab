# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct nod
{
    int s;
    struct nod *next;
}TIME;

typedef struct nod1
{
    int time,bani;
    struct nod1 *next;
}NODE;

TIME *peek,*last;
NODE *head,*tail;

void enqueve(int time)
{    TIME *newnode;
    if(peek==NULL)
    {
        peek=(TIME*)malloc(sizeof(TIME));
        peek->s=time;
        peek->next=NULL;
        last=peek;

    }

    else
    {
        newnode=(TIME*)malloc(sizeof(TIME));
        last->next=newnode;
        newnode->next=NULL;
        newnode->s=time;
        last=newnode;
    }
}

void dequeve()
{   TIME *position;
    position=peek;
    if(peek!=NULL)
    {
        peek=peek->next;
        free(position);
    }
}

void AL(int bani, int time)
{    NODE *newnode;
    if(head==NULL)
    {
        head=(NODE*)malloc(sizeof(NODE));
        head->time=time;
        head->bani=bani;
        head->next=NULL;
        tail=head;

    }

    else
    {
        newnode=(NODE*)malloc(sizeof(NODE));
        tail->next=newnode;
        newnode->next=NULL;
        newnode->time=time;
        newnode->bani=bani;
        tail=newnode;
    }
}
void DOOM_THE_LIST()
{   NODE *p, *position;
    p=head;
    position=head;
    head=NULL;
    tail=NULL;
    while(p!=NULL)
    {   p=p->next;
        free(position);
        position=p;
    }
}
int main()
{
    FILE *input, *output;
    input=fopen("input.dat","r");
    output=fopen("output.dat","w");

    int t,m,s1,s2;
    char s[1000];
    NODE *p;
    while(fscanf(input,"%d",&t))
         enqueve(t);
    while(fscanf(input,"%s",s)!=EOF)
    {
        fscanf(input,"%d",&m);
        fscanf(input,"%d",&t);
        AL(m,t);
    }

    while(peek!=NULL)
    { s1=s2=0;
      p=head;
      while((s1+p->time<=peek->s)&&(p->next!=NULL))
      {
          s2=s2+p->bani;
          s1=s1+p->time;
          p=p->next;
      }
      if(p->next==NULL)
        s2=s2+p->bani;
      fprintf(output,"after %d seconds: %d",peek->s,s2);
      fprintf(output,"\n");
      dequeve();
    }
    return 0;
}
