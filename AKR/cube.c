#include<stdio.h>

int main()
{
	int N = 5;
	int n = 0, c = 0, temp = 0, x = 0;

	while ( n != N)
	{
		x = x + n + n + 1;
		c = c + temp + temp + temp + n + n + n + 1;
		temp = x;
		n++;
	}	
	
	printf("%d\n",c);

	return 0;
}
