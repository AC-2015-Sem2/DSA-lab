#include "functions.h"
#include "battleFunctions.h"

int main()
{
    int sentinelNumber, countryNumber;
    waveList *sentinels = createList();

    country* first = NULL;
    country* last = NULL;

    //Reading all the elements
    readElements(&sentinelNumber, &countryNumber, sentinels, &first, &last);

    //Calculating the total defense of the sentinels
    int totalDefense = calculateDefense(sentinels);

    int maxDamage = 0;
    int totalDamage = 0;
    char *bestName;
    char *worstName;
    country* newCountry = first;

    //Calculating the best and worst countries as well as the total damage
    computeBest(&newCountry, &bestName, &worstName, &totalDamage, &maxDamage);

    FILE* g = fopen("output.dat", "w");

    //Checking for victory
    if(totalDamage > totalDefense)
        fprintf(g, "The tyrant was killed!\n");
    else
        fprintf(g, "The tyrant was not killed!\n");

    //Computing who did the last hit, if any
    newCountry = first;
    int currentHealth = totalDefense;
    if(totalDamage > totalDefense)
        computeLast(currentHealth, &newCountry, first, g);

    //Printing the strongest and weakest countries
    fprintf(g,"The strongest country was: %s\n", bestName);
    fprintf(g,"The weakest country was: %s\n", worstName);

    //Checking if there are countries which can kill all sentries, and if not we will calculate how much the best country could do
    int turrets = 0, chipped = 0;
    newCountry = first;
    int nr=0;
    computeSingleCountry(&newCountry, sentinels, totalDefense, maxDamage, &turrets, &chipped, &nr, g);

    if(nr==0)
        fprintf(g,"No country ");
    fprintf(g, "could have defeated all the sentinels\n");
    if(nr==0)
        fprintf(g, "%s could have brought down the first %d sentinels and would have chipped off %d life points from sentinel %d\n", bestName, turrets, chipped, turrets+1);
    fclose(g);
    return 0;
}
