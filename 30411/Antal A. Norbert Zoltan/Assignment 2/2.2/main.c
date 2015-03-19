#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cust
{
    char* name;
    int money, time;
    struct cust *next, *prev;
} CustT;

typedef struct sent
{
    CustT *head, *tail, *current;
    int length;
} SentT;

SentT* valSnt;
SentT* custSnt;

void ReadInp();
CustT* DeQueue(SentT*);
int CalcMon(int);

int main()
{
    valSnt = (SentT*)malloc(sizeof(SentT));
    custSnt = (SentT*)malloc(sizeof(SentT));
    valSnt->head = NULL;
    valSnt->tail = NULL;
    custSnt->head = NULL;
    custSnt->tail = NULL;
    ReadInp();
    valSnt->current = valSnt->tail;
    FILE* ofile = fopen("output.dat", "a");
    CustT* value;
    while (valSnt->current!=NULL)
    {
        value = DeQueue(valSnt);
        custSnt->current = custSnt->tail;
        fprintf(ofile, "After %d seconds: %d\n", value->time, CalcMon(value->time));
    }
    fclose(ofile);
    return 0;
}

void EnQueue(SentT* snt, char* name, int money, int time)
{
    CustT* customer = (CustT*)malloc(sizeof(CustT));
    customer->name = name;
    customer->money = money;
    customer->time = time;
    if (snt->head==NULL)
    {
        customer->prev = NULL;
        customer->next =NULL;
        snt->head = customer;
        if (snt->tail==NULL)
        {
            snt->tail = snt->head;
        }
    }
    else
    {
        customer->next = snt->head;
        snt->head->prev = customer;
        snt->head = customer;
        snt->head->prev = NULL;
        if (snt->tail->prev==NULL)
        {
            snt->tail->prev = snt->head;
        }
    }
    snt->length++;
}

CustT* DeQueue(SentT* snt)
{
    if (snt->tail!=NULL && snt->current!=NULL)
    {
        CustT* ret = snt->current;
        snt->current = snt->current->prev;
        return ret;
    }
    return NULL;
}

void ReadInp()
{
    FILE* ifile = fopen("input.dat", "r");
    char* line = (char*)malloc(50);
    fgets(line, 50, ifile);
    char* token = strtok(line, " ");
    while (token)
    {
        EnQueue(valSnt, "", -1, atoi(token));
        token = strtok(NULL, " ");
    }
    char* name = (char*)malloc(20);
    int money, time;
    while (fgets(line, 50, ifile))
    {
        sscanf(line, "%s %d %d", name, &money, &time);
        EnQueue(custSnt, name, money, time);
    }
}

int CalcMon(int time)
{
    if (valSnt->head==NULL)
    {
        return 0;
    }
    int totmoney = 0, tottime = 0;
    CustT* customer = DeQueue(custSnt);
    while (customer!=NULL && tottime+customer->time<=time)
    {
        totmoney += customer->money;
        tottime += customer->time;
        customer = DeQueue(custSnt);
    }
    return totmoney;
}
