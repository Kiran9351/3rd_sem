#include<stdio.h>

void division(int a, int b)
{
	int quo = 0, rem = a;

	while(rem >= b)
	{
		rem = rem - b;
		quo = quo + 1;
	}

	printf("\nQuotient is = %d",quo);
	printf("\nReminder is = %d\n",rem);
}

int main()
{
	int a = 0, b = 0;

	printf("\nEnter the dividend = ");
	scanf("%d",&a);

	printf("\nEnter the Divisor = ");
	scanf("%d",&b);

	division(a,b);

	return 0;
}
