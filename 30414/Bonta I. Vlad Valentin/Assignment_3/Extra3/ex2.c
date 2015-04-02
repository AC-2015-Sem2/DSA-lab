#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define INF -99999999
typedef struct s_btree
{
	char* data;
	struct s_btree *left, *right;	
}t_btree;

typedef struct s_node{
	int data;
	struct s_node *next;
}t_node;

FILE *f, *g;
t_node *head = NULL, *tail = NULL;

t_btree*	createNode(char* data)
{
	t_btree *tmp;
	tmp = (t_btree*)malloc(sizeof(t_btree));
	tmp->data = (char*)malloc(sizeof(char));
	tmp->data = strcpy(tmp->data, data);
	tmp->left = NULL;
	tmp->right = NULL;
	return (tmp);
}

int	ft_check_number(char *s)
{
	int i = 0;
	if (strlen(s) != 1)
	{
		while (s[i] != 0)
			if ((i==0 && s[i] == '-') || ((s[i] >= '0' && s[i] <= '9') || s[i] == '.'))
				i++;
			else
				return (0);
	}
	else
	{
		if (s[0] <= '9' && s[i] >= '0')
			return (1);
		else
			return (0);
	}
	return (1);
}

t_btree* createBinTree()
{
	t_btree *p;
	p = (t_btree*)malloc(sizeof(t_btree));
	char *s;
	s = (char*)malloc(sizeof(char) * 100);
	if (fscanf(f, "%s",s) == 1)
	{
		if (ft_check_number(s) == 1)
		{
			p = createNode(s);
			return (p);
		}
		p = createNode(s);
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

void printElement(t_btree * node)
{
	fprintf (g, "%s "  ,node->data );
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
		fprintf(g, "       ");
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
	if (!f)
	{
		printf ("Can't read from input file\n");
		return ;
	}
	g = fopen("output.dat", "w");
	root = createBinTree();
	//getListFromTree(root);
	//traverseList(head);
	//rootFromList = getTreeFromList();
	prettyPrint(root, 0);
	fprintf (g, "\n");
	return (0);
}
