#include <stdio.h>
#include <stdlib.h>
typedef struct s_NODE
    {
        int data;
        struct s_NODE *next;
    } NODE;
    NODE *head,*tail ;

    void AF(int data) /*addFirst*/
   {struct NODE *newnode;
        if (head==NULL)
        {
            head= (NODE*)malloc(sizeof(NODE));
            head->data=data;
            head->next=NULL;
            tail=head;
        }
        else
        {
            NODE *newnode=(NODE*)malloc(sizeof(NODE));
            newnode->data=data;
            newnode->next=head;
            head=newnode;
        }
   }

    void AL(int data) /*addLast*/
{    NODE *newnode;
        if(head=NULL)
        {
            head=(NODE*)malloc(sizeof(NODE));
            head->data=data;
            head->next=NULL;
            tail=head;
        }
        else
        {
            newnode=(NODE*)malloc(sizeof(NODE));
            newnode->data=data;
            newnode->next=NULL;
            tail->next=newnode;
            tail=newnode;
        }
}
    void DF()/* delete first*/
        {
             NODE *tmp;
            tmp=head;
            head=head->next;
            free(tmp);
        }

    void DL()/*delete last*/
        {   if (head==NULL)
            printf("list is empty");
            else
                {
                     NODE *curr;
                    curr=head;
                    while (curr->next != NULL)
                    {
                        curr=curr->next;
                        head=curr;

                    }
                    free(head);
                    head=NULL;
                }
        }

        void DOOM_THE_LIST()/*deletes all*/
        {
             NODE *temp;
            while (head != NULL)
                {
                        temp = head;
                        head = temp->next;
                        free(temp);
                }
        }

            int DE(int x)
        {
             NODE *temp, *prev;
            temp=head;
            while(temp!=NULL)
                {
                if(temp->data==x)
                    {
                    if(temp==head)
                        {
                        head=temp->next;
                        free(temp);
                        return 1;
                        }
                    else
                        {
                        prev->next=temp->next;
                        free(temp);
                        return 1;
                        }
                    }
                    else
                        {
                        prev=temp;
                        temp= temp->next;
                        }
                    }
                return 0;
        }


   void print_all()
   {  FILE *fp;
       NODE *p;
       p=head;
       fp=fopen("output.dat","w");
       while(p->next !=NULL)
       {
           fprintf(fp,"%d",p->data);
           p=p->next;
       }
       fclose(fp);
   }

   void print_x(int x)
   {    int cont;
       FILE *fp;
       NODE *p;
       cont=0;
       p=head;
       fp=fopen("output.dat","w");
       while((p->next !=NULL)&&(cont<=x))
       {
           fprintf(fp,"%d",p->data);
           p=p->next;
           cont++;
       }
       fclose(fp);
   }

      void print_last_x(int x)
   {    int cont;
       FILE *fp;
       NODE *p;
       cont=0;
       p=head;
       fp=fopen("output.dat","w");
       while((p->next !=NULL)&&(cont<=x))  /* nu stiu cum se face/*/
       {
           fprintf(fp,"%d",p->data);
           p=p->next;
           cont++;
       }
       fclose(fp);
   }
  void print_all_on_screen()
   {
       NODE *p;
       p=head;
       while(p->next !=NULL)
       {
           printf("%d",p->data);
           p=p->next;
       }
   }

 int main()
 {
     int i,num;
     NODE *n;
    head=NULL;
    while(1)
    {
    printf("\nList Operations\n");
    printf("===============\n");
    printf("1.add first\n");
    printf("2.add last\n");
    printf("3.delete first\n");
    printf("4.Delete last\n");
     printf("5.doom the list\n");
    printf("6.delete value x\n");
    printf("7.print all\n");
    printf("8.print first xt\n");
    printf("9.print last x\n");
     printf("10.EXIT\n");


      printf("Enter your choice : ");
    if(scanf("%d",&i)<=0){
        printf("Enter only an Integer\n");
        exit(0);
    } else {
        switch(i)
        {
        case 1:      printf("Enter the number to add : ");
                 scanf("%d",&num);
                 AF(num);
                 print_all_on_screen();
                 break;
        case 2:      printf("Enter the number to add : ");
                 scanf("%d",&num);
                 AL(num);
                 print_all_on_screen();
                 break;
        case 3:     if(head==NULL)
                {
                printf("List is Empty\n");
                }
                else
                {
                DF();
                print_all_on_screen();
                break;
        case 4: if(head==NULL)
                {
                printf("List is Empty\n");
                }
                else
                {
                DL();
                print_all_on_screen();
                break;
        case 5:     DOOM_THE_LIST();
               print_all_on_screen();
               printf("List is Empty\n");

                break;
        case 6: if(head==NULL)
                printf("List is Empty\n");
                else{
                printf("Enter the number to delete : ");
                scanf("%d",&num);
                if(delete(num))
                    {printf("%d deleted successfully\n",num);
                    print_all_on_screen();}
                else
                    printf("%d not found in the list\n",num);
                }
                break;
        case 7:  if(head==NULL)
                {
                printf("List is Empty\n");
                }
                else
                {
                    print_all();
                }
                break;

        case 8:      if(head==NULL)
                printf("List is Empty\n");
                else{
                printf("Enter the number of values to print : ");
                scanf("%d",&num);
                print_x(num);
                }
        case 9:       if(head==NULL)
                printf("List is Empty\n");
                else{
                printf("Enter the number of values to print : ");
                scanf("%d",&num);
                print_last_x(num);
                };
        case 10:return 0;
        default:    printf("Invalid option\n");
        }
    }
    }
    return 0;
}};

