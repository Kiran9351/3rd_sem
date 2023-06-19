
#include<stdio.h>
#include<stdlib.h>

int pairs(int *A, int *B, int m, int n)
{
	int p = 0, q = 0, cnt = 0, i = 0, j = 0;

	while(p < m && q < n)
	{
		i = p;
		j = q;
		
		while((A[i] <= B[j]) && (i < m) && (j < n))
		{
			if(A[i] == B[j])
			{
				cnt++;
				j++;
			}

			i++;
		}	

		while((B[j] <= A[i]) && (i < m) && (j < n))
		{
			if(B[j] == A[i])
			{
				cnt++;
				i++;
			}
			
			j++;
		}

		p = i;
		q = j;
	}

	return cnt;
}

int main()
{
	int *A = NULL, *B = NULL;

	int m = 0, n = 0, i = 0, cnt = 0;
	printf("Enter size of A : ");
	scanf("%d",&m);
	printf("Enter size of B : ");
	scanf("%d",&n);

	A = (int*)malloc(m * sizeof(int));
	B = (int*)malloc(n * sizeof(int));
	
	printf("Enter %d elements of A\n",m);
	for(i = 0; i < m; ++i)
	{
		scanf("%d",(A + i));
	}

	printf("Enter %d elements of B\n",n);
	for(i = 0; i < n; ++i)
	{
		scanf("%d",(B+i));
	}

	cnt = pairs(A,B,m,n);
	printf("cnt = %d\n",cnt);

	return 0;
}
