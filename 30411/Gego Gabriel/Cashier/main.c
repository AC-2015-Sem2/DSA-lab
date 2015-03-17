#include <stdio.h>
#include <stdlib.h>

typedef struct _node Node;
struct _node
{
    int ruble;
    int timp;
    Node *next;
};
Node *tail,*head,*node;

FILE *in,*out;

void Enqueue(int ruble,int timp)
{
    if (tail==0)
    {
        Node *temo=(Node*)malloc(sizeof(Node));
        temo->ruble=ruble;
        temo->timp=timp;
        temo->next=head;
        head=temo;
        tail=head;
    }
    else
    {
        Node *temo=(Node*)malloc(sizeof(Node));
        temo->ruble=ruble;
        temo->timp=timp;
        temo->next=0;
        tail->next=temo;
        tail=temo;
    }
}
void Dequeue()
{
    if (head!=0)
    {
        Node *temo=head;
        head=head->next;
        free(temo);
    }
}


int main()
{
    node = (Node*)malloc(sizeof(Node));
    in=fopen("input.txt","r");
    out=fopen("output.txt","w");
    int time_after[30],i=0,bani_casiera=0,timp_casiera=0,timp_clienti=0,ruble,timp;
    char nume[30];

    while(fscanf(in,"%d ",&time_after[i]))i++;
     timp_casiera=time_after[i-1];
    while(fscanf(in,"%s %d %d",nume,&ruble,&timp)!=EOF)
    {
        if(timp_casiera < timp_clienti)break;
        else
        {

            Enqueue(ruble,timp);
        }

    }
    int j;
    int secunde=0;
    for(j=0; j<i; j++)
    {
        while (head!=0&&(secunde+head->timp<=time_after[j]))
        {
            bani_casiera+=head->ruble;
            secunde+=head->timp;
            Dequeue();
        }
        fprintf(out,"%s %d %s %d\n","After",time_after[j],"seconds:",bani_casiera);
    }


    fclose(in);
    fclose(out);

    return 0;
}
