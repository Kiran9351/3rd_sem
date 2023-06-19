#include<stdio.h>
#include<stdlib.h>

void next_seq(int *arr, int start,int end)
{
	int i = 0;
	
	if(start == end)
	{
		return;
	}

	for(i = end; i > start; i--)
	{
		if(arr[i - 1] < arr[i])
		{
			break;
		}
	}
	int j = end;
	while(i < j)
	{
		if(
	}

	
}

int main()
{
	int *arr = NULL;
	int iSize = 0, i = 0, iValue = 0;

	printf("\nEnter the size of the array: ");
	scanf("%d",&iSize);
	
	for(i = 0; i < iSize; i++)
	{
		printf("\nEnter value at the index %d : ",i);
		scanf("%d",&iValue);
		arr[i] = iValue;
	}
	
	int start = 0;
	int end = iSize - 1;
	next_seq(arr,start,end);

	return 0;
}
