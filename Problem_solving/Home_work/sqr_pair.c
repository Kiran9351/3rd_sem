#include<stdio.h>

void sqr_pairs(int k)
{
	int i = 0, j = 0;

	while(i < k/2)
	{
		j = 0;
		while(j < k)
		{
			if(k == (i*i) + (j*j))
			{
				printf("\n%d %d",i,j);
			}
			j++;
		}
		i++;
	}
	printf("\n");
}

int main()
{
	int k = 0;

	printf("\nEnter the value of k = ");
	scanf("%d",&k);

	sqr_pairs(k);

	return 0;
}
