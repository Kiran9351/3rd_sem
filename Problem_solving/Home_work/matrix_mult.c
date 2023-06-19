#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define row 1000
#define col 1000

int arr[row][col], brr[row][col], crr[row][col];


int main()
{ 
	int i = 0, j = 0, k = 0;

	for(i = 0; i < row; i++)
	{
		for(j = 0; j < col; j++)
		{
			arr[i][j] = (int)rand() % 100;
			brr[i][j] = (int)rand() % 97;
		}
	}

	for(i = 0; i < row; i++)
	{
		for(j = 0; j < col; j++)
		{
			for(k = 0; k < row; k++)
			{
				crr[i][j] += (arr[k][i] * brr[j][k]);
			}
		}
	}

	return 0;
}
