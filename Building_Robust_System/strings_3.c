#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

int main()
{
	int i = 0, len = 0, ivalue = 0 ;
	int fd = open("arr_to_file.txt",O_CREAT | O_WRONLY,00700);
	
	char *str[4] = {"First string", "Second String", "Third String", "Forth String"};
	
	len = 4;

	write(fd, &len, sizeof(len));

	for(i = 0; i < 4; i++)
	{
		len = strlen(*(str+i));
		write(fd,&len,sizeof(int));
		write(fd,*(str+i),len);
	}
	/*
	close(fd);

	fd = open("arr_to_file.txt",O_RDONLY);
	unsigned char *str = malloc(15);
	n = read(fd,str,sizeof(int));
	int ch = *(int *)str;
	printf("%d\n", ch);
	*/

	close(fd);

	return 0;
}
