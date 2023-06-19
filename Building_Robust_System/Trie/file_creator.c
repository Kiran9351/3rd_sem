#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>


#define million 1000000

int main()
{
	char *buffer = NULL;
	char new_line[2] = "\n";
	int fd = open("filenames.txt",O_CREAT|O_RDWR,00777);
	
	int i = 0, j = 0, ch = 0, len = 0;

	for(i = 0 ;i < million; i++)
	{
		buffer = NULL;
		len = rand() % 40;
		buffer = (char*)malloc((len + 5) * sizeof(char));
		
		for(j = 0; j < len; j++)
		{
			ch = rand() % 26;
			buffer[j] = (char)(ch + 97);
		}
	
		if(i % 2 == 0)
		{
			strcat(buffer,"txt");
		}	
		else
		{
			strcat(buffer,"pdf");
		}

		write(fd,buffer,strlen(buffer));
		write(fd,new_line,strlen(new_line));
	}

	
	return 0;
}
