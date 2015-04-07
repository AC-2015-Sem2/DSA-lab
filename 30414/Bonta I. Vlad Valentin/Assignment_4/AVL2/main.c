#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define max(a, b) ((a) > (b) ? (a) : (b))
#define seth(n) (n->h = 1 + max(n->left->h, n->right->h)) //seth(n) sets the height of a node

typedef struct s_btree
{
	int data, h;
	struct s_btree *left, *right;
}t_btree;

t_btree *R, *NIL; /*I found something very nice on internet with NIL, a NULL "alternative" */

FILE *f, *g;

int 	search(t_btree *root, int value) //check if a value is in the tree
{
	if (root != NULL)
	{
		if (root->data == value)
			return (1);
		if (value < root->data)
			return search(root->left, value);
		return search(root->right, value);
	}
	return (0);
}


void init(void)
{
	R = NIL = (t_btree *) malloc(sizeof(t_btree));
	NIL->data = NIL->h = 0;
	NIL->left = NIL->right = NULL;
}

/*
	Unbalance node's height = (height of left tree) - (height of right tree);
	If the unbalance node's height is :
		o positive -> left side
 			If the left node's height is:
				o positive : LL rotation
				o negative : LR rotation

		o negative ->right side
			If the right node's height is:
				o positive : RL rotation
				o negative : RR rotation
*/

t_btree* rotate_Left(t_btree *n)
{
	t_btree *t = n->left;

	n->left = t->right;
	t->right = n;
	seth(n);
	seth(t);
	return t;
}

t_btree* rotate_Right(t_btree *n)
{
	t_btree *t = n->right;

	n->right = t->left;
	t->left = n;
	seth(n);
	seth(t);
	return t;
}

t_btree* balance_Tree(t_btree *node)
{
	seth(node);
	if (node->left->h - node->right->h > 1)
	{
		//Left subtree > Right subtree
		if (node->left->right->h - node->left->left->h > 0) // if it's left node height is negative , then LR rotation is applied
			node->left = rotate_Right(node->left);
		node = rotate_Left(node);
	}
	else
		if (node->right->h - node->left->h > 1)
		{
			//Right subtree > Left subtree
			if (node->right->left->h - node->right->right->h > 0) // if it's left node height is positive, then RL rotation is applied
				node->right = rotate_Left(node->right);
			node = rotate_Right(node);
		}
	return node;
}

t_btree* insert(t_btree *node, int data)
{
	if (node == NIL)
	{
		node = (t_btree*) malloc(sizeof(t_btree));
		node->data = data;
		node->h = 1;
		node->left = node->right = NIL;
		return node;
	}
	if (data < node->data)
		node->left = insert(node->left, data);
	else
		node->right = insert(node->right, data);
	return balance_Tree(node);
}

t_btree* erase(t_btree *node, int data)
{
	t_btree *t;
	if (node == NIL) return node;
	if (node->data == data)
	{
		if (node->left == NIL || node->right == NIL)
		{
			if (node->left == NIL)
				t = node->right;
			else
				t = node->left;
			free(node);
			return t;
		}
		else
		{
			/*Take the most left leave of the right son of the node*/
			if (node->right->h > node->left->h)
				for (t = node->right; t->left != NIL; t = t->left);
			else
				for (t = node->left; t->right != NIL; t = t->right);
			node->data = t->data;
			if (node->right->h > node->left->h)
				node->right = erase(node->right, t->data);
			else
				node->left = erase(node->left, t->data);
			return balance_Tree(node);
		}
	}
	if (data < node->data)
		node->left = erase(node->left, data);
	else
		node->right = erase(node->right, data);
	return balance_Tree(node);
}

t_btree*	createNode(int data)
{
	t_btree *tmp;
	tmp = (t_btree*)malloc(sizeof(t_btree));
	tmp->data = data;
	tmp->left = NIL;
	tmp->right = NIL;
    tmp->h = 0;
	tmp-> h =seth(tmp);
	return (tmp);
}

t_btree* createBinTree()
{
	t_btree *p;
	char *s;
	s = (char*)malloc(sizeof(char) * 100);
	fscanf(f, "%s",s);
	if (strcmp (s, "*") == 0)
		return (NIL);
	else
	{
		p = createNode(atoi(s));
		p->left = createBinTree();
		p->right = createBinTree();
	}
	return p;
}

void printElement(t_btree * node)
{
	printf ("%d " ,(int) node->data );
}

void prettyPrint(t_btree *root,int recLevel) //! root, index, length, reccurence level
{
	if(root==NIL)
	{
		recLevel--; //! reached leaf, must decrement recurence level
		return;
	}
	recLevel++; //! otherwise increment it
	prettyPrint(root->right,recLevel); //! keep going right in the tree
	int j=0;
	//! print spaces for the appropriate recurence level
	for(j=0; j<recLevel-1; j++)
	{
		printf( "      ");
	}
	//! then print value
	printElement(root);
	//! print a new line
	printf( "\n");
	prettyPrint(root->left,recLevel); //! keep going left in the tree
}

int	main(void)
{
	f = fopen("input.dat", "r");
	init();
	R = createBinTree();
	prettyPrint(R, 0);
	printf("\n\n\n\n\n\n");
	int x = 0;
	scanf("%d", &x);
	while (x != 0 && R !=NIL)
	{
		R = erase(R, x);
		prettyPrint(R, 0);
		printf("\n\n\n\n\n\n\n\n");
		scanf("%d", &x);
	}
	return (0);
}
