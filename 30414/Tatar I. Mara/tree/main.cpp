#include <string.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct node{
                               struct node *left;
                               struct node *right;
                               char* data;
                               }NodeT;
typedef struct node1{
                             struct node1 *next;
                               struct node1 *prev;
                               char* data1;
                               }NodeL;

NodeT* createNode(char *d)
    {
        NodeT *newnode;
        newnode=(NodeT*)malloc(sizeof(NodeT));
        newnode->data=d;
        return newnode;
    }
NodeT *CreateBinTree(FILE *f)
    {
        NodeT *p;
        char *return_val;
        return_val=(char*)malloc(sizeof(char));
        fscanf(f,"%s",return_val);
        if (strcmp(return_val,"*")==0)
            return NULL;
        else
        {
            p=createNode(return_val);
            p->left=CreateBinTree(f);
            p->right=CreateBinTree(f);
        }
        return p;
    }

    void AddLast(NodeL* head,char *data )
    {   NodeL *newnode;
        newnode=(NodeL*)malloc(sizeof(NodeL));
        newnode->data1=data;
        if (head==NULL)
            {newnode->prev=NULL;
            newnode->next=NULL;
            head=newnode;}
        else
            {newnode->prev=head;
            newnode->next=NULL;
            head=newnode;}
    }

    void CreateList(NodeT* root,NodeL*head)
    { if (root==NULL)
              AddLast(head,"*");
     else
       {
      AddLast(head,root->data);
     CreateList(root->left,head);
     CreateList(root->right,head);
       }



    }


NodeL* getListfromTree(NodeT* root)
{ NodeL *head;
head=(NodeL*)malloc(sizeof(NodeL));
  CreateList(root,head);
   while(head->prev!=NULL)
    {
        head->prev->next=head;
        head=head->prev;
    }
    return head;
}


void traverseList(NodeL *head)
{  while (head != NULL)
	{   printf("%s ", head->data1);
		head = head->next;
	}
	printf("\n");
}

    NodeT *getTreeFromList(NodeL *head)
{
	NodeT *root;
    NodeL *first;
    first=head;
    head=first->next;
    if(first == NULL || strcmp(first->data1, "*") == 0)
    {
        return NULL;
    }
    else
    {
        root=createNode(first->data1);
        root->left=getTreeFromList(head);
        root->right=getTreeFromList(head);
        return root;
    }
}
void prettyPrint(NodeT *root,int level)
{
    if(root==NULL)
    {
        level=level-1;
        return ;
    }
    level=level+1;
    prettyPrint(root->right,level);
    int j=0;

    for(j=0; j<level-1; j++)
    {
        printf("  ");
    }
    printf("%s", root->data);
    printf("\n");
    prettyPrint(root->left,level);
}

int main()
{      FILE *f=fopen("input.txt","r");
    NodeT *root=CreateBinTree(f);
    NodeL*firstFromList=getListfromTree(root);
    traverseList(firstFromList);
    root=getTreeFromList(firstFromList);
    prettyPrint(root,0);
     fclose(f);
    return 0;

}
