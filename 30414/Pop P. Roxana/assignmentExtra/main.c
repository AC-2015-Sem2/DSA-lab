#include <stdio.h>
#include <stdlib.h>
#include "list_h.h"
#include <string.h>



int main()
{
    /***********************************OPENING OF THE FILES *********************************************************/
    FILE *f;
    FILE *g;
    f=fopen("input.dat","r");
    if (f==0) printf("error1");
    g=fopen("output.dat","w");
    if (g==0) printf("error2");

    /**********************************CREATING THE LIST FOR THE SENTINELS*******************************************/
    int N;
    fscanf(f,"%d",&N);
    int i;
    for (i=0;i<N;i++)
    {
        int data;
        fscanf(f,"%d",&data);
        addLastSentinel(data);
    }

    /*****************************************************************************************************************
    ***********************************READING THE REST OF THE DATA FROM THE FILE************************************/

    int M;
    fscanf(f,"%d",&M);
    fscanf(f,"\n");
    for (i=0;i<M;i++)//going on every line till the end of the file
    {
        char *line=(char*)malloc(1024*sizeof(char));
        fgets(line,1024,f);
        char * tok;
        tok = strtok (line," ");
        char*s=(char*)malloc(20*sizeof(char));
        strcpy(s,tok);
        ///INTRODUCING THE NAME OF THE COUNTRY IN THE LIST
        addLastHeader(s);
        ///INTRODUCING THE WAVES
        tok = strtok(NULL," ");
        while (tok != NULL)
        {
            int data;
            sscanf(tok,"%d",&data);
            addLifePoints(&headerTail,data);
            addLastNode(&(headerTail->head),&(headerTail->tail),data);
            tok = strtok (NULL, " ");
        }
        memset(line,0,1024);
    }

    /*************** PUTTING JIM-KONG nu AT THE END OF THE LIST OF SENTINELS **************************************/
    addLastSentinel(1);


    /****************** COMPUTING THE STRONGEST AND WEAKEST COUNTRIES ************* WORKS!!!!! ********************/
    char *strongest=(char*)malloc(20*sizeof(char));
    char *weakest=(char*)malloc(20*sizeof(char));
    strongest=strongestCountry();
    weakest=weakestCountry();

    /****************** COMPUTE IF ANY COUNTRY COULD HAVE DEFEATED THE TYRANT BY ITSELF. IF NOT, HOW MUCH AT MOST**/
    int nrOfKilledSentinels, pointsLeft;
    int ok=mostSentinelsKilled(strongest,&nrOfKilledSentinels,&pointsLeft);

    /****************** SIMULATION OF THE WAR. OUTPUT: WAS THE TYRANT KILLED? IF SO, BY WHOM?*********************/

    char *lastCountry=(char*)malloc(20*sizeof(char));
    if (simulatingTheWar(&lastCountry)==0)
    {
        fprintf(g,"The tyrant was not killed\nTherefore, no country had the hitting blow!");
    }
    else
    {
        fprintf(g,"The tyrant was killed!\n");
        fprintf(g,"The last hit was done by: %s\n",lastCountry);
    }
    /****************** PRINTING THE REMAINING RESULTS (COMPUTED EARLIER AS IN THE WAR SIMULATION THE DATA WAS DESTROYED)*/
    fprintf(g,"The strongest country was: %s\nThe weakest country was: %s\n",strongest,weakest);
    if (ok==1)
    {
        fprintf(g,"%s could have defeated all the sentinels by itself\n",strongest);
    }
    else
    {
        fprintf(g,"No country could have defeated all the sentinels.\n%s could have brought down the first %d sentinels and would have had chipped off %d life points from sentinel %d.\n",strongest,nrOfKilledSentinels,pointsLeft,nrOfKilledSentinels+1);
    }
    return 0;
}


