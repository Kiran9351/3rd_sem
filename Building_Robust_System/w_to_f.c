#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>  
#include<unistd.h>

int main()
{

	int fd = open("test.txt", O_CREAT | O_RDWR);

	long a  = 0X12345678a1a2a3a4;
	
	int length = sizeof(long);

	int size1 = write(fd,&a,length);
	
	unsigned char str[255];

	close(fd);

	fd = open("test.txt",O_RDONLY);

	int size2 = read(fd,str,length);

	for(int i = 0; i < length; i++)
	{
		printf("%x ",str[i]);
	}

	printf("\n");
		
	return 0;
}
