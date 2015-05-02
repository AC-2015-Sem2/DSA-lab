#include "BinTree.h"

#include <stdlib.h>
#include <string.h>
#include <math.h>

void printNodeT(FILE* out, NodeT* n) {
	fprintf(out, "%s ", n->val);
}

NodeT* newNodeT(char* data) {
	NodeT* n = (NodeT*)malloc(sizeof(NodeT));

	n->val = data;
	n->r = n->l = NULL;

	return n;
}

BTree* newBTree() {
	BTree* bt = (BTree*)malloc(sizeof(BTree));
	
	bt->root = NULL;
	bt->height = 0;

	return bt;
}

void freeBTree(BTree* bt) {
	if (!bt)
		return;
	if (!bt->root)
		return;

	recFree(bt->root);
	free(bt);
}

void recFree(NodeT* n) {
	if (n->l) {
		recFree(n->l);
	}
	else if (n->r) {
		recFree(n->r);
	}
	
	free(n);
}

BTree* treeFromList(List* l) {
	BTree* bt = newBTree();
	NodeL* iterator = l->first;

	bt->root = recCreate(&iterator);
	bt->height = recHeight(bt->root);

	return bt;
}

NodeT* recCreate(NodeL** iterator) {
	NodeT* n;
	char* dat = (*iterator)->val;

	iterate(iterator);

	if (!strcmp(dat, "*")) {
		return NULL;
	}
	else {
		n = newNodeT(dat);
		n->l = recCreate(iterator);
		n->r = recCreate(iterator);
	}

	return n;
}


List* listFromTree(BTree* bt) {
	List* l = newList();

	recList(l, bt->root);

	return l;
}

void recList(List* l, NodeT* nt) {
	if (nt) {
		addLast(l, nt->val);
		recList(l, nt->l);
		recList(l, nt->r);
	}
	else {
		addLast(l, "*");
	}
}


int getHeight(BTree* bt) {
	return recHeight(bt->root);
}

int recHeight(NodeT* n) {
	if (n == NULL)
		return 0;
	else {
		int hl = recHeight(n->l);
		int hr = recHeight(n->r);

		if (hl > hr)
			return hl + 1;
		else
			return hr + 1;
	}
}

int spacing(int height, int level, int userSet) {
	return userSet * (int)pow(2.0, height - level);
}

int offset(int height, int level, int userSet) {
	return userSet / 2 * ((int)pow(2.0, height - level) - 1);
}

void prettyPrint(FILE* out, BTree* bt) {
	if (!bt)
		return;
	if (!bt->root)
		return;

	int height = getHeight(bt);
	//printf("%d", height);
	Queue* q = newQueue();

	int currentLineCounter = 1; // no of elements on the current line
	int nextLineCounter; // no of elements on the following line

	NodeT* nt;
	int i, iLine, kLevel = 0;
	int offsetParam, spacingParam, userSet = 2, wordOffset;

	enqueue(q, (void*)bt->root);

	while (!isEmpty(q)) {

		offsetParam = offset(height, kLevel, userSet);
		for (iLine = 0; iLine < offsetParam; iLine++) {
			fprintf(out, " ");
		}

		spacingParam = spacing(height, kLevel, userSet);
		nextLineCounter = 0;
		for (i = 0; i < currentLineCounter; i++) {
			wordOffset = 1;

			if (getFirst(q) != NULL) {
				nt = (NodeT*)getFirst(q);
				printNodeT(out, nt);
				wordOffset = strlen(nt->val);

				if (nt->l) {
					enqueue(q, (void*)(nt->l));
					nextLineCounter++;
				}
				else if (kLevel < height - 1) {
					enqueue(q, NULL);
					nextLineCounter++;
				}

				if (nt->r) {
					enqueue(q, (void*)(nt->r));
					nextLineCounter++;
				}
				else if (kLevel < height - 1) {
					enqueue(q, NULL);
					nextLineCounter++;
				}
			}
			else {
				fprintf(out, " ");
			}


			for (iLine = 0; iLine < spacingParam - wordOffset; iLine++) {
				fprintf(out, " ");
			}

			dequeue(q);
		}
		fprintf(out, "\n");
		currentLineCounter = nextLineCounter;
		kLevel++;
	}
	freeQueue(q);
	fprintf(out, "\n");
}