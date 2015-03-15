#include <stdlib.h>
#include <stdio.h>
int numberofcustomers(FILE *f)
{
    char s[BUFSIZ];
    int nr=0;
    fseek(f,0L,SEEK_SET);
    fgets(s,sizeof(s),f);
    while(fgets(s,sizeof(s),f)!=NULL)
    {
        nr++;
    }
    return nr;
}
