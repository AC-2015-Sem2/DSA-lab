#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

/*
            |sorted array        |PBBST-perfectly balanced binary search tree
search-     log(n)                log(n)
select-     O(1)                  log(n)
min/max-    O(1)                  log(n)
Output-     O(n)                  O(n)
insert-     O(n) X                log(n)
delete-     O(n) X                log(n)
*/
typedef struct node
{
    int code;
    struct node *left,*right;
    int height;

} TreeNode;

static int height( TreeNode* p )
{
    if( p == NULL )
        return -1;
    else
        return p->height;
}

static int max( int l, int r)
{
    return l > r ? l: r;
}


static TreeNode* single_rotate_with_left( TreeNode* p2 )
{
    TreeNode* p1 = NULL;

    p1 = p2->left;
    p2->left = p1->right;
    p1->right = p2;

    p2->height = max( height( p2->left ), height( p2->right ) ) + 1;
    p1->height = max( height( p1->left ), p2->height ) + 1;
    return p1;
}

static TreeNode* single_rotate_with_right( TreeNode* p1 )
{
    TreeNode* p2;

    p2 = p1->right;
    p1->right = p2->left;
    p2->left = p1;

    p1->height = max( height( p1->left ), height( p1->right ) ) + 1;
    p2->height = max( height( p2->right ), p1->height ) + 1;

    return p2;
}

static TreeNode* double_rotate_with_left( TreeNode* p3 )
{
    p3->left = single_rotate_with_right( p3->left );
    return single_rotate_with_left( p3 );
}

static TreeNode* double_rotate_with_right( TreeNode* p1 )
{
    p1->right = single_rotate_with_left( p1->right );
    return single_rotate_with_right( p1 );
}


TreeNode *createNode(int code)
{
    TreeNode *p=(TreeNode*)malloc(sizeof(TreeNode));
    p->code=code;
    p->height=0;
    p->left=p->right=NULL;
    return p;
}

TreeNode* insert( int value, TreeNode* root)
{
    if (root==NULL)
    {
        return createNode(value);
    }

    else if(value<root->code)
    {
        root->left=insert(value, root->left);
        if( height(root->left) - height(root->right)==2)
            {if(value<root->left->code)
                root=single_rotate_with_left(root);
            else
                root=double_rotate_with_left(root);
            }
    }
    else if(value>root->code)
    {
        root->right = insert( value, root->right );
        if(height(root->right) - height(root->left)==2)
            {if(value>root->right->code)
                root=single_rotate_with_right(root);
            else
                root=double_rotate_with_right(root);
            }
    }
    root->height = max(height(root->left), height(root->right))+1;
    return root;
}


TreeNode* createBinTree()
{
    TreeNode *p;
    char *content=(char*)malloc(sizeof(char)*20);
    scanf("%s", content);
    if (strcmp(content,"*")==0)
        return NULL;
    else
    {
        p=createNode(atoi(content));        // atoi=array to integer
    }
    p->left=createBinTree();
    p->right=createBinTree();

    return p;
}

void printElement(TreeNode * node)
{
    printf ( "%d " ,(int) node->code );
}

void prettyPrint(TreeNode *root,int recLevel) //! root, index, length, reccurence level
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
    printElement(root);

    //! print  a new line
    printf("\n");

    prettyPrint(root->left,recLevel); //! keep going left in the tree
}



int main()
{
    TreeNode *root=createBinTree();
    insert(6,root);
    prettyPrint(root,0);
    return 0;
}
