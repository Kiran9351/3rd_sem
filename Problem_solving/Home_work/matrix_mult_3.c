#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define row 1024
#define col 1024

int main()
{ 
	int i = 0, j = 0, k = 0, m = 0, M = 0, ii = 0, jj = 0, kk = 0;

	int *arr = NULL, *brr = NULL, *crr = NULL;

	arr = (int*)malloc(row * col * sizeof(int));
	brr = (int*)malloc(row * col * sizeof(int));
	crr = (int*)malloc(row * col * sizeof(int));

	for(i = 0; i < row; i++)
	{
		for(j = 0; j < col; j++)
		{
			*(arr + i * col + j) = (int)rand() % 100;
			*(brr + i * col + j) = (int)rand() % 100;
		}
	}
/*
	for(i = 0; i < row; i++)
	{
		for(k = 0; k < col; k++)
		{
			for(j = 0; j < row; j++)
			{
				*(crr + i * col + j)  += (*(arr + i * col + k)) * (* (brr + j * col + k));
			}
		}
	}
*/	
	M = row / 64;
/*
	for(m = 0; m < M; m++)
	{
		for(i = m * 32; i < (m+1) * 32; i++)
	        {
	                for(k = m * 32; k < (m + 1) * 32; k++)
	                {
	                        for(j = m*32; j < (m + 1) * 32; j++)
	                        {
	                                *(crr + i * col + j)  += (*(arr + i * col + k)) * (* (brr + k * col + j));
	                        }
	                }
	        }
	}
*/

	for(ii = 0; ii < row; ii += 32)
	{
		for(i = 0; i < 32; i++)
		{
			for(kk = 0; kk < row; kk +=32)
			{		
				for(k = 0; k < 32; k++)
				{
					for(jj = 0; k < row; kk += 32)
					{
						for(j = 0; j < 32; j++)
						{
							*(crr + (ii + i) * col + (jj + j)) += (*(arr + (ii + i) * col + (kk + k)) * (*(brr + (kk + k) * col +(jj + j))));
						}
					}	
				}
			}
		}
	}

	return 0;
}
