#include <stdio.h>
#include <stdlib.h>

void AddLastCustomer(int name, int rubles, int seconds);
void Print_All_Customers();

typedef struct queue1
    { char pers[30];
      int money, time;
      struct queue1 *next;
    }customer;

customer *head, *tail;

void AddLastCustomer(int name, int rubles, int seconds)
{
    if (head==NULL)
    {
        head=(customer*)malloc(sizeof(customer));
        tail=head;
        strcpy(head->pers, name);
        head->money=rubles;
        head->time=seconds;
        head->next=tail;
    }
    else
    {
        customer* newCustomer=(customer*)malloc(sizeof(customer));
        strcpy(tail->pers, name);
        newCustomer->money=rubles;
        newCustomer->time=seconds;
        tail->next=newCustomer;
        tail=newCustomer;
    }


    void Print_All_Customers()
{
    FILE *f=fopen("output.dat", "a");
    customer* aux=head;
    while (aux!=NULL)
    {
        fprintf(f, "%c %d %d\n", aux->pers, aux->money, aux->time);
        aux=aux->next;
    }
    fprintf(f,"\n");
    fclose(f);
}
}
int main()
{
    char name[20]; int rubles, seconds, totalmoney=0, time, currenttime=0;
    FILE *d;
    d= fopen("input.dat", "r");
    FILE* f=fopen("output.dat", "a");
    while(fscanf(d,"%d",&time)!="\n")
    {
        while(fscanf(d, "%s %d %d", &name, &rubles, &seconds)!=EOF)
        {
            currenttime=currenttime+seconds;
            totalmoney=totalmoney+rubles;
            if (time>=currenttime)
            {
                AddLastCustomer(name,rubles,seconds);
                fprintf(f,"After %d seconds: %d", time, currenttime);

            }

        }
    }
    fclose(f);
    return 0;
}
