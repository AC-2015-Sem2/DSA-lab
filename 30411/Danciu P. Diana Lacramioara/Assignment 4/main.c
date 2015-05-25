#include "header.h"

int main()
{
    TreeT *root;
    int data,nr,i,op;
    do
    {
        printf("\n1.Create:");
        printf("\n2.Insert:");
        printf("\n3.Delete:");
        printf("\n4.Print:");
        printf("\n5.End programme:");
        printf("\n\nEnter Your Choice:");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            printf("\nEnter number of elements to be introduced:");
            scanf("%d", &nr);
            printf("\nEnter tree data:");
            root=NULL;
            for(i=0; i<nr; i++)
            {
                scanf("%d",&data);
                root=Insert(root,data);
            }
            break;
        case 2:
            printf("\nEnter a data:");
            scanf("%d",&data);
            root=Insert(root,data);
            break;
        case 3:
            printf("\nEnter a data:");
            scanf("%d",&data);
            root=Delete(root,data);
            break;
        case 4:
            prettyPrint(root, 0);
            printf("\n");
            break;
        }
    }
    while(op!=5);

    return 0;
}
