#include<stdio.h>
#include<stdbool.h>

int SIZE = 1000;
void *arr[SIZE];
int fflag = 0;
int mflag = 0;
int header = 99;

/*
bool check_free_space(int iSize)
{
	if(*(int*)(arr+0) >= iSize)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void manage_free_space(int iSize)
{
	if(fflag == 0)
	{
		*(int*)(arr+0) = SIZE - 1 - header; 
	}
	else
	{
		*(int*)(arr+0) = *(int*)(arr+0) - iSize;
	}
}
void manage_header_global_array(void *arr,void *start, int iSize)
{

}*/

void *my_malloc(void *arr,int iSize)
{
	bool iRet;

	iRet = check_free_space(iSize)
	if(bRet == false)
	{
		printf("\nThere is not enough space");
		return NULL;
	}

	if(mflag == 0)
	{
		*(int*)(arr + 0) = 1;
		*(int*)(arr + 1) = header + 1;
	       	*(int*)(arr + 2) = (header + 1) + (4 * iSize);
			
		return (arr + (*(int*)(arr + 1)))

	}
	else
	{
		int i = *(int*)(arr + 0);

		for(
	}


}

void construct_array()
{
	int iSize = 0;
	void *iRet = 0;

	printf("\nEnter the size of the array: ");
	scanf("%d",&iSize);

	iRet = my_malloc(arr,iSize);

	
}

int main()
{
	free_space(0)
	construct_array();

	return 0;
}
