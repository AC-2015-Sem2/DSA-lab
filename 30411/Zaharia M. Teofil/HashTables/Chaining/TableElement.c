#include "TableElement.h"

#include <stdlib.h>
#include <string.h>

TableElement* newTableElement(char* data)
{
    TableElement* te = (TableElement*) malloc (sizeof(TableElement));

    int len = strlen(data);
    te->data = (char*) malloc ((len+1) * sizeof(char));
    strcpy(te->data, data);

    return te;
}

TableElement* deleteTableElement(TableElement* te)
{
    if (te == NULL)
        return NULL;

    free(te->data);
    free(te);
    return NULL;
}

void printContent(FILE *out, TableElement* te)
{   if (te == NULL)
        fprintf(out, "NULL");
    else
        fprintf(out, "%s ", te->data);
}

// change this function
int elementHash(TableElement* te)
{
    if (te == NULL)
        return 0;

    char* str = te->data;

    int i = 0, sum = 0;
    while (str[i] != '\0') {
        sum += str[i] - 46;
        i++;
    }

    return sum;
}

