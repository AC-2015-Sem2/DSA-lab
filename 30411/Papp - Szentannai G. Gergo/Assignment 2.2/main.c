#include <stdio.h>
#include <stdlib.h>

#include "DLL.h"
#include "DLL_TYPES.h"

int main()
{
    FILE *pf; // Input
    pf=fopen("input.dat","r");
    if (pf==NULL)
    {
        perror("Cannot open file");
        return(-1);
    }

    FILE *f; // Output
    f=fopen("output.dat","w");
    if (f==NULL)
    {
        perror("Cannot open file");
        return(-1);
    }

    // Setting initial data for sentinels storing time and customer information:
    // This method might seem ugly, but this is how I managed not to have global variables (I usually try not to use globals)

    sentinel time; // Time
    time.length=(int*)malloc(sizeof(int*));
    time.head=(NodeT*)malloc(sizeof(NodeT*));
    time.tail=(NodeT*)malloc(sizeof(NodeT*));
    *(time.length)=0;
    time.head->code=time.tail->code=0;

    sentinel cust_t; // Time required for each customer
    cust_t.length=(int*)malloc(sizeof(int*));
    cust_t.head=(NodeT*)malloc(sizeof(NodeT*));
    cust_t.tail=(NodeT*)malloc(sizeof(NodeT*));
    *(cust_t.length)=0;
    cust_t.head->code=cust_t.tail->code=0;

    sentinel cust_m; // Monet spent by each customer
    cust_m.length=(int*)malloc(sizeof(int*));
    cust_m.head=(NodeT*)malloc(sizeof(NodeT*));
    cust_m.tail=(NodeT*)malloc(sizeof(NodeT*));
    *(cust_m.length)=0;
    cust_m.head->code=cust_m.tail->code=0;


    char aux[10];
    int a,b;


    // Reading time values:
    int x=0;
    while (fscanf(pf,"%d ",&a)==1)
    {
        AL(time,a-x);
        x=a;
    }

    // Reading Customer info (without customer name)
    while ((fscanf(pf,"%s %d %d",aux, &a, &b)==3))
    {
        AL(cust_m,a);
        AL(cust_t,b);
    }

    // Computing money gained at each given time:

    int money=0;
    int t=0;
    t=time.head->code;
    while (*(time.length)!=0)
    {
        if (*(cust_t.length)==0)
        {
            while (*(time.length)!=0)
            {
                fprintf(f,"After %d seconds: %d RON.\n",t,money);
                DF(time);
                t=t+time.head->code;
            }
        }
        else if (time.head->code==0)
        {
            fprintf(f,"After %d seconds: %d RON.\n",t,money);
            DF(time);
            t=t+time.head->code;
        }
        else if (time.head->code<cust_t.head->code)
        {
            cust_t.head->code=cust_t.head->code-time.head->code;

            time.head->code=0;

        }
        else if (time.head->code==cust_t.head->code)
        {
            money=money+cust_m.head->code;
            DF(cust_m);

            time.head->code=0;
            DF(cust_t);
        }
        else if (time.head->code>cust_t.head->code)
        {
            money=money+cust_m.head->code;
            DF(cust_m);

            time.head->code=time.head->code-cust_t.head->code;
            DF(cust_t);
        }
    }
    fclose(pf);
    fclose(f);
    return 0;
}
