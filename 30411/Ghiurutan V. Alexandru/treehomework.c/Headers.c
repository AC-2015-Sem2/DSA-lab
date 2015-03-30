#include "Header.h"

NodeT * createBinTree()
{
    NodeT *p;
    char *content=(char *)malloc(sizeof(char)*MAX_CONTENT);
     scanf("%s",content);
    if(strcmp((content),"*")==0)
    {
        return NULL;
    }
    else
    {
        p=(NodeT *)malloc(sizeof(NodeT));
        if(p==NULL)
        {
            perror("Not enough memory!\n");
            exit(1);
        }
        p->data=atoi(content);
        p->left=createBinTree();
        p->right=createBinTree();
    }
    return p;
}

void addlast(char key[])
{
    if(head==NULL)
    {
        head=(NodeL *)malloc(sizeof(NodeL));
        strcpy(head->code,key);
        head->next=NULL;
        head->previous=NULL;
        tail=head;
    }
    else
    {
        NodeL *q=(NodeL *)malloc(sizeof(NodeL));
        strcpy(q->code,key);
        q->next=NULL;
        q->previous=tail;
        tail->next=q;
        tail=q;
    }
}

void preorder(NodeT *root)
{
    if(root!=NULL)
    {int x=root->data;
char s[10];
sprintf(s,"%d",x);
        addlast(s);
        preorder(root->left);
        preorder(root->right);
    }
    else
    {
        addlast("*");
    }
}


NodeL *createListFromTree(NodeT *root)
{head=NULL;
tail=NULL;
    preorder(root);
return head;
}

void traverseList(NodeL *head)
{printf("The list content:\n");
    if(head!=NULL)
    {
      NodeL *q=head;
      while(q!=NULL)
      {
          if(strcmp(q->code,"*")==0)
          {
          printf("%s ",q->code);}
          else
          {
              printf("%d ",atoi(q->code));
          }
          q=q->next;
      }
    }
printf("\n");
}
NodeT *getTreeFromList()
{
  NodeT *p;
  char *content=(char *)malloc(sizeof(char)*MAX_CONTENT);
  strcpy(content,head->code);
  head=head->next;
  if(strcmp(content,"*")==0)
  {
   return NULL;
  }
  else
{
p=(NodeT *)malloc(sizeof(NodeT));
p->data=atoi(content);
p->left=getTreeFromList();
p->right=getTreeFromList();
}
return p;
}
void printElement(NodeT *root)
{
    printf("%d ",root->data);
}


void prettyPrint(NodeT*root,int recLevel)
{
   if(root==NULL)
    {
        recLevel--;
        return;
    }
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
