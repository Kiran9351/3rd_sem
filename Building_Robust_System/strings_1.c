#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

int main()
{
	int i = 0, len = 0;
	int fd = open("write_to_file.txt", O_CREAT|O_WRONLY,00700);
	
	char *str[4] = {"First String","Second String", "Third String", "Forth string"};

	 len = 4;

        write(fd,&len,sizeof(int));


	for(i = 0; i < 4; i++)
	{
		len = strlen(*(str+i));
		write(fd,&len,sizeof(int));
		write(fd,*(str+i),len);
	}

	close(fd);

	return 0;
}
