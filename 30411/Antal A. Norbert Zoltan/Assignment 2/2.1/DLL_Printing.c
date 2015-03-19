#include <stdlib.h>
#include <stdio.h>
#include "DLL_Printing.h"
#include "DLL_Def.h"

void PrintAll()
{
    if (dll->head==NULL || dll->tail==NULL)
    {
        return;
    }
    nodeT* node = dll->head;
    FILE* pfile = fopen("output.dat", "a");
    while (node!=dll->tail)
    {
        fprintf(pfile, "%d ", node->data);
        node = node->next;
    }
    fprintf(pfile, "%d\n", dll->tail->data);
    fclose(pfile);
}

void PrintFirst(int x)
{
    if (dll->head==NULL || dll->tail==NULL || x<=0)
    {
        return;
    }
    FILE* pfile = fopen("output.dat", "a");
    nodeT* node = dll->head;
    int i = 0;
    while (i<x && node!=NULL)
    {
        fprintf(pfile, "%d ", node->data);
        node = node->next;
        i++;
    }
    fprintf(pfile, "\n");
    fclose(pfile);
}

void PrintLast(int x)
{
    if (dll->head==NULL || dll->tail==NULL || x<=0)
    {
        return;
    }
    FILE* pfile = fopen("output.dat", "a");
    nodeT* node = dll->head;
    int i = 0, r = dll->length-x;
    while (i<=r)
    {
        node = node->next;
        i++;
    }
    while (node!=NULL)
    {
        fprintf(pfile, "%d ", node->data);
        node = node->next;
    }
    fprintf(pfile, "\n");
    fclose(pfile);
}
