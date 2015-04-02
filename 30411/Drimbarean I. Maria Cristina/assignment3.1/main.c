#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct tree
{
  int data;
  struct tree *left;
  struct tree *right;
}NodeT;
typedef struct list
{
    char *data;
    struct list *next;
}NodeL;
char s[200];
char c[10];
NodeT* createNode(int x)
  {
      NodeT *p;
      p=(NodeT*)malloc(sizeof(NodeT));
      p->data=x;
      p->left=p->right=NULL;
      return p;
  }
NodeT* createBinTree()
{
    char* content=(char*) malloc(sizeof(char)*20);
     NodeT* p;
     scanf("%s",content);
     if (strcmp(content,"*")==0)
        return NULL;
     else{
        p=createNode(atoi(content));
        p->left=createBinTree();
        p->right=createBinTree();
     }
     return p;
}
void makeString(NodeT *root)
  {
     if (root!=NULL)
      {
          if (root->left==NULL && root->right==NULL)
          {
              itoa(root->data,c,10);
              strcat(s,c);
              strcat(s," ");
              strcat(s,"* ");
          }
          else
          {
              itoa(root->data,c,10);
              strcat(s,c);
              strcat(s," ");
          }
          makeString(root->left);
          makeString(root->right);
          if (root->right==NULL) strcat(s,"* ");
      }
  }
NodeL* getListFromTree(NodeT *root)
{
  NodeL *head;
  NodeL *tail;
  makeString(root);
  char *stok;
  stok=strtok(s," ");
    while (stok!=NULL)
    {
        if (head==NULL)//addLast
    {
        head=(NodeL*)malloc(sizeof(NodeL));
        head->data=stok;
        head->next=NULL;
    }
    else if(tail==NULL)
    {
        tail=(NodeL*)malloc(sizeof(NodeL));
        tail->data=stok;
        tail->next=NULL;
    }
    else
    {
        NodeL *now=(NodeL*)malloc(sizeof(NodeL));
        now->data=stok;
        now->next=NULL;
        tail->next=now;
        tail=now;
    }
        stok=strtok(NULL," ");
    }
  return head;
}
void traverseList(NodeL *head)
{
    printf("the list is:");
    NodeL *p=head;
    while (p!=NULL)
    {
        printf("%s ",p->data);
        p=p->next;
    }
}
NodeT* getTreeFromList(NodeL *head)
{
  char* content=(char*) malloc(sizeof(char)*20);
     NodeT* p;
     strcpy(content,head->data);
     if (strcmp(content,"*")==0)
        return NULL;
     else{
        p=createNode(atoi(content));
        p->left=getTreeFromList(head->next);
        p->right=getTreeFromList(head->next);
     }
     return p;
}
void preorder(NodeT *root)
  {
     if (root!=NULL)
      {
          printf("%2d ",root->data);
          preorder(root->left);
          preorder(root->right);
      }
  }
  void printElement(NodeT * node)
{
    printf ( "%d " ,(int) node->data );
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
    printElement(root);

    //! print  a new line
    printf("\n");

    prettyPrint(root->left,recLevel); //! keep going left in the tree
}
int main()
{
    NodeT * root=createBinTree();
    NodeL * firstFromList=getListFromTree(root);
    traverseList(firstFromList);
    root=getTreeFromList(firstFromList);
    printf(" ");
    prettyPrint(root,0);
    return 0;
}
