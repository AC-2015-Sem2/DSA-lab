#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "List.h"
#include "Country.h"

int main() {

    FILE *in = fopen("input.dat", "r");

    Country* nk = (Country*) malloc(sizeof(Country));
    initCountry(nk, NULL);

    int nkSize;
    fscanf(in, "%d", &nkSize);

    int i, unitStrength;
    for (i = 0; i < nkSize; i++) {
        fscanf(in, "%d ", &unitStrength);
        addUnit(nk, unitStrength);
    }

    int countryNo;
    fscanf(in, "%d\n", &countryNo);
    Country* allies = (Country*) malloc(countryNo * sizeof(Country));

    char line[200];
    char *tok, *newName;

    int maxArmySize = -1, minArmySize = 2147e6;
    Country *strongestCountry = NULL, *weakestCountry = NULL;
    Country* canWinAlone = NULL;

    for (i = 0; i < countryNo; i++) {
        fgets(line, 200, in);

        tok = strtok(line, " ");

        // country name + initialization

        newName = (char*) malloc (strlen(tok) * sizeof(char));
        strcpy(newName, tok);
        initCountry(allies+i, newName);

        // unit assignments
        tok = strtok(NULL, " \n");

        while (tok != NULL) {
            addUnit(allies+i, atoi(tok));
            tok = strtok(NULL, " \n");
        }

        if ((allies+i)->armySize > maxArmySize) {
            maxArmySize =  (allies+i)->armySize;
            strongestCountry = allies+i;
        }

        if ((allies+i)->armySize < minArmySize) {
            minArmySize = (allies+i) -> armySize;
            weakestCountry = allies+i;
        }

        // strictly considering the sentinels
        // without Kim's 1 HP
        if ((allies+i)->armySize >= nk->armySize) {
            canWinAlone = allies+i;
        }
        //printUnits(allies+i);

        // simulate one on one battle
    }
    if (canWinAlone == NULL) {
        oneOnOne(strongestCountry, nk);
    }

    //printUnits(allies);
    // attack simulation
    int noMoreArmies = 0;
    char result = '0';

    while (!noMoreArmies && result != 'w') {
        noMoreArmies = 1;

        // suppose there are no more armies left
        for (i = 0; i < countryNo; i++) {

            if ((allies + i)->army->first != NULL) {
                noMoreArmies = 0;

                // only Kim remains
                // army i deals the winning blow just to kim
                // no sentinels were left
                if (result == 'K') {
                    result = 'w';
                    break;
                }

                result = fightBattle(allies + i, nk);

                // army i dealt the winning blow to the sentinel and kim
                if (result == 'w') {
                    break;
                }
            }
        }
    }

    FILE *out = fopen("output.dat", "w");

    if (noMoreArmies) {
        fprintf(out, "The allies have lost!");
    } else {
        fprintf(out, "The tyrant was killed!\n");
        fprintf(out, "The last hit was done by: %s.\n", (allies+i)->name);
        fprintf(out, "The strongest country was: %s.\n", strongestCountry->name);
        fprintf(out, "The weakest country was: %s.\n", weakestCountry->name);
        if(canWinAlone != NULL) {
            // just the sentinels, not necessarily including Kim
            fprintf(out, "%s could have defeated all the sentinels.\n", canWinAlone->name);
        } else {
            fprintf(out, "No country could have defeated all the sentinels.\n");
            fprintf(out, "%s could have brought down the first %d sentinels ",
                   strongestCountry->name,
                   strongestCountry->lastDefeatedSentinel);
            fprintf(out, "and would have chipped off %d points from sentinel %d.\n",
                   strongestCountry->lastDmg,
                   strongestCountry->lastDefeatedSentinel + 1);
        }

    }

    //printf("%s\n", strongestCountry->name);
    //printf("%s\n", weakestCountry->name);


    fclose(in);
    return 0;
}
