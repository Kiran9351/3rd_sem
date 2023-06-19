#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	int fd;

	fd = open("csv_file.csv",O_CREAT | O_WRONLY,00777);
	
	char str[] = "name,mob no,bdate,email";	

	int val = 0;
	val = write(fd, str, sizeof(str)-1);
	
	block_i	
}
