#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char *value;
    struct node *left;
    struct node *right;
}nodeT;

typedef struct list
{
    char *value;
    struct list *prev;
    struct list *next;
}nodeL;

nodeL *head, *tail;
nodeT *root;

nodeT *CreateTree()
{
    char *value=(char*)calloc(30,sizeof(char));
    scanf("%s",value);
    if(strcmp(value,"*")==0)
        return NULL;
    else
    {
        nodeT *p=(nodeT*)malloc(sizeof(nodeT));
        p->value=value;
        p->left=CreateTree();
        p->right=CreateTree();
        return p;
    }
}

void AddNode(char *value)
{
    nodeL *p=(nodeL*)malloc(sizeof(nodeL));
    p->value=value;

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

nodeL *MakeListFromTree(nodeT *root)
{
    if(root==NULL)
    {
        AddNode("*");
    }
    else
        {
            AddNode(root->value);
            MakeListFromTree(root->left);
            MakeListFromTree(root->right);
        }
return head;
}


nodeT *MakeTreeFromList(nodeL **head)
{
   if(strcmp((*head)->value,"*")==0)
   {
       *head=(*head)->next;
       return NULL;
   }
   else
    {
        nodeT *p=(nodeT*)malloc(sizeof(nodeT));
        p->value=(*head)->value;
        *head=(*head)->next;
        free((*head)->prev);
        p->left=MakeTreeFromList(head);
        p->right=MakeTreeFromList(head);
        return p;
    }
}

void DestoryTree(nodeT *root)
{
    if(root==NULL) return;

    DestoryTree(root->left);
    DestoryTree(root->right);
    free(root);
}

void PreetyPrint(nodeT *root,int level)
{int i;
 if(root==NULL)   {
        level--;
       return;
   }
    level++;
    PreetyPrint(root->right,level);
    for(i=0; i<level-1; i++)
    {
        printf("\t");
    }
    printf ( "%s \n" ,root->value );
    PreetyPrint(root->left,level);

}

void printList()
{
    nodeL *temp=head;
    while(temp != NULL)
    {
        printf("%s ",temp->value);
        temp=temp->next;
    }
    printf("\n");
}


int main()
{
   root=CreateTree();
   head=MakeListFromTree(root);
   printList();
   DestoryTree(root);
   root=MakeTreeFromList(&head);
   PreetyPrint(root,0);

   return 0;
}

