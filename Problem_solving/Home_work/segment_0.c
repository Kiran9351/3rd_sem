#include<stdio.h>
#include<stdlib.h>

void segment(int arr[], int iSize)
{
	int i = 0, iMax = 0, iCnt = 0, index = 0;

	while( i < iSize)
	{
		if(arr[i] == 0)
		{
			iCnt = iCnt + 1;
		}
		else
		{
			iCnt = 0;
		}	
	
		if(iMax < iCnt)
		{
			iMax = iCnt;
			index = i;
		}


		i++;
	}

	printf("\nMax number of zeros in segment : %d", iMax);
	printf("\nStarting index of segment : %d",(index - iMax + 1));
	printf("\nEnding index of segment : %d\n",index);
}

int main()
{
	int *arr = NULL;
	int iSize = 0, i = 0, iValue = 0;

	printf("\nEnter the size of the array: ");
	scanf("%d", &iSize);

	arr = (int*)malloc(iSize * sizeof(int));

	for(i = 0; i < iSize; i++)
	{
		printf("\nEnter the value at the index %d : ", i);
		scanf("%d", &iValue);
		arr[i] = iValue;
	}

	segment(arr,iSize);
	
	free(arr);

	return 0;
}
