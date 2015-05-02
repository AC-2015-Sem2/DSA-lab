#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    struct node* right, *left;
    int content, height;
} NodeT;

NodeT* createnode(int q)
{
    NodeT* p= (NodeT*)malloc(sizeof(NodeT));
    p->content=q ;
    p->left= NULL;
    p-> right= NULL;
    p->height=1;
    return p;
}

NodeT * createbintree()
{
    NodeT *p;
    char *content= (char*)malloc(20*sizeof(char));
    scanf("%s", content);
    if (strcmp(content, "*")==0) return NULL;
    else
    {
        p=createnode(atoi(content));
        p->left= createbintree();
        p->right= createbintree();
    }
    return p;
}

int max(int a, int b)
{
    if (a> b) return a;
    else return b;
}

int heightl(const NodeT *mytree)
{
  if(mytree == NULL)
  {
   return 0;
  }
  else
  {
    return 1 + max(heightl(mytree -> left), heightl(mytree -> right));
  }
}


int checkBalance( NodeT *N)
{
    if (N == NULL)
        return 0;
    else return heightl(N->left) - (heightl(N->right));

}

NodeT* rightRotate(NodeT* p)
{
    NodeT* q= (NodeT*)malloc(sizeof(NodeT));
    p->left=q->right;
    q->right=p;
    p=q;
    return p;
}

NodeT* leftRotate(NodeT* p)
{
    NodeT* q;
    q=p->right;
    p->right=q->left;
    q->left=p;
    p=q;
    return p;
}



 NodeT* insert( NodeT* node, int key)
{
    if (node == NULL)
        return(createnode(key));

    if (key < node->content)
        node->left  = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    node->height = max(heightl(node->left), heightl(node->right)) + 1;


    int balance = checkBalance(node);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && key < node->left->content)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->content)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->content)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->content)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }


    return node;
}




void printElement (NodeT *root)
{
    printf("%d",root->content);
}
void prettyPrint(NodeT *root,int recLevel) //! root, index, length, reccurence level
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
    printf("%d ",root->content);

    //! print  a new line
    printf("\n");

    prettyPrint(root->left,recLevel); //! keep going left in the tree
}


int main()
{
    NodeT* root= createbintree();
    insert(root, 12);

    prettyPrint(root, 0);
    return 0;
}
