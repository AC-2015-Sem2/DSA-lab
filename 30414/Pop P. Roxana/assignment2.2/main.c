#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_h.h"

FILE * f;

int main()
{
    ///OPENING THE FILES
    f=fopen("input.dat","r");
    if (f==NULL) perror("The input file could not be opened\n");
    FILE * g=fopen("output.dat","w");
    if (g==NULL) perror("The output file could not be opened\n");

    ///READING THE FIRST LINE AND PUTTING THE DATA IN THE LIST OF SECCONDS
    char * line=(char*)malloc(1024*sizeof(char));
    fgets(line,1024,f);
    char * tok;
    tok=strtok(line," ");
    while (tok!=NULL)
    {
        int data;
        sscanf(tok,"%d",&data);
        enqueueS(data);
        tok=strtok(NULL," ");
    }
    memset(line,0,1024);

    ///READING THE REST OF THE DATA FROM THE FILE: THE PART RELATED TO THE CUSTOMERS
    char * name=(char*)malloc(20*sizeof(char));
    int x,y;
    while (fscanf(f,"%s%d%d",name,&x,&y)!=-1)
    {
        enqueue(name,x,y);
    }
    ///COMPUTING THE AMOUNT OF MONEY THE CASHIER HAS AFTER EACH PERIOD OF TIME
    int cashierMoney=0;
    int passedSec=0;
    while(shead!=NULL)
    {
        int secToPrint=shead->sec;
        shead->sec-=passedSec;
        while ((head!=NULL)&&((shead->sec)-head->sec>=0))
        {
            cashierMoney+=head->money;
            shead->sec=(shead->sec)-head->sec;
            passedSec+=head->sec;
            dequeue();
        }
        fprintf(g,"After %d seconds: %d\n",secToPrint,cashierMoney);
        dequeueS();
    }
    fclose(f);
    fclose(g);
    return 0;
}
