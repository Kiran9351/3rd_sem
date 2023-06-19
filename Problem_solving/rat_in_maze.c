#include<stdio.h>
#include<stdlib.h>

int search_path(int arr[][], int m, int n, int i, int j, int p, int q)
{
	if(i == p, j == q)
	{
		return 1;
	}
	
	if(i > m || i < 0 || j > n || j < 0)
	{
		return 0;
	}	

	if(arr[i][j] == 1 || arr[i][j] == -1)
	{
		return 0
	}

	arr[i][j] = -1;

	return (search_path(arr,m,n,i+1,j,p,q) || (search_path(arr,m,n,i-1,j,p,q) || (search_path(arr,m,n,i,j+1,p,q) || search_path(arr,m,n,i,j-1,p,q));
	
}

int main()
{
	return 0;
}
