#include<stdio.h>

int mult(int x, int y)
{
	int iCnt = 0;

	while(iCnt <= y)
	{
		temp = 
	}
}

int square_root(int iValue)
{
	int x = 0, xx = 0, m = 0;

	while((x + 1) * (x + 1) <= iValue)
	{
		xx = 1;

		while((x + xx) * (x + xx) <= iValue)
		{
			m = xx;
			xx = xx + xx;
		}

		x = x + m;
	}

	return x;
}

int main()
{
	int iValue = 0, iRet = 0;

	printf("Enter number : ");
	scanf("%d",&iValue);

	iRet = square_root(iValue);
	printf("Square root of %d is : %d\n",iValue,iRet);

	return 0;
}
