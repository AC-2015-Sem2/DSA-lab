#include "io.h"
#include "files.h"
#include<stdio.h>
int main()
{
    int i;
     int N =_5,coliziuni=0,max_collisions=0;
    char ** content = readFromFile(N);
    initHashTable(N);

    for(i=0;i<N;i++)
        {
            coliziuni=insertElement(*(content+i));
            if(max_collisions<coliziuni)
                max_collisions=coliziuni;
        }
    printf("Numarul maxim de coliziuni este %d",max_collisions);
   // printContentToConsole(content,N);

    return 0;
}
