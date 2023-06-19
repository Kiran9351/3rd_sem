#include<stdio.h>

void *arr[200];

void print_arr(int *ptr)
{
	int start = 0, end = 0, i = 0;
	
	void *new_ptr = (void*)ptr;	

	printf("\nptr = %d",ptr[0]);

	start = *(int*)(new_ptr - 8);
	end = *(int*)(new_ptr - 4);
	/*
	for(i = 0; i < 5; i++)
	{
		printf("\n%d ",ptr[i]);
	}
*/
	printf("\nStart = %d",start);
	printf("\nEnd = %d\n",end);
}

int *construct_array(void *arr)
{
	int i = 0, iSize = 0, iValue = 0;

	printf("\nEnter the size of array : ");
	scanf("%d",&iSize);
	
	*(int*)(arr + 0) = 2;
	*(int*)(arr + 1) = 6;

	for(i = 2; i < iSize+2; i++)
	{
		printf("\nEnter element at index %d = ",i);
		scanf("%d",&iValue);
		*(int*)(arr + i) = iValue;
	}

	return (arr + 2); 
}

int main()
{	
	int *ptr = construct_array(arr);
	
	print_arr(ptr);
	
	return 0;

