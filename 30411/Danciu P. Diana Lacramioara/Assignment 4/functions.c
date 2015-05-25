#include "header.h"

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

int BF(TreeT *T)
{
    int lh;
    int rh;

    if(T==NULL)
        return(0);
    if(T->left==NULL)
        lh=0;
    else
        lh=1+T->left->ht;
    if(T->right==NULL)
        rh=0;
    else
        rh=1+T->right->ht;

    return(lh-rh);
}

int height(TreeT *T)
{
    int lh;
    int rh;

    if(T==NULL)
        return(0);
    if(T->left==NULL)
        lh=0;
    else
        lh=1+T->left->ht;
    if(T->right==NULL)
        rh=0;
    else
        rh=1+T->right->ht;
    if(lh>rh)
        return(lh);

    return(rh);
}

TreeT *rotate_right(TreeT *x)
{
    TreeT *y;

    y=x->left;
    x->left=y->right;
    y->right=x;
    x->ht=height(x);
    y->ht=height(y);

    return(y);
}
TreeT *rotate_left(TreeT *x)
{
    TreeT *y;

    y=x->right;
    x->right=y->left;
    y->left=x;
    x->ht=height(x);
    y->ht=height(y);

    return(y);
}
TreeT *RR(TreeT *T)
{
    T=rotate_left(T);
    return(T);
}
TreeT *LL(TreeT *T)
{
    T=rotate_right(T);
    return(T);
}
TreeT *LR(TreeT *T)
{
    T->left=rotate_left(T->left);
    T=rotate_right(T);
    return(T);
}
TreeT *RL(TreeT *T)
{
    T->right=rotate_right(T->right);
    T=rotate_left(T);
    return(T);
}

TreeT* Insert(TreeT *T, int x)
{
    if(T==NULL)
    {
        T=(TreeT*)malloc(sizeof(TreeT));
        T->data=x;
        T->left=NULL;
        T->right=NULL;
    }
    else if(x > T->data)               // insert in right subtree
    {
        T->right=Insert(T->right,x);
        if(BF(T)==-2)
        {
            if(x>T->right->data)
                T=RR(T);
            else
                T=RL(T);
        }
    }
    else if(x<T->data)
    {
        T->left=Insert(T->left,x);
        if(BF(T)==2)
        {
            if(x < T->left->data)
                T=LL(T);
            else
                T=LR(T);
        }
    }
    T->ht=height(T);

    return(T);
}

TreeT* Delete(TreeT *T,int x)
{
    TreeT *p;

    if(T==NULL)
    {
        return NULL;
    }
    else

        if(x > T->data)       // insert in right subtree
        {
            T->right=Delete(T->right,x);
            if(BF(T)==2)
            {
                if(BF(T->left)>=0)
                    T=LL(T);
                else
                    T=LR(T);
            }
        }
        else if(x<T->data)
        {
            T->left=Delete(T->left,x);
            if(BF(T)==-2) //Rebalance during windup
            {
                if(BF(T->right)<=0)
                    T=RR(T);
                else
                    T=RL(T);
            }
        }
        else
        {
            //data to be deleted is found
            if(T->right !=NULL)
            {
                //delete its inorder succesor
                p=T->right;
                while(p->left != NULL)
                    p=p->left;

                T->data=p->data;
                T->right=Delete(T->right,p->data);
                if(BF(T)==2)//Rebalance during windup
                {
                    if(BF(T->left)>=0)
                        T=LL(T);
                    else
                        T=LR(T);
                }
            }
            else
                return(T->left);

        }
    T->ht=height(T);

    return(T);
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
