#include "hashTable.h"
#include<stdio.h>
#include<math.h>
void initHashTable(int N)
{
 int i;
 size=(int)((float)N*INITIAL_HT_SIZE_FACTOR);
 hashTable=(char**)malloc(sizeof(char *)*size);
 for(i=0;i<size;i++)//AICI AM COMENTAT
    hashTable[i]=NULL;
   // memset(hashTable,NULL,size);
    //! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/4 of N)
}

float getFillFactor()
{
    //! return the fill factor of the hash table
   // return (float)hash_number/(float)size;
    float fillFactor = 0;
    int i,nr=0;
    for(i=0;i<size;i++)
        if(hashTable[i]!=NULL)
        nr++;
    fillFactor=(float)nr/(float)size;//s-a umplut .x% din vector
    return fillFactor;
}

void resizeHashTable()
{

    //! reconstruct the hash table by (usually) doubling its size
    //! only call this when the current fill factor of your hash table > MAX_FILL_FACTOR

    //! careful, when resizing, the 'size' variable should be changed as well such that the 'hashFunction's distribution will work
    //! be double careful! all the elements which are already in the hash table have to  be RE-hashed! (explanation @ lab)
    char **aux=(char**)malloc(sizeof(char *)*size);

    int i;
    for(i=0;i<=size;i++)
        aux[i]=hashTable[i];
    size*=2;
    hashTable=(char**)malloc(sizeof(char *)*size);
    // memset(hashTable,NULL,size);
    for(i=0;i<=size;i++)
        hashTable[i]=NULL;
    for(i=0;i<size/2;i++)
        if(aux[i]!=NULL)
        insertElement(*(aux+i));
    free(aux);

}

int insertElement(char * element)
{

    int coliziuni=0;
    int cod;
    if(getFillFactor()>MAX_FILL_FACTOR)
        resizeHashTable();

    //! insert an element
    //! returns the number of collisions which occurred before the element was inserted

   cod=hashFunction(element,coliziuni);
    while(hashTable[cod++]!=NULL)
        coliziuni++;


     cod%=size;
    // I put this out of the while function
    hashTable[cod]=element;
    return coliziuni;
}

int h1(char* content)
{
    int i=0,sum=0;
    while((content[i])!='\n'&&(content[i])!='\0')
        sum=(sum+content[i++]);
    return sum%size;
}
int h2(char* content)
{
    int i=0,sum=0;
    while((content[i])!='\n'&&(content[i])!='\0')
        sum=(sum+content[i++]*(int)sin(h1("Pie")))%size;
    return sum%size;
}
int h3(char* content)
{
    int i=0,sum=0;
    while((content[i])!='\n'&&(content[i])!='\0')
        sum=(sum+content[i++]*h1("http://9gag.com/gag/a755dO2\n"))%size;
    return sum%size;
}
int hashFunction(char * content, int i)
{
   // printf("%c\n",(content));
    return h1(content);
    return h2(content);
    return h3(content);
  //return (content+1)+  hashFunction(( content+1),i+1);
   // strcpy(aux,*content);



}
