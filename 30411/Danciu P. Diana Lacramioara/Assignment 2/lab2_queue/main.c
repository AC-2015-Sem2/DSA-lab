#include "file.h"

int main(void)
{
    FILE *pf;

    char name[20];
    int TIME[15];
    int time, money;
    int sum_time, sum_money;
    int t; // number of elements of array TIME
    int i,readt;

    pf = fopen("store.txt", "r");
    if (pf == NULL)
    {
        perror("Cannot open file");
        return (-1);
    }
    sum_time = 0;
    sum_money = 0;
    t = 0;
    while (fscanf(pf, "%d", &readt) > 0)
    {
        TIME[t] = readt;
        t++;
    }
    while (fscanf(pf, "%s %d %d", name, &money, &time) > 0)
        {
            Enque(money, time, name);
        }
    i=0;
    while (i < t)
    {
        NodeT *elem;
        elem = head;
         sum_time = 0;
         sum_money = 0;
        while (elem != NULL)
        {
            if ((sum_time + elem->time) <= TIME[i])
            {
                sum_time = sum_time + elem->time;
                sum_money = sum_money + elem->money;
            }
            elem=elem->next;
        }
        printf("After %d seconds: %d and total amount of time %d\n", TIME[i], sum_money, sum_time);
        i++;
    }
    PrintList();
    fclose(pf);
    return(0);
}
