#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*I have 2 lists here. In the first are the time values from the first row. The second one contains the money spent by
people and how much time they spent at cashier. Firstly I read the data from the file and than check if in the first list
(with time)is <= than the sum of time values from the second list(names,money,time), if not I delete the head of (time)list
and continue with the second node of it. The summing of the time values from the second list works similar. If I added the
actual nodes time value to the sum I delete the first node and contiunue with the 2nd, and so on...
*/

typedef struct node{
    //char name[20];
    int  time, money;
    struct node* next;
    //struct node* prev;
}node;


node *head,*tail;
node *thead,*ttail;

void addTime(int time)
{
    node *t;
    t=(node*)malloc(sizeof(node));
    t->time=time;
    t->next=NULL;

    if(thead==NULL)
    {
        thead=t;
    }
    else
    {
        ttail->next=t;
    }
    ttail=t;
}
void addLast(/*char name[20],*/int money, int time)
{
    node *a;
    a=(node*)malloc(sizeof(node));
    //strcpy(a->name,name);
    a->money=money;
    a->time=time;
    a->next=NULL;
    //a->prev=NULL;

    if(head==NULL)
    {
      head=a;
    }
    else
    {
        //a->prev=tail;
        tail->next=a;
    }
    tail=a;
}
void deleteFirst()
{
    if (head==NULL)
        return;
    else
    {
        node *aux=head;
        head=head->next;
        free(aux);
    }
}
void tdeleteFirst()
{
    if (thead==NULL)
        return;
    else
    {
        node *aux=thead;
        thead=thead->next;
        free(aux);
    }
}
void print()
{
    node *a;
    a=head;
    while (a!=NULL)
    {
        printf("%d %d ",a->money, a->time);
        a=a->next;
    }
    printf("\n");
}
void tprint()
{
    node *a;
    a=thead;
    while (a!=NULL)
    {
        printf("%d ",a->time);
        a=a->next;
    }
    printf("\n");
}
int main()
{
    int T;
    FILE *f,*g;
    f=fopen("input.dat","r");
    if (f==NULL)
    {
        perror("File not found");
        exit(EXIT_FAILURE);
    }
    g=fopen("output.dat","w");

    //read time
    char c;
        fscanf(f,"%d",&T);addTime(T);         //reading the first time value separately because the getc() function
    while((c=getc(f))!='\n')                 //moves forward the cursor in the file and I could only read the number
    {                                       //from the second position in the file
        fscanf(f,"%d",&T);
        addTime(T);
    }
    char name[20];int money, time, k=1;
    while(k==1)
    {
        fscanf(f," %s %d %d",name, &money,&time);
        if(name[0]=='\0') k=0;
        else (addLast(money,time));//print();}
        name[0]='\0';
    }

    int seconds=0,cash=0;

    while(thead!=NULL)
    {   int ok=1;
        //T=thead->time;
        node *aux;
        if(head!=NULL) aux=head;

        while(ok==1)/*seconds+aux->time<=thead->time*/
        {
            if((seconds+aux->time<=thead->time)&&(head!=NULL))
            {
                cash=cash+aux->money;
                seconds=seconds+aux->time;
                deleteFirst();
                if(head!=NULL) aux=head;
            }
            else
            {
                fprintf(g,"%s %d %s %d\n","After",thead->time,"seconds:",cash);
                tdeleteFirst();
                ok=0;
            }

        }
    }
fclose(f);
fclose(g);
    return 0;
}
