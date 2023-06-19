#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>  
#include<string.h>
#include<unistd.h>

int main()
{

	int fd = open("test2.txt", O_CREAT | O_RDWR);

	long arr[10] = {0X12345678a1a2a3a4, 0X23456781a4a1a2a3,0X34567812a3a4a1a2,0X45678123a2a3a4a1,0X56781234a1a2a3a4,0X67812345a2a3a4a1,0X78123456a3a4a1a2,0X81234567a4a1a2a3,0X12345678a3a4a1a2,0X23456781a2a3a4a1};
/*
	for(int i = 0; i < 10; i++)
	{
		printf("\nEnter the element at the index %d : ",i);
		scanf(" %ld",(arr+i));
	}
	*/
	int length = sizeof(long);
	
	printf("\nPrinting array\n ");
	for(int i = 0; i < 10; i++)
	{
		printf("\n%lx",arr[i]);
	}	

	printf("\n");

	for(int i = 0; i < 10; i++)
	{
		int size1 = write(fd,(arr+i),length);
	}
	unsigned char str[10*length];

	close(fd);

	fd = open("test2.txt",O_RDONLY);

	int size2 = read(fd,str,length * 10);
	printf("\n");
	for(int i = 1 ; i <= 10*length; i++)
	{
		printf("%x ",str[i-1]);
		if(i % 8 == 0)
		{
			printf("\n");
		}
	}

	printf("\n");
		
	return 0;
}
