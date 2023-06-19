
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<math.h>

typedef struct dm
{
	int ds;
	int bs;
}dm;

void create_disk(int disk_size, int block_size)
{
	int fd = 0, val = 0, i = 0, no_fb = 0, no_b = 0, no_fblock = 0;
	char ch = '\0';
	
	disk_size = disk_size * 1024 * 1024;
	
	fd = open("disk",O_CREAT|O_WRONLY,00777);
	lseek(fd,disk_size,SEEK_SET);	
	write(fd,&ch,1);
	
	lseek(fd,0,SEEK_SET);
	
	//Write disk metadata to disk.
	dm *DM = (dm*)malloc(sizeof(dm));
	DM -> ds = disk_size;
	DM -> bs = block_size;
	
	unsigned char *buf= (unsigned char*)malloc(sizeof(dm));
		
	while(i < sizeof(dm))
	{
		buf[i] = ((char*)dm)[i];
		i++;
	}
	
	val = write(fd,buf,sizeof(dm));

	//Write flagbits to disk.

	no_b = ceil((disk_size * 1024) / block_size);
	no_fb = ceil(no_b/8);
	
	if(no_fb > 1024)
	{
		no_fblocks = ceil(no_fb/1024);
	}	
	else
	{
		no_fblock = 1;
	}

	i = 0;
	buf = (unsigned char*)malloc(sizeof(unsigned char) * no_fb);
	while(i < no_fb)
	{
		buf[i] = 0xff;
		i++;
	}
	
	val = write(fd,buf,no_fb);
		
	return;
}

int main()
{
	int disk_size = 0, block_size = 0;

	printf("Enter disk size in GB = ");
	scanf("%d",&disk_size);

	printf("Enter block size in kb = ");
	scanf("%d",&block_size);
	
	create_disk(disk_size,block_size);
	
	return 0;
}
