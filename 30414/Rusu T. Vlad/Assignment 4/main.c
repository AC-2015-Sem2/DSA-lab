#include <stdlib.h>
#include <stdio.h>

typedef struct s_tree
{
	int data;
	struct s_tree *left;
	struct s_tree *right;
	int height;
} t_tree;

t_tree *createNode(int data)
{
	t_tree *node;

	node = (t_tree *)malloc(sizeof(t_tree));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return (node);
}

int maxim(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int height(t_tree *root)
{
	if (root == NULL)
		return (0);
	return (root->height);
}

t_tree *rightRotate(t_tree *root)
{
	t_tree *l;
	t_tree *sub;

	l = root->left;
	sub = l->right;

	l->right = root;
	root->left = sub;

	root->height = maxim(height(root->left), height(root->right)) + 1;
	l->height = maxim(height(l->left), height(l->right)) + 1;

	return (l);
}

t_tree *leftRotate(t_tree *root)
{
	t_tree *r;
	t_tree *sub;

	r = root->right;
	sub = r->left;

	r->left = root;
	root->right = sub;

	root->height = maxim(height(root->left), height(root->right)) + 1;
	r->height = maxim(height(r->left), height(r->right)) + 1;

	return (r);
}

t_tree *insert(t_tree *root, int data)
{
	int balance;

	if (root == NULL)
		return (createNode(data));

	if (data < root->data)
		root->left = insert(root->left, data);
	else
		root->right = insert(root->right, data);

	root->height = maxim(height(root->left), height(root->right)) + 1;

	balance = height(root->left) - height(root->right);

	if ((balance > 1) && (data < root->left->data))
		return (rightRotate(root));

	if ((balance > 1) && (data >= root->left->data))
	{
		root->left = leftRotate(root->left);
		return (rightRotate(root));
	}

	if ((balance < -1) && (data > root->right->data))
		return (leftRotate(root));

	if ((balance < -1) && (data <= root->right->data))
	{
		root->right = rightRotate(root->right);
		return (leftRotate(root));
	}

	return (root);
}

void prettyPrint(t_tree *root,int recLevel)
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

int main()
{
	int x;
	t_tree *root;

	root = NULL;
	do
	{
		scanf("%d", &x);
		root = insert(root, x);
		printf("\n\n");
		prettyPrint(root, 0);
		printf("\n\n");
	} while (x);
	return (0);
}
