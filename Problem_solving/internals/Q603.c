//Q603

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool kgon(int *D, int n, int sum, int k,int i)
{
	if(n == 0 || n < k)
	{
		return false;
	}

	sum = sum/k;

	int p = 0, j = i, s = 0, temp = 0;

	while(i < n)
	{
		if(s < sum)
		{
			s = s + D[j];	
			j++;
		}
		else if( s == sum)
		{
			break;
		}
		else
		{
			s = 0;
			i++;
			j = i;
		}
	}

	if(i != n)
	{	
		s = 0;
		while((j % n) == i)
		{
			s = s + D[j%n];
			if(s > sum)
			{
				i++;
				return kgon(D,n,sum,k,i);
			}
			else if(s == sum)
			{
				s = 0;
			}
			j++;
		}
	}

	if(j == i)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	int n = 0, *D = NULL, sum = 0, k = 0, i = 0;
	bool ret;

	printf("Enter the number of arcs: ");
	scanf("%d",&n);
	
	printf("Enter k : ");
	scanf("%d",&k);

	D = (int*)malloc(n * sizeof(int));

	printf("Enter arc lengths:\n");
	for(i = 0; i < n; ++i)
	{
		scanf("%d",(D+i));
		sum = sum + D[i];
	}
	
	printf("%d\n",sum);
	
	i = 0;
	ret = kgon(D,n,sum,k,i);
	if(ret == true)
	{
		printf("True\n");
	}
	else
	{
		printf("False\n");
	}
	
	return 0;
}
