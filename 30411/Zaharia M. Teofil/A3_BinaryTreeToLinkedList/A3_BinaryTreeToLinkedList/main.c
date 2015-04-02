#include "BinTree.h"
#include "List.h"

#include <stdio.h>
#include <stdlib.h>


int main() {
	// read the list
	FILE *in = fopen("input.dat", "r");
	FILE *out = fopen("output.dat", "w");

	List* initialList = createList(in);

	fclose(in);
	
	// create the bin tree from the list
	BTree* bt = treeFromList(initialList);
	
	prettyPrint(out, bt);

	List* finalList = listFromTree(bt);
	fprintf(out, "Initial list (from input.dat):\n");
	printAll(out, initialList);
	fprintf(out, "Final list (from the binary tree):\n");
	printAll(out, finalList);

	freeBTree(bt);

	freeList(initialList);
	freeList(finalList);
	getchar();
	return 0;
}