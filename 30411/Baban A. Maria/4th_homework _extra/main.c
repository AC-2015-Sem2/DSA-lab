#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int k; //content
    int e; //check echilibrum
    struct node *left;
    struct node *right;
} NodeT;

//define all functions!
NodeT *createNode(int x);
NodeT* createStaticTree();
void echilibrum(NodeT *p);
void maxPath(NodeT *p,int *maximum,int lung);
void preorderEchilibrum(NodeT *root);
void preorderCheck(NodeT *root);
void check(NodeT *root);
void AVLTree(NodeT *root);
NodeT *insertNode(NodeT *p,int data);
NodeT *rotateRight(NodeT *p);
NodeT *rotateLeft(NodeT *p);
NodeT *rotateRight_Left(NodeT *p);
NodeT *rotateLeft_Right(NodeT *p);
NodeT *balancedTree(NodeT *p);
void printElement(NodeT *root);
void prettyPrint(NodeT *root,int recLevel);

NodeT *createNode(int x)
{
    NodeT *p=(NodeT *)malloc(sizeof(NodeT));
    p->k=x; //content
    p->e=0; //echilirum
    p->left=NULL;
    p->right=NULL;
    return p;
}

NodeT* createStaticTree()
{
    NodeT* root=createNode(4);
    root->left=createNode(2);
    root->right=createNode(5);
    root->left->left=createNode(1);
    root->left->right=createNode(7);
    root->right->left=createNode(3);
    return root;
}

//function to check for the maximum length & use it to check the echilibrum
void echilibrum(NodeT *p)
{
    int leftH=1;
    int rightH=1;
    if(p->left!=NULL)
        maxPath(p->left,&leftH,1);
    else
        leftH=0;
    if(p->right!=NULL)
        maxPath(p->right,&rightH,1);
    else
        rightH=0;
    p->e=rightH-leftH;
}

void maxPath(NodeT *p,int *maximum,int lung)
{
    if(p!=NULL)
    {
        maxPath(p->right,maximum,lung+1);

        if((p->left==NULL)&&(p->right==NULL)&&(*maximum<lung))
        {
            *maximum=lung;
        }
        maxPath(p->left,maximum,lung+1);
    }
}

void preorderEchilibrum(NodeT *root)
{
    if(root!=NULL)
    {
        echilibrum(root);
        preorderEchilibrum(root->left);
        preorderEchilibrum(root->right);
    }
}

void preorderCheck(NodeT *root)
{
    if(root!=NULL)
    {
        check(root);
        preorderCheck(root->left);
        preorderCheck(root->right);
    }
}

//check if AVL tree
void check(NodeT *root)
{
    if(root->e>1||root->e<(-1))
    {
        perror("This is not an AVL tree!\n");
        exit(1);
    }
}

void AVLTree(NodeT *root)
{
    preorderEchilibrum(root);
    preorderCheck(root);
}


//insertion
NodeT *insertNode(NodeT *p,int data)
{
    if(p==NULL)
    {
        return createNode(data);
    }
    else
    {
        if(p->k>data)
        {
            p->left=insertNode(p->left,data);
        }
        else if(p->k<data)
        {
            p->right=insertNode(p->right,data);
        }
        else
        {
            printf("The node already exists!\n");
        }
        p=balancedTree(p);
        return p;
    }
}

//4 types of rotations
NodeT *rotateRight(NodeT *p)
{
    NodeT *q;
    q=p->left;
    p->left=q->right;
    echilibrum(p);
    echilibrum(q);
    p=q;
    return p;
}

NodeT *rotateLeft(NodeT *p)
{
    NodeT *q;
    q=p->right;
    p->right=q->left;
    q->left=p;
    echilibrum(p);
    echilibrum(q);
    p=q;
    return p;
}

NodeT *rotateRight_Left(NodeT *p)
{
    p->right=rotateRight(p->right);
    p=rotateLeft(p);
    return p;
}

NodeT *rotateLeft_Right(NodeT *p)
{
    p->left=rotateLeft(p->left);
    p=rotateRight(p);
    return p;
}

NodeT *balancedTree(NodeT *p)
{
    preorderEchilibrum(p);
    NodeT *j;
    if(p->e==-2)
    {
        j=p->left;
        if(j->e==1)
        {
            p=rotateLeft_Right(p);
        }
        else
        {
            p=rotateRight(p);
        }
    }
    else if(p->e==2)
    {
        j=p->right;
        if(j->e==-1)
        {
            p=rotateRight_Left(p);
        }
        else
        {
            p=rotateLeft(p);
        }
    }
    return p;
}

NodeT *deleteNode(NodeT *root,int data)
{
    NodeT *m,*n,*o;
    if(root!=NULL)
    {
        if(root->k<data)
        {
            root->right=deleteNode(root->right,data);
        }
        else if(root->k>data)
       {
            root->left=deleteNode(root->left,data);
        }
        else
        {
            m=root;
            if(m->right==NULL)
            {
                root=m->left;
            }
            else if(m->left==NULL)
            {
                root=m->right;
            }
            else
            {
                n=m->left;
                o=m;
                if(n->right!=NULL)
                {
                    o=n;
                    n=n->right;
                }
                root->k=n->k;
                m=n;
                o->right=n->left;
                o=root->left;
                n=n->left;
                if (o!=NULL)
                {
                    while ((o!=n)&&(o!=NULL))
                    {
                        o =balancedTree(o);
                        o=o->right;
                    }
                }
                else
                {
                    root->k=n->k;
                    root->left=n->left;
                    m=n;
                }
            }
            free(m);
        }
    }
    if (root!=NULL)
        root = balancedTree(root);
    return root;
}
void printElement(NodeT *root)
{
    printf("%d ",root->k);
}

//copied from GitHub :D
void prettyPrint(NodeT *root,int recLevel)
{
    if(root==NULL)
    {
        recLevel--;
        return;
    }
    else
    {
        recLevel++;
        prettyPrint(root->right,recLevel);
        int j;
        for(j=0; j<recLevel-1; j++)
        {
            printf("     ");
        }
        printElement(root);
        printf("\n");
        prettyPrint(root->left,recLevel);
    }
}
int main()
{
    NodeT *root=createStaticTree();
    AVLTree(root);
   // root=insertNode(root,18); //try to add 18;
    //root=insertNode(root,5);//try to add 5 and error message: this node already exists (which is ok for my example tree)
    root=deleteNode(root,4);
    root=insertNode(root,4); //inserted but not in the first position as given in the static tree! Is it ok?
    prettyPrint(root,0);
    return 0;
}
