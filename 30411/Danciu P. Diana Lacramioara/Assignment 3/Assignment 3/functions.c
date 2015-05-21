#include "header.h"

/*Functions for trees in particular, adapted for to my tree's structure
*
*
*
*/

ListT *head = NULL; //global variables for the doubly linked list
ListT *tail = NULL;

TreeT *createStaticTree()
{
    TreeT *root;

    root = createNodeTree(1);
    root->left=createNodeTree(2);
    root->right=createNodeTree(5);
    root->left->left=createNodeTree(6);
    root->left->right=createNodeTree(7);
    root->right->left=createNodeTree(9);
    return (root);
}

void preorder(TreeT *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(TreeT *root)
{
    if (root != NULL)
    {
        inorder(root->left);   //for a binary search tree, it outputs the node in increasing order
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void postorder(TreeT *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int MaxDepth(TreeT *root)
{
    if (root == NULL)
        return (0);
    else
    {
        int leftHeight,rightHeight;
        leftHeight=MaxDepth(root->left);
        rightHeight=MaxDepth(root->right);
        if (leftHeight > rightHeight)
            return(leftHeight+1);
        else
            return(rightHeight+1);
    }
}

/* Functions for my problem -> list from tree and back again
*
*
*
*/

void AddNodeLast(int code)
{
    ListT *p;

    p = (ListT *)malloc(sizeof(ListT));
    if (head == NULL )
    {
        // empty list
        head = tail = p;
        p->data = code;
        p->next = p->prev= NULL;
    }
    else
    {
        // nonempty list
        p->next = NULL;
        p->prev = tail;
        p->data = code;
        tail->next = p;
        tail =p;
    }
}

TreeT *createNodeTree(int data)
{
    TreeT *p;

    p = (TreeT *)malloc(sizeof(TreeT));
    p->data = data;
    p->left = p->right = NULL;
    return(p);
}

TreeT *createBinTree(void)
{
    char *content;
    TreeT *p;

    content = (char *)malloc(sizeof(char)*20);
    scanf("%s", content);
    if (strcmp(content, "*")== 0)  //give star = * to point to null when you don't have any more nodes to that node
        return NULL;
    else
    {
        p=createNodeTree(atoi(content));
        p->left=createBinTree();
        p->right=createBinTree();
    }
    return (p);
}

ListT *getListFromTree(TreeT *root)
{
    if (root == NULL)
        AddNodeLast(-1); // consider that the node of the tree can not have negative values so when we have a star (NULL) is will be -1
    else if (root != NULL)
    {
        AddNodeLast(root->data);
        getListFromTree(root->left);
        getListFromTree((root->right));
    }
    free(root); //free the memory allocated for the tree
    return(head);
}

TreeT *getTreeFromList(ListT **head)
{
    TreeT *tree;

    if ((*head)->data == -1 && *head != NULL)
    {
        *head=(*head)->next;
        return(NULL);
    }
    else
    {
        tree = (TreeT *)malloc(sizeof(TreeT));
        tree->data=(*head)->data;
        *head=(*head)->next;
        free((*head)->prev);
        tree->left=getTreeFromList(head);
        tree->right=getTreeFromList(head);
        return(tree);
    }
}

void prettyPrint(TreeT *root,int recLevel) //! root, index, length, reccurence level
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
        printf("     ");
    }
    //! then print value
    printf("%d", root->data);

    //! print  a new line
    printf("\n");

    prettyPrint(root->left,recLevel); //! keep going left in the tree
}

void traverseList(ListT *firstFromList)
{
    ListT *p;

    p = (ListT *)malloc(sizeof(ListT));
    p=firstFromList;
    while (p != NULL )
    {
        if (p->data == -1)
        {
            printf("* ");  //as the input tree
        }
        else
        {
            printf("%d ", p->data);
        }
        p=p->next;
    }
}
