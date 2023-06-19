#include<stdio.h>

#define SIZE 1000;
#define header 100;
void *ptr[SIZE];
int free_space = SIZE-header;

void head(void *ptr[], int header)
{
	int i = 0; 

	for(i = 0; i < header; i++)
	{
		*(int*)(ptr+i) = -1;
	}
}

int search_for_free_memory_index(void *ptr[], int header)
{
	if((*(int*)(ptr+0)) == -1)
	{
		return -1;
	}
}

void * my_malloc(int iSize)
{
	int iRet = 0;

	if(free_space < 0)
	{
		printf("\nThere is no memory");
		return NULL;
	}	

	iRet = search_for_free_memory_index(ptr,header);

}

int main()
{
	int i = 0, iSize = 0, cSize = 0;

	//For keeping integers
	/*
	printf("\nEnter the size of integer array: ");
	scanf("%d",&iSize);

	for(i = 0; i < iSize; i++)
	{
		printf("\nEnter the integer value at the index %d = ",i);
		scanf("%d",(int*)(ptr+i));
	}

	//For keeping characters
	
	printf("\nEnter the size of characters array: ");
	scanf("%d",&cSize);

	for(int j = i; (j - i) < cSize; j++)
	{
		printf("\nEnter the character at the index %d = ",(j-i));
		scanf(" %c",(char*)(ptr+j));
	}

	//Printing the arrays.
	
	printf("\nPrinting integer array: ");
	for(i = 0; i < iSize; i++)
	{
		printf("%d ",*(int*)(ptr+i));
	}

	printf("\nPrinting character array: ");
	for(int j = i; (j - i) < cSize; j++)
	{
		printf("\%c ",*(char*)(ptr+j));
	}

	*/

	head(ptr,header);

	return 0;
}
