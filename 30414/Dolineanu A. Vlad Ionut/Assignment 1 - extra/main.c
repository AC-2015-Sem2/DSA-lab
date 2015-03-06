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

    country* auxCountry = first;

    //Calculating the best and worst countries as well as the total damage
    computeBest(&auxCountry, &bestName, &worstName, &totalDamage, &maxDamage);

    FILE* g = fopen("output.dat", "w");

    //Checking for victory
    if(totalDamage > totalDefense)
        fprintf(g, "The tyrant was killed!\n");
    else
        fprintf(g, "The tyrant was not killed!\n");

    //Computing who did the last hit, if any
    auxCountry = first;
    int currentHealth = totalDefense;
    if(totalDamage > totalDefense)
        computeLast(currentHealth, &auxCountry, first, g);

    //Printing the strongest and weakest countries
    fprintf(g,"The strongest country was: %s\n", bestName);
    fprintf(g,"The weakest country was: %s\n", worstName);

    //Checking if there are countries which can kill all sentries, and if not we will calculate how much the best country could do
    auxCountry = first;
    computeSingleCountry(&auxCountry, sentinels, totalDefense, maxDamage, g);

    fclose(g);
    return 0;
}
