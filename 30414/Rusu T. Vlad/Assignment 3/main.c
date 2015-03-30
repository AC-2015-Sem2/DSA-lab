#include <stdio.h>
#include <stdlib.h>
#define CTRLNODE 0xFFFFFFFF

typedef struct s_list
{
	int data;
	struct s_list *next;
} t_list;

typedef struct s_btree
{
	int data;
	struct s_btree *left;
	struct s_btree *right;
} t_btree;

void addLast(t_list **head, t_list **tail, int data)
{
	if (*head == NULL)
	{
		*head = (t_list *)malloc(sizeof(t_list));
		(*head)->data = data;
		(*head)->next = NULL;
		*tail = *head;
	}
	else
	{
		t_list *p;

		p = (t_list *)malloc(sizeof(t_list));
		p->data = data;
		p->next = NULL;
		(*tail)->next = p;
		*tail = p;
	}
}

void appendList(t_list *a, t_list *b)
{
	t_list *p;

	if (a == NULL)
		return;
	p = a;
	while (p->next != NULL)
		p = p->next;
	p->next = b;
}

void prettyPrint(t_btree *root,int recLevel)
{
	if(root==NULL)
	{
		recLevel--;
		return;
	}
	recLevel++;
	prettyPrint(root->right,recLevel);
	int j=0;

	for(j=0; j<recLevel-1; j++)
	{
		printf("     ");
	}
	printf("%d", root->data);

	printf("\n");

	prettyPrint(root->left,recLevel);
}

t_btree *createBinTree(FILE *f)
{
	t_btree *p;
	char *s;

	s = (char *)malloc(sizeof(char) * 20);

	fscanf(f, "%s", s);
	if (strcmp(s, "*") == 0)
		return NULL;
	else
	{
		p = (t_btree *)malloc(sizeof(t_btree));
		p->data = atoi(s);
		p->left = createBinTree(f);
		p->right = createBinTree(f);
	}

	free(s);
	return (p);
}

t_list *getListFromTree(t_btree *root)
{
	t_list *head;

	head = (t_list *)malloc(sizeof(t_list));
	head->next = NULL;
	if (root == NULL)
	{
		head->data = CTRLNODE;
		return (head);
	}
	head->data = root->data;
	appendList(head, getListFromTree(root->left));
	appendList(head, getListFromTree(root->right));
	return (head);
}

void traverseList(t_list *head)
{
	while (head != NULL)
	{
		if (head->data == CTRLNODE)
			printf("%c ", '*');
		else
			printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

t_btree *getTreeFromList(t_list *head)
{
	t_btree *root;

	if (head->data == CTRLNODE)
		return (NULL);
	else
	{
		t_list *p;

		root = (t_btree *)malloc(sizeof(t_btree));
		root->data = head->data;
		root->left = getTreeFromList(head->next);
		p = head->next;
		head->next = head->next->next;
		free(p);
		root->right = getTreeFromList(head->next);
		p = head->next;
		head->next = head->next->next;
		free(p);
	}
	return (root);
}

int main()
{
	t_btree *root;
	t_list *firstFromList;
	FILE *f;

	f = fopen("input.dat", "r");
	root = createBinTree(f);
	firstFromList = getListFromTree(root);
	traverseList(firstFromList);
	root = getTreeFromList(firstFromList);
	prettyPrint(root, 0);
	fclose(f);
	return (0);
}
