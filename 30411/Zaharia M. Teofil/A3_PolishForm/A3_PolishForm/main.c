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

	freeBTree(bt);

	freeList(initialList);
	getchar();
	return 0;
}