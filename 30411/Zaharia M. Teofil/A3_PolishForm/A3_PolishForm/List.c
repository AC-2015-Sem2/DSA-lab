#include "List.h"

#include <stdlib.h>
#include <string.h>

NodeL* newNodeL(char* val) {
    NodeL* n = (NodeL*) malloc(sizeof(NodeL));

    n->next = n->prev = NULL;
	n->val = (char*) malloc(sizeof(strlen(val) + 1));
	strcpy(n->val, val);

    return n;
}

List* newList() {
    List* l = (List*) malloc(sizeof(List));

    l->first = l->last = NULL;

    return l;
}

void freeList(List* l) {
    if (!l)
        return;

    NodeL* temp;
    while (l->first) {
        temp = l->first->next;
        free(l->first);
        l->first = temp;
    }

    free(l);
}


void addFirst(List* l, char* val) {
	if (!l)
		return;

	NodeL* n = newNodeL(val);

	// non-empty list case is more probable
	// insert first for performance
	if (l->first) {
		n->next = l->first;
		l->first->prev = n;
		l->first = n;

	}
	else {
		l->first = l->last = n;
	}
}

void addLast(List* l, char* val) {
    if(!l)
        return;

    NodeL* n = newNodeL(val);

	if (l->first) {
		n->prev = l->last;
		l->last->next = n;
		l->last = n;

	}
	else {
		l->first = l->last = n;
	}
}


int iterate(NodeL** n) {
	if (*n) {
		if ((*n)->next) {
			(*n) = (*n)->next;
			return 0; // the list end wasn't reached
		} else {
			return 1; // list end is reached
		}
	}

	return -1;
}


List* createList(FILE* in) {
	List* l = newList();

	char *pc = (char*)malloc(20 * sizeof(char));

	while (!feof(in)) {
		fscanf(in, "%s ", pc);
		addLast(l, pc);
	}

	free(pc);
	return l;
}

void printAll(FILE* out, List* l) {
    if (l == NULL)
        return;

    NodeL* k = l->first;

    while (k != NULL) {
        fprintf(out, "%s ", k->val);
        k = k->next;
    }

    fprintf(out, "\n");
}


NodeL* getLast(List* l) {
	return l->last;
}
