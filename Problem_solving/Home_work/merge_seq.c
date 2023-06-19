#include<stdio.h>
#include<stdlib.h>

int *merge_seq(int arr[], int brr[], int iSize)
{
	int i = 0, j = 0, m = 0;

	int * orr = NULL;

	orr = (int*)malloc((2 * iSize) * sizeof(int)); 

	while(m < (2 * iSize))
	{
		while((i < iSize) || (j < iSize))
		{
			if(m == (2 * i))
			{
				orr[m] = arr[i];
				i = i + 1;
			}
			else 
			{
				orr[m] = brr[j];
				j = j + 1;
			}
			
			m = m + 1;
		}
	}

	return orr;
}

int main()
{
	int iSize = 0, i = 0, iValue = 0;
	int *arr = NULL, *brr = NULL, *orr = NULL;

	printf("\nEnter the size of both sequence : ");
	scanf("%d",&iSize);

	arr = (int*)malloc(iSize * sizeof(int));
	brr = (int*)malloc(iSize * sizeof(int));
	
	printf("\nEnter the elements of first array");
	for(i = 0 ; i < iSize; i++)
	{
		printf("\nEnter the element at the index %d = ",i);      
		scanf("%d",&iValue);
		arr[i] = iValue;	
	}

	printf("\nEnter the elemetns of second array");
	for(i = 0; i < iSize; i++)
	{
		printf("\nEnter the element at the index %d = ",i);
		scanf("%d",&iValue);
		brr[i] = iValue;
	}

	orr = merge_seq(arr,brr,iSize);

	printf("\nPrinting the output array: ");
	for(i = 0; i < (2 * iSize); i++)
	{
		printf("%d ",orr[i]);
	}

	return 0;
}
