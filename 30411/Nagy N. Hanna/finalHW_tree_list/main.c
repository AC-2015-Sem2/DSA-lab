#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodeTree
{
    char *data;
    struct nodeTree *left;
    struct nodeTree *right;
}nodeT;

typedef struct nodeList
{
    char *data;
    struct nodeList *prev;
    struct nodeList *next;
}nodeL;
nodeL *head, *tail;
nodeT *root;


nodeT *createBinTree();
void addLast(char *);
nodeL *getListfromTree(nodeT *);
void printList();   //==traverseList();
nodeT *getTreefromList(nodeL **);
void deleteTree(nodeT*);
void prettyPrint(nodeT *,int);

int main()
{
   root=createBinTree();
   head=getListfromTree(root);
   printf("The List from the Tree is: ");
   printList();
   deleteTree(root);
   root=NULL;
   root=getTreefromList(&head);
   printf("\nThe Tree from the List is: \n");
   prettyPrint(root,0);

   return 0;
}

nodeT *createBinTree()
{
    char *data=(char*)malloc(sizeof(char)*20);
    scanf("%s",data);
    if(strcmp(data,"*")==0)
        return NULL;
    else
    {
        nodeT *p=(nodeT*)malloc(sizeof(nodeT));
        p->data=data;
        p->left=createBinTree();
        p->right=createBinTree();
        return p;
    }
}

void addLast(char *data)
{
    nodeL *p=(nodeL*)malloc(sizeof(nodeL));
    p->data=data;

    if(head==NULL)
    {
        p->prev=NULL;
        p->next=NULL;
        head=p;
        tail=head;
    }
    else
        {
        tail->next=p;
        p->prev=tail;
        p->next=NULL;
        tail=p;
        }
}

nodeL *getListfromTree(nodeT *root)
{
    if(root==NULL)
    {
        addLast("*");
    }
    else
        {
            addLast(root->data);
            getListfromTree(root->left);
            getListfromTree(root->right);
        }
return head;
}


void printList()
{
    nodeL *aux=head;
    while(aux != NULL)
    {
        printf("%s ",aux->data);
        aux=aux->next;
    }
    printf("\n");
}


nodeT *getTreefromList(nodeL **head)
{
   if(strcmp((*head)->data,"*")==0)
   {
       *head=(*head)->next;
       return NULL;
   }
   else
    {
        nodeT *p=(nodeT*)malloc(sizeof(nodeT));
        p->data=(*head)->data;
        *head=(*head)->next;
        free((*head)->prev);
        p->left=getTreefromList(head);
        p->right=getTreefromList(head);
        return p;
    }
}

void deleteTree(nodeT *root)
{
    if(root==NULL) return;

    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
}

void prettyPrint(nodeT *root,int level)
{
 if(root==NULL)   {
        level--; //! reached leaf, must decrement recurence level
       return;
   }
    level++; //! otherwise increment it
    prettyPrint(root->right,level); //! keep going right in the tree
    int j=0;

    //! print spaces for the appropriate recurence level
    for(j=0; j<level-1; j++)
    {
        printf("     ");
    }
    //! then print value
    //printElement(root);
    printf ( "%s " ,root->data );
    //! print  a new line
    printf("\n");

    prettyPrint(root->left,level); //! keep going left in the tree

}


