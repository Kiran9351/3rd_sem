#include<stdio.h>
#include<stdlib.h>

int polynomial(int *arr,int x, int iLen)
{
	int t = 1 , i = 0;
	int p = arr[0];

	for(i = 1; i < iLen; i++)
	{
		t = t * x;
		p = p + (t * arr[i]);
	}

	return p;
}

int main()
{
	int *arr = NULL;
	int x = 0, iValue = 0, i = 0, iNo = 0, iRet = 0;
	
	printf("Enter number number of coefficients in polynomial : ");
	scanf("%d",&iValue);
	
	arr = (int*)malloc(sizeof(int) * iValue);
	
	for(i = 0; i < iValue; i++)
	{
		printf("Enter the value at indes %d : ",i);
		scanf("%d",&iNo);
		arr[i] = iNo;
	}

	printf("Enter the value of x : ");
	scanf("%d",&x);

	iRet = polynomial(arr,x,iValue);
	printf("Value of polynomial for x is : %d\n",iRet);
				

	return 0;
}
