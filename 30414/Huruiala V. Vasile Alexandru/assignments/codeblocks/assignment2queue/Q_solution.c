#include "Q_definition.h"
#include <stdio.h>

void solve(Sentinel* S, FILE* I, FILE* O)
{
    if(S == NULL)
    {
        fprintf(stderr, "Sent NULL pointer detected.\n");
        return;
    }
    (*S->readFile)(S, I);

    int TimeSoFar = 0;
    int TotalCashed = 0;
    while(S->Thead != NULL)
    {
        while((S->Thead != NULL)&&(S->Qhead != NULL)&&(TimeSoFar + *(int*)S->Qhead->data3 > *(int*)S->Thead->data))
        //This part checks if the next client would take longer than the next time limit allows
        //if so it prints for all time limits that he would break
        {
            fprintf(O, "After %d seconds: %d\n", *(int*)S->Thead->data, TotalCashed);
            (*S->RemoveFirstTime)(S);
        }
        //Now the time limit has advanced to one that the next transaction will not overpass
        //and in case it is equal the transaction would have been completed
        if(S->Qhead != NULL)
        //The transaction
        {
            TimeSoFar += *(int*)S->Qhead->data3;
            TotalCashed += *(int*)S->Qhead->data2;
            (*S->DEQ)(S);
        }
        //This prints and advances for all time limits that the current transaction overpassed
        //or it prints for the rest of the time list if the queue is empty
        while((S->Thead != NULL)&&((TimeSoFar >= *(int*)S->Thead->data)||(S->Qhead == NULL)))
        {
            fprintf(O, "After %d seconds: %d\n", *(int*)S->Thead->data, TotalCashed);
            (*S->RemoveFirstTime)(S);
        }
    }
}
