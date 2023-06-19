#include<stdio.h>
#include<stdlib.h>

void swap(int arr[], int j, int l)
{
	int temp = 0;
	
	temp = arr[j];
	arr[j] = arr[l];
	arr[l] = temp;
}

void sort(int arr[], int iSize)
{
	int i = 0, j = 0, k = iSize - 1, temp = 0;

	while(j <= k)
	{
		while(arr[i] == 0)
		{
			i = i + 1;
			
			if(j == 0)
			{
				j = i;
			}
		}

		while(arr[j] == 1)
		{
			j = j + 1;
		}

		while(arr[k] == 2)
		{
			k = k - 1;
		}
		
		if(k < j)
		{
			break;
		}

		if(arr[j] == 0)
		{
			swap(arr,j,i);
		}
		else if(arr[j] == 2)
		{
			swap(arr,j,k);
		}

	}
}

void display_array(int arr[], int iSize)
{
	int i = 0;
	
	printf("\nPrinting array: ");
	for(i = 0; i < iSize; i++)
	{
		printf("%d ",arr[i]);
	}
}

int main()
{	
	int *arr = NULL;
	int iSize = 0, iValue = 0;

	printf("\nEnter the size of array: ");
	scanf("%d",&iSize);
	
	arr = (int*)malloc(iSize * sizeof(int));
	
	for(int i = 0 ; i < iSize; i++)
	{
		printf("\nEnter the value at index %d: ",i);
		scanf("%d",&iValue);

		arr[i] = iValue;
	}


	sort(arr,iSize);
	
	display_array(arr,iSize);
	
	return 0;
}
