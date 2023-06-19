#include<stdio.h>
#include<stdio.h>

int main()
{
	void *ptr[40];
	
	int i = 0, iSize = 0, j = 0;

//	For static array i.e. or array of size 5.
	for(i = 0; i < 5; i++)
        {
                printf("\nEnter the value at the index %d = ",i);
                scanf("%d",(int*)(ptr+i));
        }
	
	int **arr = &(ptr + i);

	printf("\nptr + i = %p,arr = %p",(ptr + i),arr);

	printf("\n%d\n",**(arr - 3));


/*
        printf("\nPrinting array: ");
        for(i = 0; i < 5; i++)
        {
                printf("%d ",*(int*)(ptr+i));
        }

	//For user input array.
	printf("\nEnter the size of an array: ");
	scanf(" %d",&iSize);

	for(j = i; j < iSize + i; j++)
	{	
		printf("\nEnter the value at the index %d = ",j);
		scanf("%d",(int*)(ptr+j));
	}
	j = j - 1;

	int *arr = (int*)(ptr - j);

	printf("\nptr - j = %p,arr = %p",(ptr - j),arr);

	printf("\nmid = %d\n",**(arr)); 

	printf("\nPrinting array: ");
	for(j = i; j < iSize + i; j++)
	{
		printf("%d ",*(int*)(ptr+j));
	}*/

	printf("\n");

	return 0;
}
