#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

int main()
{
	int i = 0, len = 0, ivalue = 0 ;

	int fd_1 = open("arr_to_file.txt",O_RDONLY);
	int fd_2 = open ("arr_to_file_2.txt",O_CREAT | O_WRONLY, 00700);



	read(fd,
	write(fd, &len, sizeof(len));
	for(i = 0; i < 4; i++)
	{
		len = strlen(*(str+i));
		printf("\n%d",len);
		write(fd,&len,sizeof(int));
		write(fd,*(str+i),len);
	}
	
	close(fd);

	return 0;
}
