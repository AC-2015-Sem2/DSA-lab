#include "TableElement.h"

#include <stdlib.h>
#include <string.h>

TableElement* newTableElement(char* data) {
    TableElement* te = (TableElement*) malloc (sizeof(TableElement));

    te->data =  (char*) malloc ((strlen(data)+1) * sizeof(char));
    strcpy(te->data, data);

    return te;
}

TableElement* deleteTableElement(TableElement* te) {
    if (te) {
        free(te->data);
        free(te);
    }

    return NULL;
}

void printElement(FILE *out, TableElement* te) {
    if (te == NULL)
        fprintf(out, "NULL");
    else
        fprintf(out, "%s ", te->data);
}

