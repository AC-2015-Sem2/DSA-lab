#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node* left;
    struct node* right;
    char* data;
}NodeTree;

typedef struct StructNod
   {
      char* data;
      struct StructNod *next;
      struct StructNod *prev;
   }NodeList;

NodeList *head, *tail;


NodeTree* CreateNodeTree(int data)
{
    NodeTree* newnode=(NodeTree*)malloc(sizeof(NodeTree));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;

}

NodeTree* CreateBinaryTree()
 {
     NodeTree* p;
     char* data=(char*)malloc(sizeof(char)*100);
     scanf("%s",data);
     if (strcmp(data,"*")==0)
     {
         return NULL;
     }
     else {
          p=CreateNodeTree(atoi(data));
          p->left=CreateBinaryTree();
          p->right=CreateBinaryTree();
     }
     return p;
 }

NodeList* Tree_To_List(NodeTree* root)
{
    NodeList* node = (NodeList*)malloc(sizeof(NodeList));
    if (root==NULL)
       {
           node->data = (char*)malloc(1);
           strcpy(node->data, "*");
       }
       else
          {
              node->data = (char*)malloc(30);
              strcpy(node->data, root->data);
          }

    node->next = NULL;
    node->prev = tail;

    if (tail!=NULL)
       {
           tail->next = node;
       }
    tail = node;
    if (root!=NULL)
       {
           Tree_To_List(root->left);
           Tree_To_List(root->right);
       }
    return node;
}

void preorder(NodeList* head)
{
    while (head!=NULL)              //traverse the list and print
    {
        printf("%s ", head->data);
        head = head->next;
    }
    printf("\n");
}

void PrettyPrint(NodeTree* root, int val)
{
    if (root==NULL) return;
    PrettyPrint(root->right, val+4);
    int i;
    for (i=0; i<val; i++)
    {
        printf("     ");
    }
    printf("%s\n", root->data);
    PrettyPrint(root->left, val+4);
}
int main()
{
   NodeTree* root=CreateBinaryTree();
  // NodeList* FirstFromList=GetListFromTree(root);
  // TraverseList(FirstFromList);
  // root=GetTreeFromList(FirstFromList);
   PrettyPrint(root,0);
    return 0;
}
