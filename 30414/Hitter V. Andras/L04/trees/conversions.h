#ifndef CONVERSIONS_H_INCLUDED
#define CONVERSIONS_H_INCLUDED

void TreeToList(NodeT *root)
{
    if(root==NULL)
    {
        AddLast('*');
    }
    else
    {
        AddLast(root->data);
        TreeToList(root->left);
        TreeToList(root->right);
    }

}

NodeT* ListToTree()
{
    NodeT *a=NULL;
    if (head!=NULL)
    {
        int i=head->data;
        if(i==42)
        {
            head=head->next;
        }
        else
        {
            a=createNode(head->data);
            head=head->next;
            a->left=ListToTree();
            a->right=ListToTree();

        }


    }
    return a;
}

#endif // CONVERSIONS_H_INCLUDED
