//example input : 7 4 3 * * 6 * * 19 8 * 17 * * *
//insert  node : 16

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct nodeBT{
    int data;
    int ht;
    struct nodeBT *left, *right;
}node;

void prettyPrint(node *root,int recLevel);

node *createNode(int x){
    node *p=(node*)malloc(sizeof(node));
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    return p;
}

node *createBinaryTree(){
    char *content=(char*)malloc(sizeof(char)*3);
    scanf("%s",content);
    node *p=createNode(atoi(content));
    if(strcmp(content,"*")==0)
        return NULL;
    else {
        printf("left child of %d parent : ",atoi(content));
        p->left=createBinaryTree();
        printf("right child of %d parent : ",atoi(content));
        p->right=createBinaryTree();
    }
    return p;
}

int height(node *T)
{
               int lh,rh;
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

node * rotateright(node *x)
{
               node *y;
               y=x->left;
               x->left=y->right;
               y->right=x;
               x->ht=height(x);
               y->ht=height(y);
               return(y);
}
node * rotateleft(node *x)
{
               node *y;
               y=x->right;
               x->right=y->left;
               y->left=x;
               x->ht=height(x);
               y->ht=height(y);
               return(y);
}
node *RR(node *T)
{
               T=rotateleft(T);
               printf("after the left rotation : \n");
               prettyPrint(T,0);
               return(T);
}
node * LL(node *T)
{
               T=rotateright(T);
               printf("after the right rotation : \n");
               prettyPrint(T,0);
               return(T);
}
node * LR(node *T)
{
               T->left=rotateleft(T->left);
               printf("after the left rotation : \n");
               prettyPrint(T,0);
               T=rotateright(T);
               printf("after the right rotation : \n");
               prettyPrint(T,0);
               return(T);
}
node * RL(node *T)
{
               T->right=rotateright(T->right);
               printf("after the right rotation : \n");
               prettyPrint(T,0);
               T=rotateleft(T);
               printf("after the left rotation : \n");
               prettyPrint(T,0);
               return(T);
}

int BF(node *root){ //binary tree node hight
    int lh,rh;
    if(root==NULL)
        return(0);
    if(root->left==NULL)
        lh=0;
        else{
            root->left->ht=height(root->left);
            lh=1+root->left->ht;
        }
    if(root->right==NULL)
        rh=0;
        else{
            root->right->ht=height(root->right);
            rh=1+root->right->ht;
        }
    return(lh-rh);
}

node *insertNode(node *root, int cont){
    if(root==NULL){
        return createNode(cont);
    }
    else
    if(cont>root->data) {
        root->right=insertNode(root->right,cont);
        if(BF(root)==-2){
            if(cont>root->right->data)
                root=RR(root);
                else
                    root=RL(root);
        }
    }
    else
    if(cont<root->data) {
        root->left=insertNode(root->left,cont);
        if(BF(root)==2){
            if(cont < root->left->data)
                root=LL(root);
                else
                  root=LR(root);
        }
    }
    /*else{
        if(cont==root->data) printf("the node %d already exists in the tree",cont);
        return root;
    }*/
    root->ht=height(root);
    return(root);
}

int isBST(node *root, int min, int max){
    if (root==NULL) return 1;
    if(root->data<min || root->data>max)
        return 0;
    else return isBST(root->right, root->data, max) && isBST(root->left, min,root->data);
}

/*node *AVL(node *rootl, node *rootr){
    rootl->ht=height(rootl);
    rootr->ht=height(rootr);
    if(abs(rootl->ht-rootr->ht)>1) {
        printf("the tree is not an AVL tree \n The corresponding AVL tree is : ");

    }

}*/

void prettyPrint(node *root,int recLevel) //! root, index, length, reccurence level
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

/*node *delete(node *root){
    if (root->left!=NULL) {
        while(root->left != NULL){
            root=root->left;
            free(root);
        }}
    else if (root->right !=NULL)
    {
        while(root->right !=NULL){
            root=root->right;
            free(root);
        }
    }
    root=NULL;
    root->left=NULL;
    root->right=NULL;
    return root;
}*/

int main()
{
    printf("root : ");
    node *root=createBinaryTree();
    while(isBST(root,INT_MIN,INT_MAX)==0){
        if (isBST(root,INT_MIN,INT_MAX)==0)
            printf("the tree is not a Binary Search Tree ! \n input again : \n");
        prettyPrint(root,0);
        printf("\n");
        //root=delete(root);
        printf("root : ");
        node *root=createBinaryTree();
        isBST(root,INT_MIN,INT_MAX);
    }

    prettyPrint(root,0);
    //root=AVL(root);
    int x=1,i;
    while(x==1){
        printf("give the node you want to insert : ");
        scanf("%d",&i);
        root=insertNode(root,i);
        prettyPrint(root,0);
        printf("do you want to insert another node? (1=yes, 0=no) \n");
        scanf("%d",&x);
    }
    return 0;
}
