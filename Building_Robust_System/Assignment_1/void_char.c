#include<stdio.h>
#include<stdlib.h>

int main()
{
	void *ptr = NULL;

	char a = 'z';

	ptr = &a;

	printf("\n a = %c\n",*(char*)ptr);

	return 0;
}
