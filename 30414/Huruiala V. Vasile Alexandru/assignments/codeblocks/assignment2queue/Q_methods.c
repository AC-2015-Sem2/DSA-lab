#include "Q_methods.h"
#include "Q_solution.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_LINE_LENGTH 256

void initSent(Sentinel** S)
{
    *S = (Sentinel*)malloc(sizeof(Sentinel));
    //Queue init
    (*S)->Qhead = NULL;
    (*S)->Qtail = NULL;
    //Time list init
    (*S)->Thead = NULL;
    (*S)->Ttail = NULL;
    //Methods init
    (*S)->ENQ = &ENQ;
    (*S)->DEQ = &DEQ;
    (*S)->AddLastTime = &AddLastTime;
    (*S)->RemoveFirstTime = &RemoveFirstTime;
    (*S)->readFile = &readFile;
    (*S)->solve = &solve;
}

//Queue operations
void ENQ(Sentinel* S, void* data1, void* data2, void* data3)
{
    NodeQ* NewNode = (NodeQ*)malloc(sizeof(NodeQ));
    NewNode->data1 = data1;
    NewNode->data2 = data2;
    NewNode->data3 = data3;
    NewNode->next = NULL;
    NewNode->prev = NULL;

    if(S->Qhead == NULL)//The queue is empty
    {
        S->Qhead = NewNode;
        S->Qtail = NewNode;
    }
    else
    {
        S->Qtail->next = NewNode;
        NewNode->prev = S->Qtail;
        S->Qtail = NewNode;
    }
}

void DEQ(Sentinel* S)
{
    if(S->Qhead != NULL)
    {
        if(S->Qhead == S->Qtail)
        {
            free(S->Qhead->data1);
            free(S->Qhead->data2);
            free(S->Qhead->data3);
            free(S->Qhead);
            S->Qhead = NULL;
            S->Qtail = NULL;
        }
        else
        {
            NodeQ* del = S->Qhead;
            S->Qhead = S->Qhead->next;
            S->Qhead->prev = NULL;
            free(del->data1);
            free(del->data2);
            free(del->data3);
            free(del);
        }
    }
}

//Time list operations(actually still a queue)
void AddLastTime(Sentinel* S, void* data)
{
    NodeT* NewNode = (NodeT*)malloc(sizeof(NodeT));
    NewNode->data = data;
    NewNode->next = NULL;
    NewNode->prev = NULL;

    if(S->Thead == NULL)//If the list is empty
    {
        S->Thead = NewNode;
        S->Ttail = NewNode;
    }
    else
    {
        S->Ttail->next = NewNode;
        NewNode->prev = S->Ttail;
        S->Ttail = NewNode;
    }
}

void RemoveFirstTime(Sentinel* S)
{
    if(S->Thead != NULL)
    {
        if(S->Thead == S->Ttail)
        {
            free(S->Thead->data);
            free(S->Thead);
            S->Thead = NULL;
            S->Ttail = NULL;
        }
        else
        {
            NodeT* del = S->Thead;
            S->Thead = S->Thead->next;
            S->Thead->prev = NULL;
            free(del->data);
            free(del);
        }
    }

}
/*DEBUG FUNCTION*
void debuglist(Sentinel* S)
{
    printf("ind\n");
    NodeT* t = S->Thead;
    while(t != NULL)
    {
        printf("%d ", *(int*)t->data);
        t = t->next;
    }
    printf("\n");

    NodeQ* q = S->Qhead;
    while(q != NULL)
    {
        printf("%s,%d,%d\n", (char*)q->data1, *(int*)q->data2, *(int*)q->data3);
        q = q->next;
    }
    printf("outd\n");
}
**/
void readFile(Sentinel* S, FILE* I)
{
    char line[MAX_LINE_LENGTH];
    fgets(line, MAX_LINE_LENGTH, I);
    char* ptr;
    //Reading the first line
    //Uses strtok since the line contains an undeclared number of numbers
    ptr = strtok(line, " ");
    while(ptr != NULL)
    {
        int time;
        sscanf(ptr, "%d", &time);

        void* data = malloc(sizeof(int*));
        *(int*)data = time;
        (*S->AddLastTime)(S, data);

        ptr = strtok(NULL, " ");
    }
    //debuglist(S);
    //Reading the rest of the file
    while(fgets(line, MAX_LINE_LENGTH, I) != NULL)
    {
        char name[MAX_LINE_LENGTH];
        int money = 0;
        int time = 0;
        sscanf(line, "%s %d %d", name, &money, &time);

        void* data1 = malloc((sizeof(char) * strlen(name)) + 1);//<------- this +1(or its absence) caused me nightmares
        strcpy((char*)data1, name);

        void* data2 = malloc(sizeof(int*));
        *(int*)data2 = money;

        void* data3 = malloc(sizeof(int*));
        *(int*)data3 = time;

        (*S->ENQ)(S, data1, data2, data3);

    }
    //debuglist(S);
}

void DestroySent(Sentinel** S)
{
    while((*S)->Thead != NULL)
    {
        NodeT* del = (*S)->Thead;
        (*S)->Thead = (*S)->Thead->next;
        free(del->data);
        free(del);
    }
    (*S)->Thead = NULL;
    (*S)->Ttail = NULL;
    while((*S)->Qhead != NULL)
    {
        NodeQ* del = (*S)->Qhead;
        (*S)->Qhead = (*S)->Qhead->next;
        free(del->data1);
        free(del->data2);
        free(del->data3);
        free(del);
    }
    (*S)->Qhead = NULL;
    (*S)->Qtail = NULL;

    //Methods init
    (*S)->ENQ = NULL;
    (*S)->DEQ = &DEQ;
    (*S)->AddLastTime = NULL;
    (*S)->RemoveFirstTime = NULL;
    (*S)->readFile = NULL;
    (*S)->solve = NULL;

    free(*S);
    *S = NULL;
}
