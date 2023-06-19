#include<stdio.h>

int exponent(int a, int x)
{
	int i = 0, m = 1 ;

	while(i < x)
	{
		m = m * a;
		i = i + 1;
	}	

	return m;
}

int main()
{
	int a = 0, x = 0, iRet = 0;

	printf("\nEnter the value of a = ");
	scanf("%d",&a);

	printf("\nEnter the value of x = ");
	scanf("%d",&x);

	iRet = exponent(a,x);
	printf("\na raised to x = %d\n",iRet);

	return 0;
}
