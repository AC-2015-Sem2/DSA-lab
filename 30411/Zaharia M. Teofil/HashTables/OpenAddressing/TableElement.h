#ifndef TABLEELEMENT_H
#define TABLEELEMENT_H

#include <stdio.h>

typedef struct s_tableElement {
    char* data;
} TableElement;

TableElement* newTableElement(char* data);
TableElement* deleteTableElement(TableElement* te);

void printElement(FILE* out, TableElement* te);

#endif // TABLEELEMENT_H
