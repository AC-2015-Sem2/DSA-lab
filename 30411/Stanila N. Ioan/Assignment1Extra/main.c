#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "list.h"
#include "lolists.h"

int main()
{
    int N, M;
    int i, x;
    LIST* sent = NULL;
    LoLISTS* coun = NULL;
    int maxPoints = 0, maxCtr = 0;
    int minPoints = INT_MAX, minCtr = 0;
    int tyrantKilled = 1;
    int sentinelPoints = 0;

    //fill the lists
    FILE* f = fopen("input.dat", "r");
    if (f == NULL) {
        perror("input.dat");
        exit(1);
    }
    FILE* g = fopen("output.dat", "w");
    if (g == NULL) {
        perror("output.dat");
        exit(1);
    }

    fscanf(f, "%d", &N);
    for (i = 0; i < N; i++) {
        fscanf(f, "%d", &x);
        add_last(&sent, x);
        printf("%d ", x);
        tyrantKilled += x;
    }
    printf("\n");

    sentinelPoints = tyrantKilled;

    fscanf(f, "%d", &M);
    char* line = (char*)malloc(100*sizeof(char));

    add_list(&coun);
    LoLISTS* tcoun = coun;
    for (i = 0; i < M; i++) {

        fscanf(f, " %[^\n]s ", line);
        char* t = strtok(line, " ");
        add_name(&tcoun, t, strlen(t));
        t = strtok(NULL, " ");

        int tPoints = 0;
        while (t != NULL) {
            sscanf(t, "%d", &x);

            tPoints += x;

            add_wave_last(&tcoun, x);
            t = strtok(NULL, " ");
        }

        if (tPoints > maxPoints) {
            maxPoints = tPoints;
            maxCtr = i;
        }
        if (tPoints < minPoints) {
            minPoints = tPoints;
            minCtr = i;
        }

        //just testing
        printf("%s ", tcoun->name);
        print_all(tcoun->wave, stdin);
        //end just testing

        add_list(&(tcoun->next));
        tcoun = tcoun->next;
    }
    free(line);
    //end fill the lists

    //i have "sent" and "coun"
    //also "maxPoints", "maxCtr", "minPoints", "minCtr"
    // det everything
    tcoun = coun;
    for (i = 0; i < M; i++) {
        LIST* twave = tcoun->wave;
        int stop = 0;
        while (twave != NULL && !stop) {
            if (tyrantKilled > 0 && tyrantKilled - twave->val <= 0) {
                fprintf(g, "The tyrant was killed!\n");
                fprintf(g, "%s had the last hit.\n", tcoun->name);
                stop = 1;
            }
            tyrantKilled -= twave->val;
            twave = twave->next;
        }
        tcoun = tcoun->next;
    }

    if (tyrantKilled > 0) {
        fprintf(g, "The tyrant lives...\n");
    }

    tcoun = coun;
    for (i = 0; i < M; i++) {
        if (minCtr == i) {
            fprintf(g, "The weakest country was %s\n", tcoun->name);
        }
        if (maxCtr == i) {
            fprintf(g, "The strongest country was %s\n", tcoun->name);
            if (maxPoints >= sentinelPoints) {
                printf("%s could have defeated all the sentinels.\n", tcoun->name);
            } else {
                fprintf(g, "No country could have defeated all the sentinels.\n");
                LIST* twave = sent;
                int a = maxPoints;
                int j = 0, remPoints = 0;
                while (a) {
                    if (a - twave->val >= 0) {
                        j++;
                        a -= twave->val;
                    } else {
                        remPoints = a;
                        a = 0;
                    }
                    twave = twave->next;
                }
                fprintf(g, "%s could have defeated %d sentinels and done %d points damage to sentinel %d.\n", tcoun->name, j, remPoints, j+1);
            }
        }
        tcoun = tcoun->next;
    }
    //end det everything

    //destroy the lists
    doom_the_list(&sent);
    doom_lolists(&coun);
    //end destroy the lists

    //close the files
    fclose(f);
    fclose(g);
    //end close the files

    return 0;
}
