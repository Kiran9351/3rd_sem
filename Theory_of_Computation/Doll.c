#include<stdio.h>
#include<stdlib.h>

void doll(FILE *fptr)
{
	char ch = '\0';

	while((ch = fgetc(fptr) != EOF))
	{
		if((ch >= 'A') &&(ch <= 'Z'))
		{
			ch = ch + 32;
		}
		else if((ch >= 'a') && (ch <= 'z'))
		{
			ch = ch - 32;
		}	

		sleep(500);

		if(ch == EOF)
		{
			fseek(fptr, 0, SEEK_SET);
		}
	}
}

int main(int argc, char **argv)
{
	FILE *fptr = NULL;

	fptr = fopen(argv[1],"rw");

	if(fptr == NULL)
	{
		printf("\nFile unable to open");
		exit(1);
	}

	doll(fptr);

	return 0;
}
