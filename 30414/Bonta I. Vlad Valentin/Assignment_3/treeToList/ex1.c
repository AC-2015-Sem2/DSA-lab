#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define INF -99999999
typedef struct s_btree
{
	int data;
	struct s_btree *left, *right;	
}t_btree;

typedef struct s_node{
	int data;
	struct s_node *next;
}t_node;

FILE *f, *g;
t_node *head = NULL, *tail = NULL;

t_btree*	createNode(int data)
{
	t_btree *tmp;
	tmp = (t_btree*)malloc(sizeof(t_btree));
	tmp->data = data;
	tmp->left = NULL;
	tmp->right = NULL;
	return (tmp);
}

t_btree* createBinTree()
{
	t_btree *p;
	char *s;
	s = (char*)malloc(sizeof(char) * 100);
	fscanf(f, "%s",s);
	if (strcmp (s, "*") == 0)
		return (NULL);
	else
	{
		p = createNode(atoi(s));
		p->left = createBinTree();
		p->right = createBinTree();
	}
	return p;
}

void	printTreePreorder(t_btree *x)
{
	if (x != NULL)
	{
		fprintf(g, "%d ", x->data);
		printTreePreorder(x->left);
		printTreePreorder(x->right);
	}
}

void    traverseList(t_node *head)
{
	t_node *tmp = head;
	while (tmp != NULL)
	{
		if (tmp->data == INF)
			fprintf(g, "* ");
		else
			fprintf(g, "%d ", tmp->data);
		tmp = tmp->next;
	}
	fprintf(g, "\n");
}

void    add_last(int data)
{ 
	if(head == NULL)
	{
		t_node *tmp;
		tmp = (t_node*)malloc(sizeof(t_node));
		if (tmp == NULL)
			fprintf(g, "\nNode creation failed!\n");
		else
		{
			tmp->data = data;
			tmp->next = NULL;
			head = tmp;
			tail = tmp;
		}
	}
	else
	{
		t_node *ptr;
		ptr = (t_node*)malloc(sizeof(t_node));

		if (ptr == NULL)
			fprintf(g, "\nNode creation failed!\n");
		else
		{
			ptr->data = data;
			ptr->next = NULL;
			tail->next = ptr;
			tail = ptr;
		}
	}
}

void	getListFromTree(t_btree *root)
{
	if (root != NULL)
	{
		add_last(root->data);
		getListFromTree(root->left);
		getListFromTree(root->right);
	}
	else
	{
		add_last(INF);
	}	
}

t_btree* getTreeFromList()
{
	t_btree *p;
	p = (t_btree*)malloc(sizeof(t_btree));

	int data = head->data;
	head = head->next;
	if (data == INF)
		return (NULL);
	else
	{
		p = createNode(data);
		p->left = getTreeFromList();
		p->right = getTreeFromList();
	}
	return p;
}

void printElement(t_btree * node)
{
	fprintf (g, "%d " ,(int) node->data );
}

void prettyPrint(t_btree *root,int recLevel) //! root, index, length, reccurence level
{
	if(root==NULL)
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
		fprintf(g, " ");
	}
	//! then print value
	printElement(root);
	//! print a new line
	fprintf(g, "\n");
	prettyPrint(root->left,recLevel); //! keep going left in the tree
}

int main(void)
{
	t_btree *root, *rootFromList;

	f = fopen("input.dat", "r");
	g = fopen("output.dat", "w");
	root = createBinTree();
	getListFromTree(root);
	traverseList(head);
	rootFromList = getTreeFromList();
	prettyPrint(root, 0);
	fprintf (g, "\n");
	return (0);
}
