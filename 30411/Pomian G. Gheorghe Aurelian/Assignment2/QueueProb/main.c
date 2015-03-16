#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NodeT{
        char name[20];
        int time;
        int cash;
        struct NodeT* next;
    }NodeT;

typedef struct sant{
    NodeT* head;
    NodeT* tail;
    }Santinel;

Santinel S;

void addElem(int time, int cash)
{
    if(S.head==NULL)
        {
            S.head=(NodeT*)malloc(sizeof(NodeT));
            S.head->time=time;
            S.head->cash=cash;
            S.head->next=NULL;
            S.tail=S.head;
        }
        else if (S.tail==NULL)
        {
            NodeT* p=(NodeT*)malloc(sizeof(NodeT));
            p->time=time;
            p->cash=cash;
            p->next=NULL;
            S.tail=p;
        }
        else
        {
            NodeT* p=(NodeT*)malloc(sizeof(NodeT));
            p->time=time;
            p->cash=cash;
            p->next=NULL;
            S.tail->next=p;
            S.tail=p;
        }
}

int Calculate(int x)
{
    int Total=0;
    if(S.head==NULL)
        printf("No elements in queue");
    else
    {
        NodeT* p=(NodeT*)malloc(sizeof(NodeT));
        p=S.head;
        while(p!=NULL && p->time<=x)
        {
            Total=Total+p->cash;
            x=x-p->time;
            p=p->next;
        }
    }
    return Total;
}

int main()
{
    FILE *f, *g;
    f=fopen("input.dat","r");
    g=fopen("output.dat","w");

    int i = 0, j, time, cash;
    char *test, str[100];
    char ch;
    char s[2]=" ";
    int interval[15];

    fgets(str,100,f);
    test = strtok(str,s);

    while(test != NULL)
    {
        interval[i] = atoi(test);
        test = strtok(NULL,s);
        i++;
    }


    ch = getc(f);
    fgets(str,100,f);
    test = strtok(str,s);

    while(ch != EOF)
    {
        cash = 0; time = 0;
        while(test != NULL)
        {
            test = strtok(NULL,s);
            if(cash == 0)
                cash = atoi(test);
            else
                if(time == 0)
                time = atoi(test);
        }
        addElem(time,cash);
        ch = getc(f);
        fgets(str,100,f);
        test = strtok(str,s);
    }

    for (j=0;j<i;j++)
    {
        fprintf(g,"Amount of money spent before %d seconds is %d\n",interval[j],Calculate(interval[j]));
    }



    fclose(f);
    fclose(g);

    return 0;
}
