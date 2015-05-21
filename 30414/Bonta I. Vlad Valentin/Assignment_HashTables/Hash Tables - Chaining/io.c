#include "io.h"

char* itoa(int i, char b[]){
	char const digit[] = "0123456789";
	char* p = b;
	if(i<0){
		*p++ = '-';
		i *= -1;
	}
	int shifter = i;
	do{ //Move to where representation ends
		++p;
		shifter = shifter/10;
	}while(shifter);
	*p = '\0';
	do{ //Move back, inserting digits as u go
		*--p = digit[i%10];
		i = i/10;
	}while(i);
	return b;
}

void writeToFile(int N)
{
	srand (time(NULL));
	FILE * f = getFileForInt(N);
	int i;
	for(i=0; i<N; i++)
	{
		fprintf(f,"%s\n",randString());
	}
	fclose(f);
}

char ** readFromFile(int N)
{
	char ** contents = (char**) malloc(sizeof(char*) * N);
	int i;

	for(i=0; i<N; i++)
	{
		*(contents + i) = (char*) malloc(sizeof(char) * (MAX_STRING_LENGTH +1) );
	}

	FILE * f = getFileForInt(N);

	for(i=0; i<N; i++)
	{
		fgets(*(contents+i), (MAX_STRING_LENGTH + 2),f);
	}

	return contents;
}

void printContentToConsole(char ** contents, int N)
{
	int i;
	for(i=0; i<N; i++)
	{
		puts(*(contents+i));
	}
}

char * randString()
{
	const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()_+{}:<>?|\[];'./,";
	char * str = (char*) malloc(sizeof(char) * (MAX_STRING_LENGTH));
	int i;

	for (i = 0; i < MAX_STRING_LENGTH-1; i++)
	{
		int key = rand() % (int) (sizeof(charset) - 1);
		str[i] = charset[key];
	}
	str[MAX_STRING_LENGTH - 1] = '\0';

	return str;
}

FILE * getFileForInt(int N)
{
	char * filename = (char*) malloc(sizeof(char)*8);
	return fopen(strcat(itoa(N,filename),".data"), "rw");
}
